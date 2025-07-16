/*
Leetcode Problem(#26): Remove Duplicates from Sorted Array
step1: take two pointers i and j    
*/


#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int i = 1;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[j - 1]) {
            nums[i] = nums[j];
            i++;
        }
    }

    return i; // i is the count of unique elements
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array is empty." << endl;
        return 0;
    }

    vector<int> nums(n); // only after valid input
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums);

    cout << "Unique values: ";
    for (int idx = 0; idx < k; idx++) {
        cout << nums[idx] << " ";
    }
    cout << endl;

    return 0;
}
/*
             OUTPUT: 
Enter number of elements: 5
Enter sorted array elements: 1 1 2 2 3
Unique values: 1 2 3 

*/