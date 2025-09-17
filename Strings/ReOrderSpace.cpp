//LeetCode Problem 519: Reorder Spaces Between Words
/*
we are given a string text of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It is guaranteed that text contains at least one word.
Reorder the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized. If you cannot redistribute all the spaces equally, place the extra spaces at the end, meaning the returned string should be the same length as text.
*/
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
    cout << "Reordered text: '" << result << "'" << endl;
    return 0;
}
// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(n) for storing words.
/*
            OUTPUT:
Enter the text:  this   is  a test
Reordered text: 'this   is   a   test'
*/  
