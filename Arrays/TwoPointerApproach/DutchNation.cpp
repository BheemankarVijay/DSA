/*
leetcode 75: Sort Colors
Given an array with n objects colored o, 1, or 2, sort them in-place 
so that objects of the same color are adjacent, with the colors in the order of 0, 1, and 2.
This is a one-pass algorithm using the two-pointer technique.   

*/


#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low++], nums[mid++]);
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high--]);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements (only 0, 1, or 2): ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    sortColors(nums);

    cout << "Sorted output: ";
    for (int val : nums) cout << val << " ";
    cout << endl;

    return 0;
}
/*
           OUTPUT:
Enter number of elements: 5
Enter 5 elements (only 0, 1, or 2): 1 0 2 0 1
Sorted output: 0 0 1 1 2 
*/