// Leettcode problem (49): Group Anagrams
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(string ch : strs){
            string key= ch; // we can't make sort original string so need copy.
            sort(key.begin(),key.end());
            mp[key].push_back(ch);
        }
        for(auto&p : mp){
            ans.push_back(p.second);
        }
        return ans;
}
int main(){
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    vector<string> strs(n);
    cout << "Enter the strings:" << endl;
    for(int i = 0; i < n; i++){
        cin >> strs[i];
    }
    vector<vector<string>> result = groupAnagrams(strs);
    cout << "Grouped Anagrams:" << endl;
    for(const auto& group : result){
        for(const auto& str : group){
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
// Time Complexity: O(n * k log k) where n is the number of strings and k is the maximum length of a string (due to sorting each string).
// Space Complexity: O(n * k) for storing the output.
/*
            OUTPUT:
Enter the number of strings: 6
Enter the strings:
eat
tea
tan
ate
bat
Grouped Anagrams:
eat tea ate
tan
bat
*/// Note: The order of groups and the order of strings within each group may vary.