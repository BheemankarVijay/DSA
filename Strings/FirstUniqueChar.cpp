// Leetcode problem 387: First Unique Character in a String
/*
Logic: Use a hash map to count the frequency of each character, then find the first character with a frequency of 1.
*/
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
int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int result = firstUniqChar(s);
    if(result != -1){
        cout << "The index of the first unique character is: " << result << endl;
    }else{
        cout << "No unique character found." << endl;
    }
    return 0;
}
// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(1) since the character set is fixed (ASCII).
/*
            OUTPUT:
Enter a string: leetcode
The index of the first unique character is: 0
*/