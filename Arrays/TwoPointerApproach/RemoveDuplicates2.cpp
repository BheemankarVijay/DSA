// LeetCode Problem(#80): Remove Duplicates from Sorted Array II
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& num) {
    if (num.size() <= 2) return num.size();
    int i = 1, count = 0;

    for (int j = 1; j < num.size(); j++) {
        if (num[j] == num[j - 1]) {
            if (count < 1) {
                num[i++] = num[j];
                count++;
            }
        } else {
            num[i++] = num[j];
            count = 0;
        }
    }
    return i;
}

int main() {
    int n;
    cout << "Enter number of elements: ";   
    cin >> n;
    vector<int> nums(n);
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int len = removeDuplicates(nums);

    cout << "Length: " << len << "\nModified Array: ";
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
            OUTPUT:
Enter number of elements: 7
Enter sorted array elements: 1 1 1 2 2 2 3
Length: 5
Modified Array: 1 1 2 2 3 
*/