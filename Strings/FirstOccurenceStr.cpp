// Leetcode problem (28): Implement strStr()
#include<iostream>
#include<string>
using namespace std;
int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if(m == 0) return 0;
    
        for(int i=0;i<=n-m;i++){
            if(haystack.substr(i,m)== needle) return i; // like fixed size sliding window
        }
        return -1;
}
int main(){
    string haystack, needle;
    cout << "Enter the haystack string: ";
    getline(cin, haystack);
    cout << "Enter the needle string: ";
    getline(cin, needle);
    
    int result = strStr(haystack, needle);
    if(result != -1){
        cout << "The first occurrence of the needle is at index: " << result << endl;
    } else {
        cout << "The needle was not found in the haystack." << endl;
    }
    return 0;
}
// Time Complexity: O((N-M+1)*M) in worst case where N is the length of haystack and M is the length of needle.
// Space Complexity: O(1) as we are not using any extra space.
/*
            OUTPUT:
Enter the haystack string: hello
Enter the needle string: ll
The first occurrence of the needle is at index: 2
*/// Note: If needle is an empty string, we return 0 as per the problem statement.