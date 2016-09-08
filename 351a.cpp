//
// Created by 王若璇 on 16/5/7.
//
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n = 100;
int a[max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        for(int i = 1;i<=n;i++){
            cin>>a[i];
        }
        int now = 0;
        int ans = 90;
        a[n+1] = 91;
        a[0] = 0;
        for(int i = 1;i<=n+1;i++){
            int tmp = a[i]-a[i-1]-1;
            if(tmp>=15){
                ans=a[i-1]+15;
                break;
            }

        }
        cout<<min(ans,90)<<endl;
    }
    return 0;
}