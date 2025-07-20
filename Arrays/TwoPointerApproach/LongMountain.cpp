/*
Leetcode Problem: 845. Longest Mountain in Array
This problem requires finding the longest mountain in an array.

Step 1: find a peak condition arr[i-1]<arr[i] && arr[i]>arr[i+1]
then check left and right side of peak
*/

#include <vector>
#include <iostream> 
using namespace std;
int longestMountain(vector<int>& arr) {
        int maxsize=0;
        int n=arr.size();
        for(int i=1;i<n-1;i++){
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
                int left=i-1;
                int right=i+1;
                while(left>0 && arr[left]>arr[left-1]){
                    left--;
                }
                while(right<n-1 && arr[right]>arr[right+1]){
                    right++;
                }
                int height=(right-left)+1;
                maxsize=max(maxsize,height);
                i=right ;// after peak we need move or start next right
                
            }
            
        }return maxsize;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result = longestMountain(arr);
    
    if (result == 0) {
        cout << "No mountain found in the array." << endl;
    } else {
        cout << "Length of the longest mountain: " << result << endl;
    }

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
/*
                OUTPUT:
Enter number of elements: 5
Enter 5 elements: 1 2 3 2 4
Length of the longest mountain: 4
*/