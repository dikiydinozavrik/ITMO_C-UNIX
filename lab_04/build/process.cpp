#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

using namespace std;

int f1_counter (int x) {
    return pow(x,2)-pow(x,2)+pow(x,4)-pow(x,5)+x+x;
}

int f2_counter (int x) {
    return x+x;
}

int f3_counter (int f1,int f2) {
    return f1+f2-f1;
}

void counter (int x, int n) {
    int f1_result, f2_result, f3_result;
    int fd1[2], fd2[2];
    
    auto start = chrono::high_resolution_clock::now();
    
        auto start1 = chrono::high_resolution_clock::now();
        
            pid_t pid1 = fork();

            if (pid1 == 0) {
                for (int i=0;i<n;i++) {
                    close(fd1[0]);
                    close(fd2[0]);
                    close(fd2[1]);
                    f1_result = f1_counter (x);
                    write(fd1[1], &f1_result, sizeof(f1_result));
                    close(fd1[1]);
                }
                exit(EXIT_SUCCESS);
            
            } 
        
        auto end1=chrono::high_resolution_clock::now();
        auto duration1 = (chrono::duration_cast<std::chrono::microseconds>(end1-start1)).count()*pow(10,-6);
        
        auto start2 = chrono::high_resolution_clock::now();
        
            pid_t pid2 = fork();

            if (pid2 == 0) {
                for (int i=0;i<n;i++)  {
                    close(fd1[0]);
                    close(fd2[0]);
                    close(fd1[1]);
                    f2_result = f2_counter(x);
                    write(fd1[1], &f2_result, sizeof(f1_result));
                    close(fd2[1]);
                }
                exit(EXIT_SUCCESS);
        
            }
            
        auto end2=chrono::high_resolution_clock::now();
        auto duration2 = (chrono::duration_cast<std::chrono::microseconds>(end2-start2)).count()*pow(10,-6);
        
        auto start3 = chrono::high_resolution_clock::now();
        
            close(fd1[1]);
            close(fd2[1]);
        
            read(fd1[0], &f1_result, sizeof(f1_result));
            read(fd2[0], &f2_result, sizeof(f2_result)); 
            
        
            for(int i=0;i<n;i++) 
                f3_result = f3_counter(f1_result,f2_result);
            
            close(fd1[0]);
            close(fd2[0]);       
            
         
            int status;
            waitpid(pid1, &status, 0);
            waitpid(pid2, &status, 0);

            
        auto end3=chrono::high_resolution_clock::now();
        auto duration3 = (chrono::duration_cast<std::chrono::microseconds>(end3-start3)).count()*pow(10,-6);
        
    
    auto end=chrono::high_resolution_clock::now();
    auto duration = (chrono::duration_cast<std::chrono::microseconds>(end-start)).count()*pow(10,-6);
    
    cout << "--------------------------------" << endl;
    cout << "Duration of " << n <<" iterations of the 1 thread = "<< duration1 << " seconds" << endl;
    cout << "Duration of " << n <<" iterations of the 2 thread = "<< duration2 << " seconds" << endl;
    cout << "Duration of " << n <<" iterations of the 3 thread = "<< duration3 << " seconds" << endl;
    cout << "Total duration of " << n <<" iterations = "<< duration << " seconds" << endl;
    
    
}

int main() {
    const int x=10;
    counter (x,10000);
    counter (x,100000);
    

    return 0;
}