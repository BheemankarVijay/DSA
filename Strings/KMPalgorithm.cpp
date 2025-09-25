// Leetcode Problem 28: Implement strStr() using KMP Algorithm
#include<iostream>
#include<vector>
using namespace std;
vector<int> computeLPS(string& pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;  // edge case
        
        int n = haystack.size();
        int m = needle.size();
        
        vector<int> lps = computeLPS(needle);
        int i = 0; // haystack index
        int j = 0; // needle index
        
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            
            if (j == m) {
                return i - j;  // found match
            } else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return -1; // not found
}
int main(){
    string haystack, needle;
    cout << "Enter the haystack string: ";
    getline(cin, haystack);
    cout << "Enter the needle string: ";
    getline(cin, needle);
    
    int result = strStr(haystack, needle);
    if(result != -1){
        cout << "The needle is found at index: " << result << endl;
    } else {
        cout << "The needle is not found in the haystack." << endl;
    }
    return 0;
}
// Time Complexity: O(n + m) where n is the length of haystack and m is the length of needle.
// Space Complexity: O(m) for the LPS array.
/*
            OUTPUT:
Enter the haystack string: hello
Enter the needle string: ll
The needle is found at index: 2
*/// Note: If the needle is an empty string, the function returns 0 as per the problem statement. If the needle is not found, it returns -1.