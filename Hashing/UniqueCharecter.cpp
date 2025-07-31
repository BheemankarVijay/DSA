// leetcode 387. First Unique Character in a String
// This code finds the first unique character in a string and returns its index.
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std; 
int firstUniqChar(string s) {
        unordered_map<char,int>str;
        for(char i : s){
            str[i]+=1;
        }
        for(int i=0;i<s.length();i++){
            if(str[s[i]] == 1) return i;
        }return -1;
        
}
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = firstUniqChar(s);
    if (result != -1) {
        cout << "First unique character is at index: " << result << endl;
    } else {
        cout << "No unique character found." << endl;
    }

    return 0;
}
// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(1) since the hash map will store at most 26 characters
/*
                    OUTPUT:
Enter a string: leetcode
First unique character is at index: 0
*/