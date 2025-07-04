#include <iostream>
using namespace std;

// Fast exponentiation: calculates base^exp in O(log exp)
int intPow(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;  // if divided by 2 
        base *= base;                 // if  divided by 3 
        exp >>= 1;                    // shift exp right (divide by 2)
    }
    return result;
}

int main() {
    int base, exp;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exp;

    if (exp < 0) {
        cout << "This implementation only supports non-negative exponents." << endl;
        return 0;
    }

    int result = intPow(base, exp);

    cout << base << "^" << exp << " = " << result << endl;

    return 0;
}
/*
                     OUTPUT:
                  Enter base: 2
                  Enter exponent: 10
                  2^10 = 1024
*/