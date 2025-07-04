#include <iostream>
using namespace std;

int main() {
    int n; 
    cout << "Enter the number of terms in the Fibonacci sequence: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Number of terms must be positive." << endl;
        return 0;
    }
    
    long long a = 0, b = 1; //  Use long long to avoid overflow for bigger n
    if (n >= 1) cout << a << " ";
    if (n >= 2) cout << b << " ";
    
    for (int i=2; i<n; i++) {
        long long c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
    return 0;
}
