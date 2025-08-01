//LeetCode 1 Two Sum
// This code finds two indices of numbers in an array that add up to a specific target value
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& num, int target) {
        unordered_map<int,int>sum;
        for(int i =0;i<num.size();i++){
            int first = num[i];
            int second = target - first;
            if(sum.find(second) != sum.end()){
                return {sum[second],i};
            }
            sum[first] = i;
        }return {-1,-1};
}
int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> num(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cout << "Enter target sum: ";
    cin >> target;

    vector<int> result = twoSum(num, target);
    if (result[0] != -1) {
        cout << "Indices of the two numbers that add up to the target: " 
             << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(n) for the hash map storing indices.
/*
                    OUTPUT:
Enter size of array: 5
Enter 5 elements of the array: 2 7 11 15 3
Enter target sum: 9 
Indices of the two numbers that add up to the target: 0 and 1
*/