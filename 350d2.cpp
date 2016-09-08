//
// Created by 王若璇 on 16/5/6.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const long long max_n = 100100;
pair<long long ,long long > ingr[max_n];
const long long up = 10000000000;
long long n,k;
long long cost = 0;
long long sum = 0;
bool ok(long long m){
    long long now = k;
    for(int i = 0;i<n;i++){
        now-=max(0LL,ingr[i].first*m-ingr[i].second);
        if(now<0){
            return false;
        }
    }
    return true;
}
long long binarySearch(long long l,long long r){
    long long mid;
    while (l<r-1){
        mid = (l+r)/2;

        if(ok(mid)){
            l = mid;
        } else{
            r = mid;
        }
    }
    return l;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin>>n>>k){

        cost = 0;
        sum = 0;
        for(long long i = 0;i<n;i++){
            cin>>ingr[i].first;
            cost +=ingr[i].first;

        }
        for(long long i = 0;i<n;i++){
            cin>>ingr[i].second;
            sum+=ingr[i].second;
        }
        sum+=k;
        long long ans = binarySearch(0,up);
        //ans+=(sum-ans*cost)/cost;

        cout<<ans<<endl;

    }
    return 0;
}

