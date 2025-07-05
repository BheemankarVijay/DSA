#include <iostream>
using namespace std;

// Euclidean algorithm to compute GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Naive way: count numbers 1..n that are coprime with n by checking gcd
int naivePhi(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (gcd(i, n) == 1) count++;
    }
    return count;    // Time complexity: O(n log n) due to gcd calls
}

// Optimized Euler's Totient function: uses prime factorization formula
int eulerPhi(int n) {
    int result = n;  // start with φ(n) = n
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            // p is a prime factor of n, so multiply by (1-1/p)
            while (n % p == 0) n /= p;   // remove all multiples of p from n
            result -= result / p;        // φ(n) *= (1-1/p) effectively
        }
    }
    // If n still has a prime factor > sqrt(original n), include it
    if (n > 1) result -= result / n;
    return result;                    // Time complexity: O(sqrt(n))
}

int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer greater than 0." << endl;
        return 1;
    }

    int naiveResult = naivePhi(n);
    int optimizedResult = eulerPhi(n);

    cout << "Using naive method: φ(" << n << ") = " << naiveResult << endl;
    cout << "Using Euler's formula: φ(" << n << ") = " << optimizedResult << endl;

    return 0;
}
/*
                      OUTPUT:
                   Enter a positive integer n: 12
                   Using naive method: φ(10) = 4
                   Using Euler's formula: φ(10) = 4

    Try p=2:

12 % 2 == 0 → yes → p=2 is a prime factor of 12.

Inside the loop:

While loop: remove all multiples of 2 from n:

n=12 → n/=2→6 → n/=2→3 → n%2≠0 → done → final n=3

Update result:

result -= result/2 → result=12-6=6

So after p=2: n=3, result=6 

Next p=3 (since p increments in the loop):

3*3=9 <= n=3 → loop continues.

n=3 % 3==0 → yes → p=3 is a prime factor of the original n.

Inside loop:

While loop: remove all multiples of 3 from n:

n=3 → n/=3→1 → n%3≠0 → done → final n=1

Update result:

result -= result/3 → result=6-2=4

After p=3: n=1, result=4 

Next p=4 → 4*4=16 > n=1 → loop stops. then we check if n > 1: result remains 4.

*/
