//
// Created by 王若璇 on 16/5/5.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int max_n = 110000;
int a[max_n];
int sum[max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        sum[0] = a[0];
        for(int i = 1;i<n;i++){
            sum[i] = sum[i-1]+a[i];
        }
        int ans = 0x3f3f3f3f;
        for(int i = 0;i<n-1;i++){
            ans = min(abs(sum[i]-(sum[n-1]-sum[i])),ans);
        }
        cout<<ans+1<<endl;
    }

    return 0;
}