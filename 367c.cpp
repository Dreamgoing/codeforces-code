//
// Created by 王若璇 on 16/8/12.
//
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const long long max_n = 100100;
const long long inf = 1e16;
long long c[max_n];
string s[max_n];
long long dp[max_n][2];
long long n;
void solve(){
    cout<<inf<<endl;
    for(long long i = 0;i<max_n;i++){
        dp[i][1] = dp[i][0] = inf;
    }
    dp[0][0] = 0;
    dp[0][1] = c[0];
    for(long long i = 1;i<n;i++){
        string now = s[i];
        string pre = s[i-1];
        string now1 = now;
        reverse(now1.begin(),now1.end());
        //cout<<now<<" "<<now1<<endl;
        string pre1 =pre;
        reverse(pre1.begin(),pre1.end());
        if(pre<=now){
            dp[i][0] = dp[i-1][0];
        }
        if(pre1<=now){
            dp[i][0] = min(dp[i][0],dp[i-1][1]);
        }
        if(pre<=now1){
            dp[i][1] = dp[i-1][0]+c[i];
        }
        if(pre1<=now1){
            dp[i][1] = min(dp[i][1],dp[i-1][1]+c[i]);
        }

    }

}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>n){
        for(long long i = 0;i<n;i++){
            cin>>c[i];
        }
        for(long long i =0;i<n;i++){
            cin>>s[i];
        }
        solve();
        long long ans = min(dp[n-1][0],dp[n-1][1]);
        if(ans>=inf){
            cout<<-1<<endl;
        } else{
            cout<<ans<<endl;
        }
    }
    return 0;
}
