// leetcode 217. Contains Duplicate
// This code checks if there are any duplicate elements in an array and returns true if found,  false otherwise.
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool containsDuplicate(vector<int>& num) {
        unordered_map<int,int>freq;
        for(int i:num){
            freq[i]++;
        }
        for(int i=0;i<num.size();i++){
            if(freq[num[i]] > 1) return true;
        }return false;
        
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

    bool result = containsDuplicate(num);
    if (result) {
        cout << "Array contains duplicates." << endl;
    } else {
        cout << "Array does not contain duplicates." << endl;
    }

    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(n) for the hash map storing frequencies.
/*
                    OUTPUT:
Enter size of array: 5
Enter 5 elements of the array: 1 2 3 4 5
Array does not contain duplicates.
*/