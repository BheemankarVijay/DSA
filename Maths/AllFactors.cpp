#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> listFactors(int n) {
    vector<int> factors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factors.push_back(i);   // count i as a factor count variaable is +1
            if (i != n / i) factors.push_back(n / i); // then count variable is +2
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<int> factors = listFactors(n);
    cout << "Factors of " << n << " are: ";
    for (int f : factors) cout << f << " ";
    cout << endl;
    return 0;
}
// Time complexity: O(sqrt(n) log(sqrt(n))) due to sorting

/*
  OUTPUT:  Enter a number: 12
  Factors of 12 are: 1 2 3 4 6 12
*/