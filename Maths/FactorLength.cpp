//Find all numbers in a range [1, n] that have exactly k factors

#include <iostream>
#include <cmath>
using namespace std;

// Function to count number of factors of a number n
int countFactors(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i == n / i)
                count += 1; // perfect square: count i once
            else
                count += 2; // count both i and n/i
        }
    }
    return count;
}

int main() {
    int n, k;
    cout << "Enter n (range upper limit): ";
    cin >> n;
    cout << "Enter k (number of factors): ";
    cin >> k;

    cout << "Numbers <= " << n << " with exactly " << k << " factors: ";
    bool found = false;

    for (int i = 1; i <= n; i++) {
        if (countFactors(i) == k) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) cout << "None found.";

    cout << endl;
    return 0;
}
// This program counts the number of factors for each number in the range [1, n]
// and prints those that have exactly k factors. The time complexity is O(n * sqrt(n

/*
                              OUTPYT:
                 Enter n (range upper limit): 18
                 Enter k (number of factors): 6
                 Numbers <= 18 with exactly 6 factors: 12 18 
*/