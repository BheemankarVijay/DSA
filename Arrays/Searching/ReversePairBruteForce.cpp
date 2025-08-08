// Leetcode Problem(493): Reverse Pairs
// This is a brute force solution to count reverse pairs in an array.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int reversePairs(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if ((long long)nums[i] > 2LL * nums[j]) {
                count++;
            }
        }
    }
    return count;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = reversePairs(nums);
    cout << "Number of reverse pairs is: " << result << endl;

    return 0;
}
// Time complexity is O(n^2) as we use two nested loops to check each pair, and space complexity is O(1) since we use a constant amount of extra space.
/*
                OUTPUT:
Enter size of array: 5
Enter 5 elements of the array: 1 3 2 3 1
Number of reverse pairs is: 2
*/