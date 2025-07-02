#include <iostream>
using namespace std;

//formula: An Armstrong number (also known as a narcissistic number) is a number that is equal to the sum of its own digits each raised to the power of the number of digits.


// Helper function: compute integer power digit^d without floating-point pow()
int intPow(int base, int exp) {
    int result = 1;
    while (exp--) result *= base;
    return result;
}

bool isArmstrong(int n) {
    if (n <= 0) return false;

    int sum = 0;
    int temp = n;

    // Count the number of digits in n
    int d = 0;
    int numDigits = n;
    while (numDigits > 0) {
        d++;
        numDigits /= 10;
    }

    temp = n; // reset temp
    while (temp > 0) {
        int digit = temp % 10;
        sum += intPow(digit, d); // use integer power to avoid floating-point
        temp /= 10;
    }
    return sum == n;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isArmstrong(num)) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }
    return 0;
}
/*  Output:
    Enter a number: 153
    153 is an Armstrong number.
*/