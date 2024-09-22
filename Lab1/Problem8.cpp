#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool IsPrime(int num){
	for(long long i=2;i<=sqrt(num);i++)
		if(num%i==0)
			return false;
	return true;
}
int main(){
    int number;
    cin >> number;
    if(IsPrime(number)&& number !=1){
        cout << "YES";
    } else{
        cout << "NO";
    }
}