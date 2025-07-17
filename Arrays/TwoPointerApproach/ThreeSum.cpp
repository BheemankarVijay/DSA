/*
LeetCode Problem: 15. 3Sum
This code finds all unique triplets in an array that sum to zero.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1, k = nums.size() - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                ans.push_back({nums[i], nums[j], nums[k]});
                while (j < k && nums[j] == nums[j + 1]) j++;
                while (j < k && nums[k] == nums[k - 1]) k--;
                j++; k--;
            }
            else if (sum < 0) j++;
            else k--;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> result = threeSum(nums);

    cout << "Unique triplets that sum to 0:\n";
    for (auto triplet : result) {
        for (int val : triplet) cout << val << " ";
        cout << endl;
    }

    return 0;
}
/*
              OUTPUT:
Enter number of elements: 6     
Enter 6 integers: -1 0 1 2 -1 -4
Unique triplets that sum to 0:
-1 -1 2
-1 0 1
*/
