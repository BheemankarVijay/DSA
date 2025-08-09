// LeetCode 81: Search in Rotated Sorted Array II
#include <vector>
#include <iostream>
using namespace std;    

bool search(vector<int>& nums, int target) {    
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return true;
        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++;
            high--;
            continue;
        }
        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return false;
}
int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " elements of the rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter target value to search: ";
    cin >> target;

    bool found = search(nums, target);
    if (found) {
        cout << "Target found in the array." << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
// Time complexity is O(n) in the worst case due to the linear search in case of duplicates, and O(log n) in the average case. Space complexity is O(1) since we use a constant amount of extra space.
/*
                OUTPUT:
Enter size of array: 5
Enter 5 elements of the rotated sorted array: 2 5 6 0 0
Enter target value to search: 0
Target found in the array.
*/