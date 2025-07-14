/*
LeetCode Problem 1051: Height Checker:-
A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

Example 1:
Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation: 
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.

*/
#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

int heightChecker(vector<int>& num) {
    int n = num.size(), count = 0;
    vector<int> arr = num;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (num[i] != arr[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter student heights: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int result = heightChecker(heights);
    cout << "Number of students not in correct position: " << result << endl;

    return 0;
}
/*
           OUTPUT:
Enter number of students: 6 
Enter student heights: 1 1 4 2 1 3
Number of students not in correct position: 3
*/