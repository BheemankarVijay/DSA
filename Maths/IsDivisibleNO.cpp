/*
large number is divisible by k
Using the property of mod
*/

#include <iostream>
#include <string>
using namespace std;

bool isDivisibleBy13(const string &s,int k) {
    int mod = 0;
    for (char ch : s) {
        mod = (mod * 10 + (ch - '0')) % k;
    }
    return mod == 0;
}

int main() {
    string number;
    cout << "Enter a large number: ";
    cin >> number;
    int k;
    cout << "Enter the divisor (k): ";
    cin>>k;

    if (isDivisibleBy13(number,k))
        cout << number << " is divisible by." <<k<< endl;
    else
        cout << number << " is NOT divisible by " <<k<< endl;

    return 0;
}
/*
            OUTPUT:
Enter a large number: 12345678901234567890
Enter the divisor (k): 13   
12345678901234567890 is NOT divisible by 13
*/