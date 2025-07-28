#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
// LeetCode Problem: 904. Fruit Into Baskets
// This problem can be solved using a sliding window approach to find the maximum number of fruits in two baskets.
int totalFruit(vector<int>& fruits) {
        unordered_map<int ,int>basket;
        int left=0,maxlen=0;
        for(int right=0;right<fruits.size();right++){
            basket[fruits[right]]++; // increament value
            while(basket.size() > 2){ // if size three remove first fruit
                basket[fruits[left]]--; // until first value get zero decreament
                if(basket[fruits[left]] == 0){
                    basket.erase(fruits[left]); // remove or erase so it be 2 fruits
                }
                left++;
            }
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> fruits(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    int result = totalFruit(fruits);
    cout << "Maximum number of fruits in two baskets: " << result << endl;

    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) for the basket since it can only hold two types of fruits.
/*
                    OUTPUT: 
Enter size of array: 7
Enter 7 elements of the array: 1 2 1 2 3 2 1
Maximum number of fruits in two baskets: 4
*/