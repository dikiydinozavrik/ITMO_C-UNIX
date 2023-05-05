#include <iostream>
#include <math.h>
#include <chrono>
#include <thread>

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


thread f1_thread(int x, int n, int& result) {
    return thread([&result, x, n]() {
        for (int i = 1; i <= n; i++) {
            result = f1_counter(x);
        }
    });
}

thread f2_thread(int x, int n, int& result) {
    return thread([&result, x, n]() {
        for (int i = 1; i <= n; i++) {
            result = f2_counter(x);
        }
    });
}

void f3_thread(int& f3_result, int f1_result, int f2_result, int n) {
    for (int i = 1; i <= n; i++) {
        f3_result = f3_counter(f1_result, f2_result);
    }
}


void counter (int x, int n) {
    int f1_result, f2_result, f3_result;
    
    auto start = chrono::high_resolution_clock::now();
    
        auto start1 = chrono::high_resolution_clock::now();
        
            thread t1 = f1_thread(x, n, f1_result);
        
        auto end1=chrono::high_resolution_clock::now();
        auto duration1 = (chrono::duration_cast<std::chrono::microseconds>(end1-start1)).count()*pow(10,-6);
        
        auto start2 = chrono::high_resolution_clock::now();
        
            thread t2 = f1_thread(x, n, f2_result);
            
        auto end2=chrono::high_resolution_clock::now();
        auto duration2 = (chrono::duration_cast<std::chrono::microseconds>(end2-start2)).count()*pow(10,-6);
        
        auto start3 = chrono::high_resolution_clock::now();
        
            thread t3(f3_thread, ref(f3_result), f1_result, f2_result, n);
            
        auto end3=chrono::high_resolution_clock::now();
        auto duration3 = (chrono::duration_cast<std::chrono::microseconds>(end3-start3)).count()*pow(10,-6);
        
        t1.join();
        t2.join();
        t3.join();
    
    auto end=chrono::high_resolution_clock::now();
    auto duration = (chrono::duration_cast<std::chrono::microseconds>(end-start)).count()*pow(10,-6);
    
    cout << "Duration of " << n <<" iterations of the 1 thread = "<< duration1 << " seconds" << endl;
    cout << "Duration of " << n <<" iterations of the 2 thread = "<< duration2 << " seconds" << endl;
    cout << "Duration of " << n <<" iterations of the 3 thread = "<< duration3 << " seconds" << endl;
    cout << "Total duration of " << n <<" iterations = "<< duration << " seconds" << endl;
    cout << "--------------------------------" << endl;
    
}

int main()
{   
    const int x = 10;
    
    counter (x,10000);
    
    counter (x,100000);

    return 0;
}
