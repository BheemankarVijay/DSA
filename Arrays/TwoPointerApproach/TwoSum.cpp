/*
Leetcode Problem(#15): Two Sum
step1: take two pointers low and high
step2: low starts at the beginning and high at the end of the array
step3: calculate the sum of elements at low and high
step4: if the sum equals the target, return the indices
step5: if the sum is greater than the target, move high pointer left
step6: if the sum is less than the target, move low pointer right
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoPointerSum(vector<int>& nums, int target) {
    vector<int> ans;
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int sum = nums[low] + nums[high];
        if (sum == target) {
            return {low, high}; // return indices of the two numbers
            break; // only one pair needed
        } else if (sum > target) {
            high--;
        } else {
            low++;
        }
    }

    return {-1,-1}; // return -1, -1 if no pair found
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter target sum: ";
    cin >> target;
    vector<int> nums(n);
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = twoPointerSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No pair found!" << endl;
    }

    return 0;
}
/*
                OUTPUT:
Enter number of elements: 5
Enter target sum: 9
Enter sorted array elements: 2 7 8 14 34
Indices: 0 and 1
*/