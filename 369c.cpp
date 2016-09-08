//
// Created by 王若璇 on 16/8/29.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const long long  max_n = 110;
const long long  inf = (long long)(1e18);
long long  n,m,kk;
long long  c[max_n];
long long  p[max_n][max_n];
long long  dp[max_n][max_n][max_n];
long long  getK(){
    long long  ans = 0;
    long long  pos = 1;
    long long  now = c[pos];
    while (pos<=n){
        if(c[pos]!=0)
            ans++;
        while (now==c[pos]&&pos<=n){
            pos++;
        }
        now = c[pos];
    }
    return ans;

}
long long  solve(long long  rek){
    //memset(dp,inf, sizeof(dp));
    long long  ans = inf;
    for(long long  i = 0;i<=n;i++){
        for(long long  j = 0;j<=m;j++){
            for(long long  k = 0;k<=rek;k++){
                dp[i][j][k] = inf;
            }
        }
    }
    if(c[1]==0){
        for(long long  i = 1;i<=m;i++){
           dp[1][i][1] = p[1][i];
        }
    } else{
        dp[1][c[1]][1]=0;
    }
    //cout<<inf<<endl;
    for(long long  k = 1;k<=rek;k++){
        for(long long  i = 2;i<=n;i++){
            if (c[i]){
                dp[i][c[i]][k] = min(dp[i-1][c[i]][k],dp[i][c[i]][k]);
                for(long long  r = 1;r<=m;r++){
                    if(r!=c[i]){
                        dp[i][c[i]][k] = min(dp[i][c[i]][k],dp[i-1][r][k-1]);
                    }

                }
                continue;
            }
            for(long long  j = 1;j<=m;j++){
                dp[i][j][k] = min(dp[i-1][j][k]+p[i][j],dp[i][j][k]);
                //cout<<i<<" "<<j<<" "<<" "<<k<<" "<<dp[i][j][k]<<"-----"<<endl;
                for(long long  l = 1;l<=m;l++){
                    if(l!=j&&k>1){
                        dp[i][j][k] = min(dp[i-1][l][k-1]+p[i][j],dp[i][j][k]);
                    }
                }
                //cout<<i<<" "<<j<<" "<<" "<<k<<" "<<dp[i][j][k]<<endl;

            }
        }
    }
    for(long long  i = 1;i<=m;i++){
        ans = min(ans,dp[n][i][rek]);

    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>n>>m>>kk){
        for(long long  i = 1;i<=n;i++){
            cin>>c[i];
        }
        //long long  initk = getK();
        //cout<<initk<<endl;
        for(long long  i = 1;i<=n;i++){
            for(long long  j = 1;j<=m;j++){
                cin>>p[i][j];
            }
        }
        long long  ans = solve(kk);
        if(ans>=inf){
            cout<<-1<<endl;
        } else{
            cout<<ans<<endl;
        }
    }
    return 0;
}
