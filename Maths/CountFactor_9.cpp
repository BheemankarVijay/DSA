/*
Using Sieve of Eratosthenes to count numbers with exactly 9 divisors
case 1: p^2 * q^2
case 2: p^8
*/


#include <iostream>
#include <cmath>
using namespace std;

int countNumbers(int n)
{
    int c = 0;
    int limit = sqrt(n);

    int prime[limit + 1];
    for (int i = 1; i <= limit; i++)
        prime[i] = i;

    // Sieve to store smallest prime factor
    for (int i = 2; i * i <= limit; i++) {
        if (prime[i] == i) {
            for (int j = i * i; j <= limit; j += i)
                if (prime[j] == j)
                    prime[j] = i;
        }
    }

    for (int i = 2; i <= limit; i++) {
        int p = prime[i];               // Smallest prime factor of i i f i =6  then p = 2
        int q = prime[i / prime[i]];   // Second smallest prime factor of i   (if q = 6/2= then q = 3)

        // Case 1: p^2 * q^2
        if (p * q == i && q != 1 && p != q) {     
            c += 1;
        }
        // Case 2: p^8
        else if (prime[i] == i && pow(i, 8) <= n) {
            c += 1;
        }
    }

    return c;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int result = countNumbers(n);
    cout << "Count of numbers with exactly 9 divisors: " << result << endl;

    return 0;
}
/*
                 OUTPUT:
Enter n: 57345
Count of numbers with exactly 9 divisors: 74
*/