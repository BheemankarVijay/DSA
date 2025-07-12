// LeetCode Problem #69: Sqrt(x)

#include <iostream>
using namespace std;

int mySqrt(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n < 0) return -1;  // square root of negative is not defined in real numbers

    int low = 1, high = n, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid == n)
            return (int)mid;
        if (mid * mid < n) {
            ans = (int)mid;
            low = (int)mid + 1;
        } else {
            high = (int)mid - 1;
        }
    }
    return ans;
}

int main() {
    int num;
    cout << "Enter a number to find its integer square root: ";
    cin >> num;

    int result = mySqrt(num);
    if (result == -1)
        cout << "Square root of a negative number is not defined in real numbers." << endl;
    else
        cout << "The integer square root of " << num << " is: " << result << endl;

    return 0;
}
/*
             OUTPUT:
Enter a number to find its integer square root: 8
The integer square root of 8 is: 2
Enter a number to find its integer square root: 16  
The integer square root of 16 is: 4
*/
