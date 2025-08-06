// LeetCode 121. Best Time to Buy and Sell Stock
// Given an array prices where prices[i] is the price of a given stock on the ith day,
// return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
#include <vector>
#include <iostream>
using namespace std;
int maxProfit(vector<int>& num) {
        int buy=num[0];
        int sell=0,profit=0;
        for(int i=1;i<num.size();i++){
            if(buy>num[i]){
                buy=num[i];
            }
            else if(buy<num[i]){
                sell=num[i]-buy;
            } 
          
            profit=max(sell,profit);
        }
        return profit;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int result = maxProfit(prices);
    cout << "Maximum profit is: " << result << endl;

    return 0;
}
//time complexity is O(n) as we traverse the array once, and space complexity is O(1) since we use a constant amount of extra space.
/*
              OUTPUT:   
Enter size of array: 6
Enter 6 elements of the array: 7 1 5 3 6 4
Maximum profit is: 5
*/