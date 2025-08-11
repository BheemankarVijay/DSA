// LeetCode Problem: Single Number II
// This program finds the element that appears only once in an array where every other element appears exactly twice.
// The solution uses a hash map to count the frequency of each element and then finds the element with a frequency of one.
// Time complexity is O(n) since we traverse the array once. Space complexity is O(n) due to the hash map used for counting frequencies.
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        
        for (int num : nums) {
            freq[num]++;
        }
        
        for (auto &it : freq) {
            if (it.second == 1) {
                return it.first;
            }
        }
        return -1; 
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

    int result = singleNonDuplicate(nums);
    cout << "The element that appears only once is: " << result << endl;

    return 0;
}
/*
         OUTPUT:
Enter  size of array: 6
Enter 6 elements of the array: 2 2 3 4 4 3
The element that appears only once is: 2    
*/