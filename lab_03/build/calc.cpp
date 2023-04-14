# include <iostream>
using namespace std;

int calc (int a, int b, char o) {
    int result;
    
    if (o == '+') {
        result = a+b;

    } else if (o == '-') {
        result = a-b;

    } else if (o == '^') {
       result = a;

        for (int i=2; i<=b; i++) {
            result = a * result;
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
    int a= stoi(argv[1]);
    int b = stoi(argv[2]);
    char o = *argv[3];

    int result;
    result = calc (a,b,o);
    cout << result << endl;
    return 0; 
}
