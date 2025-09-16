// Leetcode 409. Longest Palindrome
/*
Logic: Count frequency of each character. Add pairs to length. If any character has odd frequency, we can place one in the center.
*/
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(char ch : s) mp[ch]++;

        int length = 0;
        bool hasOdd = false;

        for(auto &p : mp){
            length += (p.second / 2) * 2;   // take all pairs and when odd add remove 1 to make it even
            if(p.second % 2 == 1) hasOdd = true; // if any char has odd frequency then result add 1 in the end
        }
        return hasOdd ? length + 1 : length;
}
int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int result = longestPalindrome(s);
    cout << "Length of Longest Palindrome that can be built: " << result << endl;
    return 0;
}
// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(1) since the character set is fixed (ASCII).
/*
            OUTPUT:
Enter a string: abccccdd
Length of Longest Palindrome that can be built: 7
*/