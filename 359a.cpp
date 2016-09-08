//
// Created by 王若璇 on 16/6/24.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    while (cin>>n>>x){
        int ans = 0;
        for(ll i = 0;i<n;i++){
            char op;
            int tmp;
            cin>>op>>tmp;
            if(op=='+'){
                x+=tmp;
            } else{
                if(x>=tmp){
                    x-=tmp;
                } else{
                    ans++;
                }
            }
        }
        cout<<x<<" "<<ans<<endl;
    }

    return 0;
}