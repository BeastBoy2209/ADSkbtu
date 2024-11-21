#include <vector>
#include <iostream>
using namespace std;

int main(){
    int A;
    int B;
    int buf = B;
    int cnt = 0;
    vector<int> o;
    cin>>A>>B;
    o.push_back(B);
    while(A!=B){ 
        if(B > A){
            if(B % 2 == 0){
                B = B / 2; 
                o.push_back(B);
            }
            else{
                B += 1;  
                o.push_back(B);
            }
            cnt++;
        }
        else if(B < A){
            B += 1;
            o.push_back(B);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=o.size()-2;i>=0;i--){
        cout<<o[i]<<" ";
    }
}