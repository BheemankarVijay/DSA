//LeetCode 560. Subarray Sum Equals K
// This problem can be solved using a prefix sum approach with a hash map to count occurrences of prefix sums.
// The idea is to maintain a running sum and check how many times the difference between the current prefix sum and k has occurred before.
// This allows us to find the number of subarrays that sum to k in O(n)
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> prefixCount;
      prefixCount[0] = 1;  // very important!
      int prefixSum = 0, count = 0;

      for (int num : nums) {
          prefixSum += num;
        
        // Check if there's a previous prefix that satisfies: prefixSum - previousPrefix = k
          if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
            count += prefixCount[prefixSum - k];
          }

          prefixCount[prefixSum]++;
      }return count;
        
        
}
int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;

    int result = subarraySum(nums, k);
    cout << "Number of subarrays that sum to " << k << ": " << result << endl;

    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(n) for the hash map storing prefix sums.
/*
                    OUTPUT:
Enter size of array: 3
Enter 5 elements of the array: 1 1 1 
Enter the value of k: 2
Number of subarrays that sum to 2: 2
*/