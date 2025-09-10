// Leetcode Problem 14: Longest Common Prefix
/*
Logic: Sort the array of strings. The longest common prefix of the entire array must be a prefix of the first and last strings in the sorted order. Compare characters of the first and last strings until they differ.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(),strs.end());
        string ans="";
        string low= strs.front();
        string high=strs.back();
        for(int i=0;i<min(low.size(),high.size());i++){
            if(low[i] == high[i]) ans+=low[i];
            else{
                break;
            }
        }
        return ans;
}
int main(){
    int n;
    cout<<"Enter number of strings: ";
    cin>>n;
    cin.ignore(); // To ignore the newline character after the integer input
    vector<string> strs(n);
    cout<<"Enter the strings:"<<endl;
    for(int i=0;i<n;i++){
        getline(cin,strs[i]);
    }
    string result = longestCommonPrefix(strs);
    if(result.empty()){
        cout<<"No common prefix found."<<endl;
    }else{
        cout<<"Longest common prefix: "<<result<<endl;
    }
    return 0;
}
// Time Complexity: O(m * n log n) where m is the average length of strings and n is the number of strings (due to sorting).
// Space Complexity: O(1) if we ignore the input storage, otherwise O(n)
/*
            OUTPUT:
Enter number of strings: 3
Enter the strings:
flower
flow   
flight
Longest common prefix: fl
*/