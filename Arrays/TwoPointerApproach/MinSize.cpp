 /*
LeetCode Problem(#209): Minimum Size Subarray Sum
It's Sliding Window Problem and Two Pointer Approach to solve the problem efficiently.
So we need check sub array with sum >= target and return the minimum size of such subarray.
we take two pointers, one for the start of the subarray (low) and one for the end (high).
High pointer it will iterate through the array, adding elements to the current sum.
When the current sum is greater than or equal to the target, we check if the size of the current subarray is smaller than the minimum size found so far.
If it is, we update the minimum size. Then we move the low pointer to the right, subtracting the element at the low pointer from the current sum.
 */
 
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums){
        int low=0,curSum=0;
        int minSize= INT_MAX;
        for(int high=0;high<nums.size();high++){
            curSum+=nums[high];
            while(curSum>=target){
                int index=(high-low)+1;
                minSize=min(minSize,index);
                curSum-=nums[low];
                low++;
            }
        }return (minSize == INT_MAX) ? 0 : minSize;
    }

int main(){
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter target sum: ";
    cin >> target;

    int result = minSubArrayLen(target, nums);

    if (result == 0) {
        cout << "No subarray found with the given sum." << endl;
    } else {
        cout << "Minimum size of subarray with sum >= " << target << ": " << result << endl;
    }

    return 0;
}

/*
              OUTPUT:  
Enter number of elements: 6
Enter 6 elements: 1 2 6 4 4 3
Enter target sum: 7
Minimum size of subarray with sum >= 7: 2
*/ 