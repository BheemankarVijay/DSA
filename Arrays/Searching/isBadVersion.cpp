#include <iostream>
using namespace std;

// Simulated API to mark which version is bad
int first_bad_version;  // This will be set from user input

// Simulated isBadVersion API
bool isBadVersion(int version) {
    return version >= first_bad_version;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                high = mid - 1;  // look left
            } else {
                low = mid + 1;   // look right
            }
        }
        return low;  // low points to the first bad version
    }
};

int main() {
    int n;
    cout << "Enter total number of versions (n): ";
    cin >> n;

    cout << "Enter the first bad version (between 1 and " << n << "): ";
    cin >> first_bad_version;

    Solution sol;
    int result = sol.firstBadVersion(n);

    cout << "First bad version is: " << result << endl;

    return 0;
}
/*
         OUTPUT:
Enter total number of versions (n): 10
Enter the first bad version (between 1 and 10): 4   
First bad version is: 4


*/