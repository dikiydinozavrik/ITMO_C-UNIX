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

int main() {
    int a;
    int b;
    char o;
    cin >> a >> b >> o;
    int result;
    result = calc (a,b,o);
    cout << result << endl;
    return 0; 
}
