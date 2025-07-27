// LeetCode Problem: 643. Maximum Average Subarray I
// This problem can be solved using a sliding window approach to find the maximum average of a subarray of size k.
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
double findMaxAverage(vector<int>& num, int k) {

        int n = num.size();
        int left=0,count=0,sum=0;
        double maxAvg = INT_MIN;
        for(int right=0;right<n;right++){
            sum += num[right];
            count++;
            while(count > k){
                sum -= num[left];
                left++;
                count--;
            }
            if(count == k) maxAvg = max(maxAvg ,double(sum)/k); 
        } return maxAvg;
        
        
}
int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> num(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cout << "Enter the size of the subarray (k): ";
    cin >> k;

    double result = findMaxAverage(num, k);
    cout << "Maximum average of subarray of size " << k << ": " << result << endl;

    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) if we ignore the input array storage.
/*
                  OUTPUT:
Enter size of array: 5
Enter 5 elements of the array: 1 12 -5 -6 50
Enter the size of the subarray (k): 4
Maximum average of subarray of size 4: 12.75
*/