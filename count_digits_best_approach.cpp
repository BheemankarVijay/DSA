#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

countDivisibleDigits(int n){
    n=int(log10(n)+1);
    return n;
}

int main() {
    int num ;
    cout<<"Enter digits:";
    cin>>num;
    std::cout << "Number of digits in " << countDivisibleDigits(num) << std::endl;
    return 0;
}