// This program finds the largest factor of a number n that is smaller than n itself.
// It starts checking from n-1 down to 1, and prints the first factor it


#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number n: ";
    cin >> n;

    if (n <= 1) {
        cout << "No positive factors smaller than " << n << endl;
        return 0;
    }

    // Start checking from n-1 down to 1
    for (int i = n - 1; i >= 1; i--) {
        if (n % i == 0) {
            cout << "Largest factor smaller than " << n << " is: " << i << endl;
            return 0;
        }
    }

    // Technically never reached since 1 is a factor of all positive n
    return 0;
}

// The time complexity is O(n) in the worst case, but it will usually find a

/* 
                              OUTPUT:
                        Enter a number n: 12
                Largest factor smaller than 12 is: 6
*/