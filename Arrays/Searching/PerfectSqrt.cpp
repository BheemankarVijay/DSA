// From lertcode Problem #367: Perfect Squares

#include <iostream>
using namespace std;

bool isPerfectSquare(int n) {
    if (n < 1) return false;

    int low = 1, high = n;
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid == n)
            return true;
        else if (mid * mid < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    int num;
    cout << "Enter a number to check if it's a perfect square: ";
    cin >> num;

    if (isPerfectSquare(num))
        cout << num << " is a perfect square." << endl;
    else
        cout << num << " is not a perfect square." << endl;

    return 0;
}
/*
             OUTPUT:
Enter a number to check if it's a perfect square: 36
36 is a perfect square.
Enter a number to check if it's a perfect square: 20
20 is not a perfect square.
*/