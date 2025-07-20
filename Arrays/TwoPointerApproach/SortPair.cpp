/*
LeetCode Problem: 905. Sort Array By Parity
This problem requires sorting an array such that all even numbers come before all odd numbers.
It like zeroes and ones problem, we can use two pointers to solve this problem.
We can use a two-pointer approach where one pointer (i) tracks the position of the next
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j] % 2 == 0){
                swap(nums[i],nums[j]);
                i++;
            }
        } return nums;
    }
int main() {
    int n;  
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<int> result = sortArrayByParity(nums);
    cout << "Sorted array by parity: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
// Time Complexity: O(n)    
// Space Complexity: O(1) if we ignore the input array storage.
/*
                OUTPUT:
Enter number of elements: 6
Enter 6 elements: 3 1 2 4 5 6   
Sorted array by parity: 2 4 6 1 5 3 
*/
 