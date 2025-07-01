#include <iostream>
using namespace std;
int countDivisibleDigits(int n) {
    int temp = n;  
    int count = 1; 

    while (n > 0) {
        int digit = n % 10; 
        
        if (digit != 0 && temp % digit == 0) {
            count++;
        }
        n /= 10; 
    }

    return count; 
}

int main() {
    int num ;
    cout<<"Enter digits:";
    cin>>num;
    int count = countDivisibleDigits(num);
    cout << "Count of digits that divide the number: " << count << endl;
    return 0;
}

\* output:
   Enter digits:123
   Count of digits that divide the number: 3 
*/

// simply we can use maths formula log10(n) + 1 to count the number of digits in a number (int)(log10(n) + 1)
// but this code counts the number of digits that divide the number itself
