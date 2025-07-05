#include <iostream>
#include <cmath>
using namespace std;

bool isPerfect(int n) {
    if (n <= 1) return false; // 1 is not a perfect number

    int sum = 1; // 1 is always a proper divisor
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i == n / i) {
                sum += i;       // perfect square factor
            } else {
                sum += i + n / i; // both factors 
            }
        }
    }

    return sum == n;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPerfect(n)) {
        cout << n << " is a perfect number." << endl;
    } else {
        cout << n << " is not a perfect number." << endl;
    }

    return 0;
}

/*
            output: 
      Enter a number: 28
     28 is a perfect number.
*/