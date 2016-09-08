//
// Created by 王若璇 on 16/8/25.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n = 100100;
int a[max_n];
int n,x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>n>>x){
        for(int i = 1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        long long ans1 = 0x3f3f3f3f;
        ans1 = min(a[n-1]-a[1]+abs(x-a[1]),a[n]-a[2]+abs(x-a[n]));
        long long ans2 = 0x3f3f3f3f;
        ans2 = min(a[n-1]-a[1]+abs(x-a[n-1]),a[n]-a[2]+abs(x-a[2]));
        long long ans = min(ans1,ans2);
        if(n==1){
            ans = 0;
        }
        cout<<ans<<endl;

    }
    return 0;
}
