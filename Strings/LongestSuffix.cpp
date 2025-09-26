// Leetcode problem 1392: Longest Happy Prefix using KMP Algorithm
#include<iostream>
#include<vector>
using namespace std;
string longestPrefix(string s) {
        int m= s.size();
        vector<int>LPS(m,0);
        int len=0,i=1;
        while(i<m){
            if(s[i]==s[len]){
                len++;
                LPS[i]=len;
                i++;
            }
            else{
                if(len!=0){
                   len=LPS[len-1]; 
                }else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
        return s.substr(0,LPS.back());
}
int main(){
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    string result = longestPrefix(s);
    if(result.empty()){
        cout << "No happy prefix found." << endl;
    } else {
        cout << "Longest happy prefix: " << result << endl;
    }
    return 0;
}
// Time Complexity: O(n)
/*
         OUTPUT:
Enter the string: level
Longest happy prefix: l
*/