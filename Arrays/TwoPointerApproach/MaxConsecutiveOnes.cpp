//#1004 and I used slide window + two pointers approach previous min sub array sum:-
// leetcode problem: #1004. Max Consecutive Ones III and its solution using Two Pointer Approach
// This code finds the maximum length of a subarray with at most k flips (0s to 1s).
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int longestOnes(vector<int>& nums, int k) {
        int maxsize=0,left=0,flip=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right] == 0){
                flip++;
            }
            while(flip>k){
                if(nums[left] == 0){
                    flip--;
                }
                left++;
            }
            maxsize=max(maxsize,right-left+1);
        }return maxsize;
    }
int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " elements of the array (0s and 1s only): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter value of k (maximum number of flips allowed): ";
    cin >> k;
    
    int result = longestOnes(nums, k);
    cout << "Maximum length of subarray with at most " << k << " flips: " << result << endl;
    
    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) if we ignore the input array storage.
/*
                  OUTPUT:
Enter size of array: 6 
Enter 6 elements of the array (0s and 1s only): 1 1 0 0 0 1
Enter value of k (maximum number of flips allowed): 2
Maximum length of subarray with at most 2 flips: 4
*/
