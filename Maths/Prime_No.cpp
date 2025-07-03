#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;  // avoid negative numbers and 0, 1
    if (n <= 3) return true;   // 2 and 3 are prime numbers
    if (n % 2 == 0 || n % 3 == 0) return false;  // eliminate multiples of 2 and 3

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;  // check for factors of the form 6k ± 1 it mean multiples of 7
    }
    return true;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }
    return 0;
}


/*
                  OUTPUT:
             Enter a number: 29
             29 is a prime number.

*/