// LeetCode 76 Minimum Window Substring uing Sliding Window
#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int>need,window;
        for(char ch : t) need[ch]++;
        int have=0,haveCount=need.size();
        int left=0,minLen=INT_MAX,start=0;

        for(int right=0;right<s.size();right++){
            char ch = s[right];
            window[ch]++;
            if(need.count(s[right]) && window[ch] == need[ch]){
                have++;
            }
            while(have == haveCount){
                // find sub string
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    start=left;
                }
                //left shrinking
                char d=s[left];
                window[d]--;
                if(need.count(d) && window[d]<need[d]){
                    have--;
                }
                left++;
            }
        }
        return minLen == INT_MAX?"":s.substr(start,minLen);
}
int main() {
    string s, t;
    cout << "Enter the main string (s): ";
    getline(cin, s);
    cout << "Enter the target string (t): ";
    getline(cin, t);
    
    string result = minWindow(s, t);
    if(result.empty()){
        cout << "No valid window found." << endl;
    } else {
        cout << "The minimum window substring is: " << result << endl;
    }
    return 0;
}
// Time Complexity: O(N) where N is the length of string s. Each character is processed at most twice (once by the right pointer and once by the left pointer).
// Space Complexity: O(M) where M is the number of unique characters in string t. We use a hashmap to store the frequency of characters in t and another hashmap for the current window.
/*
            OUTPUT:
Enter the main string (s): ADOBECODEBANC
Enter the target string (t): ABC
The minimum window substring is: BANC
*/// Note: If no such window exists that contains all characters of t, the function returns an empty string.