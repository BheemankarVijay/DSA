/*
LeetCode Problem:153 Find Minimum in Rotated Sorted Array
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the minimum element in rotated sorted array
int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return nums[low]; // or nums[high], since low == high
}

int main() {
    int n;
    cout << "Enter number of elements in rotated sorted array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements in rotated sorted array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int minimum = findMin(nums);
    cout << "Minimum element in the rotated sorted array is: " << minimum << endl;

    return 0;
}
/*
OUTPUT:
Enter number of elements in rotated sorted array: 7
Enter 7 elements in rotated sorted array: 4 5 6 7 0 1 2
Minimum element in the rotated sorted array is: 0
*/