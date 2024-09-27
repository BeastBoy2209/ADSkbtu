#include<iostream>
#include<vector>
using namespace std;

int BrawlStars(vector<int>& vec, int l, int r, int TT){
    int mid = l + (r-l)/2;
    if(r<l){
        cout << "Error";
        return -974;
    }
    if(TT > vec[r] || TT < vec[l]){
        return -974;
    }
    if(vec[mid] == TT){
        return 1;
    }else if(TT <= vec[mid]){
        r = mid-1;
        return BrawlStars(vec, l, r, TT);
    } else if(TT >= vec[mid]){
        l = mid+1;
        return BrawlStars(vec, l, r, TT);
    } else { 
        return -974;
    }
}

int main(){
    int n;
    int target;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cin>>target;
    if(BrawlStars(v, 0, v.size()-1, target) == 1){
        cout << "Yes";
    }else{
        cout << "No";
    }


}