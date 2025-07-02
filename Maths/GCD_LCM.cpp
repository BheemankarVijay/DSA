#include <iostream>
using namespace std;

// Compute GCD using the Euclidean algorithm, always returns positive GCD
int computeGCD(int a, int b) {
    a = abs(a); // abs() ensures we work with positive integers
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Compute LCM safely with long long multiplication to avoid overflow
long long computeLCM(int a, int b) {
    int gcd = computeGCD(a, b);
    // If either number is 0, LCM is 0 by definition
    if (gcd == 0) return 0;
    // Use long long for intermediate product to avoid overflow
    return (static_cast<long long>(abs(a)) * abs(b)) / gcd;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // Special case: LCM(0,0) is undefined
    if (a == 0 && b == 0) {
        cout << "LCM of 0 and 0 is undefined." << endl;
        return 0;
    }

    long long lcm = computeLCM(a, b);
    cout << "LCM of " << a << " and " << b << " is " << lcm << endl;
    return 0;
}

/*         OUTPUT: 
    Enter two numbers: 2 3
    LCM of 2 and 3 is 6
*/