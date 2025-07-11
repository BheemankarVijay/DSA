// LeetCode Problem: 34. Find First and Last Position of Element in Sorted Array


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the first occurrence of target
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1; // keep searching left
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return first;
    }

    // Function to find the last occurrence of target
    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, last = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1; // keep searching right
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return last;
    }

    // Returns a vector with the first and last occurrence
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};

// Main function for user input
int main() {
    Solution sol;
    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target element: ";
    cin >> target;

    vector<int> result = sol.searchRange(nums, target);

    if (result[0] == -1) {
        cout << "Target not found.\n";
    } else {
        cout << "First position: " << result[0] << ", Last position: " << result[1] << endl;
    }

    return 0;
}
//Time Complexity: O(log n)
/*
OUTPUT:
Enter size of array: 5
Enter sorted elements:
1 2 2 2 3  
Enter target element: 2
First position: 1, Last position: 3
*/


//Time complexity for two pointer approach is O(n) but for binary search it is O(log n).