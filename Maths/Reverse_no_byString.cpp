#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// worest case time complexity when n digits  O(n)
int reverse_integer_naive(int n) {
    // Convert the integer to a string
    string str = to_string(n);

   
    reverse(str.begin(), str.end());

    int reversed = stoi(str);
    return reversed;
}

int main() {
    int num ;
    cout<<"Enter digits:";
    cin>>num;
    int reversed_num = reverse_integer_naive(num);
    cout << "Reversed integer: " << reversed_num << endl;
    return 0;
}
/* output:
   Enter digits:123
   Reversed integer: 321 
*/  
// Note: This code reverses the digits of a given integer using string manipulation.
// It converts the integer to a string, reverses the string, and then converts it back
// to an integer. The time complexity is O(n) where n is the number of digits in the integer.