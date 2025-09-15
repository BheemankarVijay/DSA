// Leetcode Problem 520: Detect Capital
/*
Logic: Count the number of capital letters and check against the three valid cases.
*/
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
bool detectCapitalUse(string word) {
        int n = word.size();
        int capCount = 0;

        // count capital letters
        for(char c : word) {
            if(isupper(c)) capCount++;
        }

        // Case 1: All uppercase
        if(capCount == n) return true;

        // Case 2: All lowercase
        if(capCount == 0) return true;

        // Case 3: First letter capital, rest lowercase
        if(capCount == 1 && isupper(word[0])) return true;

        // Otherwise false
        return false;
}
int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;
    bool result = detectCapitalUse(word);
    cout << (result ? "True" : "False") << endl;
    return 0;
}
// Time Complexity: O(n) where n is the length of the word.
// Space Complexity: O(1)
/*
            OUTPUT:
Enter a word: india
True
*/  