//
// Created by 王若璇 on 16/6/18.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    while (cin>>n>>m){
        ll tmpa = n/5;
        ll tmpb = m/5;
        ll ans = 5*tmpa*tmpb;
        ll ma = n%5;
        ll mb = m%5;
        ll mm = min(ma,mb);
        for(ll i = 1;i<=ma;i++){
            for(ll j = 1;j<=mb;j++){
                if(i+j==5){
                    ans++;
                }
            }
        }
        ans+=ma*tmpb+mb*tmpa;
        cout<<ans<<endl;
    }

    return 0;
}

