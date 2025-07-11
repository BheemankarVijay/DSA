// LeetCode Problem: 374. Guess Number Higher or Lower 
// similar problem :First Bad Version	LeetCode 278



#include <iostream>
using namespace std;

// Simulate the hidden number to guess (this replaces the API)
int hidden_number;  // This will be set in main()

// Simulated guess API
int guess(int num) {
    if (num == hidden_number) return 0;
    else if (num < hidden_number) return 1;
    else return -1;
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);

            if (res == 0) return mid;          // Correct
            else if (res < 0) high = mid - 1;  // Too high
            else low = mid + 1;                // Too low
        }
        return -1; // Not found (should not happen)
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter upper limit (n): ";
    cin >> n;

    cout << "Enter the hidden number (1 to " << n << "): ";
    cin >> hidden_number;

    int result = sol.guessNumber(n);

    cout << "The guessed number is: " << result << endl;

    return 0;
}
/*
          OUTPUT:
Enter upper limit (n): 10
Enter the hidden number (1 to 10): 5
The guessed number is: 5
*/