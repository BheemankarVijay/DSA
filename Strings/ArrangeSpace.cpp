// Leetcode 1592. Rearrange Spaces Between Words
#include <iostream>
#include <vector>
#include <string>   
using namespace std;
string reorderSpaces(string text) {
        vector<string>words;
        int spaceLen=0;
        string word;
        for(char ch : text){
            if(ch == ' '){
                spaceLen++;
                if(!word.empty()){
                    words.push_back(word);
                    word.clear();
                }
            }else{
                word+=ch;
            }      
        }if(!word.empty())words.push_back(word);// for last word we push into words vector.
        int n=words.size();
        if(n == 1){
            return words[0]+string(spaceLen,' ');
        }
        int spaceEvenly = spaceLen/(n-1);
        int remainSpace = spaceLen%(n-1);
        string gap = string(spaceEvenly,' ');
        string result= words[0];
        for(int i=1;i<n;i++){
            result+=gap+words[i];
        }
        result+=string(remainSpace,' ');
        return result;
}
int main(){
    string text;
    cout << "Enter the text: ";
    getline(cin, text);
    string result = reorderSpaces(text);
    cout << "Reordered text: \"" << result << "\"" << endl;
    return 0;
}
// Time Complexity: O(n)
/*
         OUTPUT:
Enter the text:  this   is  a test
Reordered text: "this   is   a   test"
*/