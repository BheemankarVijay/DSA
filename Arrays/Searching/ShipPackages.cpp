// LeetCode Problem : 1011. Capacity To Ship Packages Within D Days
// This code finds the minimum capacity of a ship that can ship all packages within a given number of days.
#include <vector>
#include <iostream> 
#include <algorithm>
using namespace std;
bool IsPossible(vector<int>&weights,int days,int capacity){
        int n = weights.size();
        int day=1,sum=0;
        for(int i=0;i<n;i++){
            if(sum + weights[i] <= capacity){
                sum += weights[i]; // current day loading
            }else{
                day++; // new day
                sum = weights[i]; // sum should be currnt load
                
            }
        }
        return day <= days; // check is less then or  equal 
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
        }
        int high = sum;
        while(low<high){
            int mid = low+(high-low)/2;
            if(IsPossible(weights,days,mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
}
int main() {
    int n, days;
    cout << "Enter number of packages: ";
    cin >> n;
    vector<int> weights(n);
    cout << "Enter the weights of the packages: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    cout << "Enter the number of days: ";
    cin >> days;

    int result = shipWithinDays(weights, days);
    cout << "The minimum capacity of the ship is: " << result << endl;

    return 0;
}
// Time Complexity: O(n log(sum(weights)))
// Space Complexity: O(1) since we are using a constant amount of extra space.
// This code finds the minimum capacity of a ship that can ship all packages within a given number of days.
/*
            Output:
Enter number of packages: 5
Enter the weights of the packages: 1 2 3 4 5
Enter the number of days: 3 
The minimum capacity of the ship is: 6
*/