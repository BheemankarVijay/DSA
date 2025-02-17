#include <iostream>
using namespace std;
int countDivisibleDigits(int n) {
    int temp = n;  
    int count = 0; 

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
    std::cout << "Number of digits in " << num << " that divide " << num << " evenly: " << countDivisibleDigits(num) << std::endl;
    return 0;
}
