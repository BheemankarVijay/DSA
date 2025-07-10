/*
35. problem on leet code:- Search Insert Position 

Problem:-Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

         You must write an algorithm with O(log n) runtime complexity.

*/

#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // If not found, low is the index where it should be inserted then get the index
    return low;
}

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target element: ";
    cin >> target;

    int index = searchInsert(nums, target);
    cout << "Target should be at index: " << index << endl;

    return 0;
}
/* 
         OUTPUT:
Enter size of array: 4
Enter 4 sorted elements: 1 3 5 9
Enter target element: 7
Target should be at index: 3
*/