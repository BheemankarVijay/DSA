// LeetCode Problem: 303. Range Sum Query - Immutable
#include <iostream>
#include <vector>
using namespace std;
class NumArray {
public:
    vector<int> prefix;

    // Constructor
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n);

        // Calculate prefix sum
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    // Return sum from index 'left' to 'right'
    int sumRange(int left, int right) {
        return (left > 0) ? prefix[right] - prefix[left - 1] : prefix[right];
    }
};
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    NumArray* obj = new NumArray(nums);
    int left, right;
    cout << "Enter left and right indices for sum range query: ";
    cin >> left >> right;

    int result = obj->sumRange(left, right);
    cout << "Sum from index " << left << " to " << right << ": " << result << endl;

    delete obj; // Clean up memory
    return 0;
}
// Time Complexity: O(n) for the constructor, O(1) for sumRange.
// Space Complexity: O(n) for the prefix sum array.
/*
                    OUTPUT:
Enter size of array: 6
Enter 6 elements of the array: -2 0 3 -5 2 -1     
Enter left and right indices for sum range query: 0 2
Sum from index 0 to 2: 1
*/


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */