#include<iostream>
#include<climits>
using namespace std;

int reverse(int x) {
    int min = INT_MIN;
    int max = INT_MAX;
    int rev = 0;
    while (x != 0) {
        int remainder = x % 10;
        x /= 10;
        if (rev > max / 10 || (rev == max / 10 && remainder > 7)) return 0; // Check for overflow
        if (rev < min / 10 || (rev == min / 10 && remainder < -8)) return 0;// Check for underflow
        rev = rev * 10 + remainder;
    }
    return rev;
}

int main(){
    int x;
    cout<<"Enter a number:";
    cin>>x;
    cout<<"Reverse number is "<<reverse(x);
}

/*output:
Enter a number:123
Reverse number is 321
*/