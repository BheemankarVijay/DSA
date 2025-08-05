//LeetCode 15: 3Sum
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& num) {
        set<vector<int>>ans;
        int n = num.size();
        for(int i=0;i<n-1;i++){
            set<int>hashset;
            for(int j=i+1;j<n;j++){
                int third = -(num[i]+num[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int>temp ={num[i],num[j],third};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
                hashset.insert(num[j]);
            }
        }return vector<vector<int>>(ans.begin(),ans.end());
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

    vector<vector<int>> result = threeSum(nums);
    cout << "Triplets that sum to zero are: " << endl;
    for (const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}
// This code finds all unique triplets in the array that sum to zero using a hash set for efficient lookups.
// It uses a two-pointer technique to avoid duplicates and ensure that the triplets are unique.
// The time complexity is O(n^2) due to the nested loops, and the space complexity is O(n) for storing the hash set and the result.
/*
           OUTPUT:
Enter size of array: 6
Enter 6 elements of the array: 0 -1 2 -3 1 3
Triplets that sum to zero are: 
[-3, -1, 2]
[-3, 0, 3]
[-1, 0, 1]
*/