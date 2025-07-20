/*
LeetCode Problem: 1346. Check If N and Its Double Exist
This problem requires checking if there exists an element in the array such that its double also exists in the array.
We can solve this problem using a two-pointer approach after sorting the array use binary search to find the double of each element.
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=0;i<n;i++){
            int low=0,high=n-1;
            int target=2 * arr[i];
            while(low<=high){
                int mid =low + (high - low)/2;
                if ( mid != i && target == arr[mid]){
                    return true;
                }else if(arr[mid]> target){
                    high=mid - 1;
                }else{
                    low=mid + 1;
                }
            }
        }return false;
    }

int main() {
    int n;  
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    bool result = checkIfExist(arr);
    if (result) {
        cout << "There exists an element in the array such that its double also exists." << endl;
    } else {
        cout << "No such element found in the array." << endl;
    }
    return 0;
}
// Time Complexity: O(n log n) for sorting and O(n log n) for binary search, overall O(n log n)
// Space Complexity: O(1) if we ignore the input array storage.
/*
                OUTPUT:
Enter number of elements: 5
Enter 5 elements: 10 2 5 3 6
There exists an element in the array such that its double also exists.
*/