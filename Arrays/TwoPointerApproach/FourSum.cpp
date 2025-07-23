//leetcode problem: #18. 4Sum and its solution using Two Pointer Approach
// it is based 3sum problem and its solution using Two Pointer Approach
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& num, int target) {
    vector<vector<int>> ans;
    sort(num.begin(), num.end());
    int n = num.size();

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && num[i] == num[i - 1]) continue; // skip duplicates

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && num[j] == num[j - 1]) continue; // skip duplicates

            int k = j + 1;
            int l = n - 1;

            while (k < l) {
                long long sum = (long long)num[i] + num[j] + num[k] + num[l];

                if (sum == target) {
                    ans.push_back({num[i], num[j], num[k], num[l]});
                    while (k < l && num[k] == num[k + 1]) k++;
                    while (k < l && num[l] == num[l - 1]) l--;
                    k++;
                    l--;
                }
                else if (sum < target) {
                    k++;
                }
                else {
                    l--;
                }
            }
        }
    }

    return ans;
}

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> num(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cout << "Enter target sum: ";
    cin >> target;

    vector<vector<int>> result = fourSum(num, target);

    cout << "Quadruplets that sum to " << target << ": \n";
    for (const auto& quad : result) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}

// Time Complexity: O(n^3) where n is the size of the input array.
// Space Complexity: O(1) if we ignore the output storage.
/*
              OUTPUT:
Enter size of array: 4
Enter 4 elements of the array: 2 2 2 2
Enter target sum: 8
Quadruplets that sum to 8: 
[2, 2, 2, 2]
*/  




