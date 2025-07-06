#include <iostream>
#include <cmath>
using namespace std;

// Efficient binary modular exponentiation: (base^exp) % mod
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;  // Reduce base modulo mod first

    while (exp > 0) {
        if (exp & 1)  // If current bit in exp is 1
            result = (result * base) % mod;
        base = (base * base) % mod;  // Square the base
        exp >>= 1;                   // Move to next bit
    }
    return result;
}

int main() {
    long long base, exp, mod;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exp;
    cout << "Enter modulus: ";
    cin >> mod;

    // Calculate modular exponentiation
    long long modResult = modPow(base, exp, mod);

    // Note: rawResult is only valid for small exponents
    // because base^exp grows too big very quickly!
    long double rawResult = pow(base, exp);

    cout << base << "^" << exp << " without mod (approximate if big): " << rawResult << endl;
    cout << base << "^" << exp << " mod " << mod << " = " << modResult << endl;

    return 0;
}

/* 
                  OUTPUT:
        Enter base: 123456789
        Enter exponent:  987654321
        Enter modulus: 100
        123456789^987654321 without mod (approximate if big): inf
        123456789^987654321 mod 100 = 89

*/
