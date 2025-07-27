#include<iostream>
#include<vector>
using namespace std;
// LeetCode Problem: 2090. K Radius Subarray Averages
// This problem can be solved using a sliding window approach to calculate the averages of subarrays of
 vector<int> getAverages(vector<int>& num, int k) { 
        int n= num.size();
        vector<int>ans(n,-1);
        int windowsize = 2*k+1;
        if(windowsize > n) return ans;
        if(k == 0) return num;
        long long sum =0;
        for(int i=0; i<windowsize;i++){
            sum +=num[i];
        }
        ans[k]=sum/windowsize;
        for(int i=windowsize;i<n;i++){
            sum += num[i]-num[i-windowsize];
            ans[i-k] = sum/windowsize;
        }return ans;
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
    cout << "Enter the value of k: ";
    cin >> k;

    vector<int> result = getAverages(num, k);
    cout << "K Radius Subarray Averages: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(n) for the output array.
/*
                  OUTPUT:
Enter size of array: 5
Enter 5 elements of the array: 7 4 3 9 1
Enter the value of k: 1
K Radius Subarray Averages: -1 4 5 4 -1 
*/