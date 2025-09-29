//Leetcode 214. Shortest Palindrome
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//find LPS 
vector<int>getLPS(string s){
        int n=s.size();
        vector<int>lps(n,0);
        int low=0,i=1;
        while(i<n){
            if(s[low]==s[i]){
                low++;
                lps[i]=low;
                i++;
            }else{
                if(low != 0){
                    low=lps[low-1];
                    
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        // Concatenate s + '#' + reversed(s)
        string str = s + '#' + rev;
        
        // Compute LPS array of str
        auto lps = getLPS(str);
        
        // Add the part of rev that is not part of the palindromic prefix
        string ans = rev.substr(0, n - lps.back()) + s;
        
        return ans;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);
    string result=shortestPalindrome(s);
    cout<<"Smallest Palindrome: "<<result<<endl;
    return 0;
}
// Time Complexity: O(n)
/*
         OUTPUT:
Enter the string: abcd
Smallest Palindrome: dcbabcd
*/