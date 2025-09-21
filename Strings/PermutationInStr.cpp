// Leetcode Problem 567: Permutation in String using Sliding Window
#include<iostream>
#include<string>
using namespace std;
bool sameFreq(int freq1[],int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
}
bool checkInclusion(string s1, string s2) {
        int freq[26]={0}; // count charector
        for(int i=0;i<s1.length();i++){
            freq[s1[i] - 'a']++;
        }
        int windsize=s1.length(); // window size
        for(int i=0;i<s2.length();i++){
            int low=0 ,high=i;
            int windfreq[26]={0};
            while(low<windsize && high<s2.length()){
                windfreq[s2[high]-'a']++;
                low++,high++;
            }
            if(sameFreq(freq,windfreq)){
                return true;
            }
        }
        return false;
}
int main(){
    string s1, s2;
    cout << "Enter the first string (s1): ";
    getline(cin, s1);
    cout << "Enter the second string (s2): ";
    getline(cin, s2);
    
    bool result = checkInclusion(s1, s2);
    if(result){
        cout << "s2 contains a permutation of s1." << endl;
    } else {
        cout << "s2 does not contain a permutation of s1." << endl;
    }
    return 0;
}
// Time Complexity: O(26 * (N-M+1)*M) in worst case where N is the length of s2 and M is the length of s1.
// Space Complexity: O(1) as we are using fixed size frequency arrays of size
// 26 (for each letter in the alphabet).
/*
            OUTPUT:
Enter the first string (s1): ab
Enter the second string (s2): eidbaooo
s2 contains a permutation of s1.
*/// Note: If s1 is longer than s2, we can immediately return false as s2 cannot contain a permutation of s1.