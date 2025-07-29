// LeetCode Problem: 724. Find Pivot Index
// This problem can be solved by calculating the prefix sum and checking for the pivot index.
// This code finds the pivot index in an array where the sum of the elements to the left is equal to the sum of the elements to the right.
#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) totalSum += num;

    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
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

    int result = pivotIndex(nums);
    if (result != -1) {
        cout << "Pivot index found at: " << result << endl;
    } else {
        cout << "No pivot index found." << endl;
    }

    return 0;
}

// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(n) for the prefix sum array.
/*
                    OUTPUT:
Enter size of array: 6
Enter 6 elements of the array: 1 7 3 6 5 6
Pivot index found at: 3
*/