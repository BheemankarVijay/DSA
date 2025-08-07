// LeetCode 152. Maximum Product Subarray
// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.// The subarray must contain at least one number and the product of the subarray can be zero.
// The problem can be solved using a dynamic programming approach, where we keep track of the maximum and minimum products at each position in the array, since a negative number can turn a small product into a large one when multiplied by another negative number.
// If the array is empty, return 0.
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxProd = nums[0];

    int leftProduct = 1;
    int rightProduct = 1;

    for (int i = 0; i < n; i++) {
        leftProduct = (leftProduct == 0 ? 1 : leftProduct) * nums[i];
        rightProduct = (rightProduct == 0 ? 1 : rightProduct) * nums[n - 1 - i];
        maxProd = max({maxProd, leftProduct, rightProduct});
    }

    return maxProd;
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

    int result = maxProduct(nums);
    cout << "Maximum product of subarray is: " << result << endl;

    return 0;
}
// Time complexity is O(n) as we traverse the array once, and space complexity is O(1) since we use a constant amount of extra space.
/*
                OUTPUT:
Enter size of array: 5
Enter 5 elements of the array: 2 3 -2 4 -1
Maximum product of subarray is: 48
*/
