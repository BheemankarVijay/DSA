//LeetCode Problem: 849. Maximize Distance to Closest Person
// This problem can be solved using a two-pointer approach to find the maximum distance to the closest person in a binary array where 1 represents a person and 0 represents an empty seat.
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maxDistToClosest(vector<int>& num) {
        int n = num.size();
        int last=-1;
        int maxDis =0;
        for(int i=0;i<n;i++){
            if(num[i] == 1){
                if(last == -1){
                    maxDis = i;
                }else{
                    maxDis = max(maxDis,(i - last)/2);
                }
                last =i;
            }
        }
        // if last end have more zeroes
        maxDis = max(maxDis,n-1-last);
        return maxDis;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> num(n);
    cout << "Enter " << n << " elements of the array (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int result = maxDistToClosest(num);
    cout << "Maximum distance to closest person: " << result << endl;

    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) if we ignore the input array storage.
/*
                  OUTPUT:
Enter size of array: 8
Enter 8 elements of the array (0s and 1s): 1 0 0 0 1 0 0 1
Maximum distance to closest person: 2
*/