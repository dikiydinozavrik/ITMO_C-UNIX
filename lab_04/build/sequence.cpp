#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;

int f1_counter (int x) {
    return pow(x,2)-pow(x,2)+pow(x,4)-pow(x,5)+x+x;
}

int f2_counter (int x) {
    return x+x;
}

int f3_counter (int f1, int f2) {
    return f1+f2-f1;
}


float time_counter (int x, int n) {
    
    auto start = chrono::high_resolution_clock::now();
    for (int i=1; i<=n; i++) {
        int f1=f1_counter (x);
        int f2=f2_counter (x);
        f3_counter (f1,f2);
    } 
    
    auto end=chrono::high_resolution_clock::now();
    auto duration = (chrono::duration_cast<std::chrono::microseconds>(end-start)).count()*pow(10,-6);
    
    return duration;
}

int main()
{   
    const int x = 10;
    
    auto duration1=time_counter(10,10000);
    cout << "duration of 10000 iterations = "<< duration1 << " seconds" << endl;
    
    auto duration2=time_counter(10,100000);
    cout << "duration of 100000 iterations = "<< duration2 << " seconds" << endl;

    return 0;
}
