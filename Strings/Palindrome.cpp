// Letcode Problem: 125. Valid Palindrome
#include <iostream>
#include <string>
#include <cctype> // for isalnum and tolower
using namespace std;
bool isPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        
        while (low < high) {
            // skip non-alphanumeric chars
            if (!isalnum(s[low])) {
                low++;
                continue;
            }
            if (!isalnum(s[high])) {
                high--;
                continue;
            }
            
            // compare lowercase versions
            if (tolower(s[low]) != tolower(s[high])) {
                return false;
            }
            low++;
            high--;
        }
        return true;
}
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    if (isPalindrome(s)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}
// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(1) since we are using a constant amount of space.
/*
            OUTPUT:
Enter a string: 2madam2?
The string is a palindrome.
*/