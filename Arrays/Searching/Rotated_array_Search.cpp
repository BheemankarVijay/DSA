/*
LeetCode#33 :- Search in Rotated Sorted Array
| Step | Action                              |
|  |
| 1    | Identify which half is sorted       |
| 2    | Check if target lies in that half   |
| 3    | If yes → narrow search to that half |
| 4    | Else → search in the other half     |

*/

#include <iostream>
#include <vector>
using namespace std;

// Function to search for the target in a rotated sorted array
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

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

    return -1;
}

int main() {
    int n, target;
    cout << "Enter number of elements in rotated sorted array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter target to search: ";
    cin >> target;

    int index = search(nums, target);

    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found in the array." << endl;

    return 0;
}
/*
                OUTPUT: 
Enter number of elements in rotated sorted array: 7
Enter 7 elements: 4 5 6 7 0 1 2     
Enter target to search: 0
Target found at index: 4
*/