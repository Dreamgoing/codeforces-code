//
// Created by 王若璇 on 16/8/31.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mod_n = 1e9+7;
const int max_n = 200010;
int n;
int g[max_n];
int vis[max_n];
bool ok[max_n];
int d[max_n];
ll quickpow(ll n,ll m,ll k){
    ll res = 1;
    while (n>0){
        if(n&1){
            res = (res*m)%k;
        }
        n = n>>1;
        m = (m*m)%k;
    }
    return res;
}
ll ans = 1;
ll num = 0;
int pos = 0;
ll getNum(int x){
    int next = g[x];
    vis[x] = 3;
    ll ans = 1;
    while (x!=next){
        next = g[next];
        vis[next] = 3;
        //cout<<" ok "<<endl;
        ans++;
    }
    return ans;
}
void dfs(int x){
    if(vis[x]==2){
        ll tmpstep = getNum(x);
        num += tmpstep;
        ans*=(quickpow(tmpstep,2,mod_n)-2);
        ans = ans%mod_n;
        //cout<<tmpstep<<" * "<<endl;
    }else if(vis[x]==0){
        vis[x] = 2;
        dfs(g[x]);
    } else;
    vis[x] = 1;
}
int main(){
    while (scanf("%d",&n)!=EOF){
        memset(vis,0, sizeof(vis));
        num = 0;
        ans = 1;
        for(int i = 1;i<=n;i++){
            int x;
            scanf("%d",&x);
            g[i] = x;
        }
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                //cout<<i<<endl;
                dfs(i);
            }
        }
        //cout<<"num "<<num<<endl;

        ans*=quickpow(n-num,2,mod_n);
        ans = ans%mod_n;
        printf("%lld\n",ans);

    }

    return 0;
}
