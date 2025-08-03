// leetcode #128:ongest Consecutive Array
// This code finds the length of the longest consecutive elements sequence in an unsorted array
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int longestConsecutive(vector<int>& num) {
        if(num.size() == 0) return 0;
        unordered_set<int>s(num.begin(),num.end());
        int longest=0;
        for(int n : s){
            if(!s.count(n-1)){ // of element -1 not foun assiagn streak is 1
                int streak = 1;
                while(s.count(n+1)){ // for is next +1 we are counting if exit or exit from while loop
                    n++;
                    streak++;
                }
                longest = max(longest,streak);
            }
        }return longest;
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

    int result = longestConsecutive(num);
    cout << "Length of the longest consecutive sequence is: " << result << endl;

    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(n) for the hash set storing unique elements.
/*
                    OUTPUT:
Enter size of array: 7
Enter 7 elements of the array: 100 4 200 1 3 2 5 6
Length of the longest consecutive sequence is: 5
*/