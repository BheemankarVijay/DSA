// LeetCode Problem 58: Length of Last Word
/*
Logic: Traverse the string from the end, skip trailing spaces, then count the length of the last word until a space is encountered.
*/
#include <iostream>
#include <string>
using namespace std;
int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int i = s.size()-1,count=0;
        while(i>=0 && s[i] == ' '){
            i--;
        }
        while(i>=0 && s[i]!= ' '){
            count++;
            i--;
        }
        return count;
}
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    int result = lengthOfLastWord(s);
    cout << "Length of the last word: " << result << endl;
    return 0;
}
// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(1)
/*
            OUTPUT:
Enter a string: Hello World
Length of the last world: 5
*/  