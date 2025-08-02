// LeetCode Problem: Majority Element
// This code finds the majority element in an array, which is the element that appears more than n/2 times
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int majorityElement(vector<int>& num) {
        unordered_map<int,int>arr;
        int n = num.size();
        for(int i=0;i<n;i++){
            arr[num[i]]++;
        }
        for(auto it : arr){
            if(it.second > n/2) return it.first;
        }return -1;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> num(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int result = majorityElement(num);
    if (result != -1) {
        cout << "Majority element is: " << result << endl;
    } else {
        cout << "No majority element found." << endl;
    }

    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(n) for the hash map storing counts.
/*
                    OUTPUT:
Enter size of array: 5
Enter 5 elements of the array: 3 2 3 2 3
Majority element is: 3
*/