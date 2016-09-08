//
// Created by 王若璇 on 16/6/9.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int s[1000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fflush(stdout);
    int n,a;
    cin>>n>>a;
    for(int i = 1;i<=n;i++){
        cin>>s[i];
    }
    int l = a;
    int r = a;
    int ans = 0;
    while (l>=1||r<=n){
        if(l>=1&&r<=n){
            if(l!=r){
                if(s[l]==s[r]&&s[l]==1){
                    ans+=2;
                }
            } else{
                if(s[l]==s[r]&&s[l]==1){
                    ans++;
                }
            }
        }else if(l<1){
            if(s[r]==1){
                ans++;
            }
        }else if(r>n) {
            if (s[l] == 1) {
                ans++;
            }

        }else;
        l--;
        r++;
    }
    cout<<ans<<endl;
    fflush(stdout);
    return 0;
}