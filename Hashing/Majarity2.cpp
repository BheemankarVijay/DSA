// LeetCode 229. Majority Element II
// Given an integer array of size n, find all elements that appear more than n/3 times.
// The algorithm uses a hash map to count occurrences of each element and then filters those that appear more than n/3 times.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>result;
        int n = nums.size();
        for(int num =0;num<n;num++){
            result[nums[num]]++;
        }
        for(auto it : result){
            if(it.second > n/3) ans.push_back(it.first);
        }
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
// Space Complexity: O(n) for the hash map storing counts of elements.
/*
                    OUTPUT:
Enter size of array: 9
Enter 9 elements of the array: 3 2 3 2 2 1 1 1 2
Elements that appear more than n/3 times are: 2
*/