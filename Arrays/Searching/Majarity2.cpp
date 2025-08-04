// LeetCode 229. Majority Element II
// Given an integer array of size n, find all elements that appear more than n/3 times.
// Moore efficient solution using Boyer-Moore Voting Algorithm
// The algorithm uses a two-pass approach to find candidates and then verify their counts.
#include <iostream>
#include <vector>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 0;

        // Step 1: Candidate selection
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verification
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        vector<int> ans;
        if (count1 > n / 3) ans.push_back(candidate1);
        if (count2 > n / 3) ans.push_back(candidate2);

        return ans;
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

    vector<int> result = majorityElement(nums);
    cout << "Elements that appear more than n/3 times are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) since we are using only a constant amount of space for candidates.
/*
                    OUTPUT:
Enter size of array: 9
Enter 9 elements of the array: 3 2 3 2 2 1 1 1 2
Elements that appear more than n/3 times are: 2
*/
// Note: This solution is more efficient than using a hash map, especially for large arrays.