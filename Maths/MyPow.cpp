#include <iostream>
using namespace std;

// Your power function
double myPow(double x, int n) {
    long long N = n;
    if (N == 0) return 1.0;
    if (N < 0) {
        N = -N;
        x = 1.0 / x;
    }
    double result = 1.0;
    while (N > 0) {
        if (N % 2 != 0) {
            result *= x;
        }
        x *= x;
        N /= 2;
    }
    return result;
}

int main() {
    double x;
    int n;
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    double result = myPow(x, n);
    cout << x << "^" << n << " = " << result << endl;

    return 0;
}
/*
           OUTPUT:      
Enter base (x): 2
Enter exponent (n): 10     
2^10 = 1024
*/  