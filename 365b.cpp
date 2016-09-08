//
// Created by 王若璇 on 16/9/8.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
const int max_n = 100100;
typedef long long ll;
int n,k;
int c[max_n];
int idk[max_n];
void solve(){
    set<pair<int,int> > has;
    has.clear();
    ll ans = 0;
    for(int i = 1;i<n;i++){
        ans += c[i]*c[i+1];
    }
    ans+=c[1]*c[n];
    for(int i = 1;i<=k;i++){
        int now = idk[i];
        for(int j = 1;j<=n;j++){
            if(now!=j){
                int mi = min(now,j);
                int mx = max(now,j);

                if(mx-mi>1&&(mi!=1||mx!=n)&&has.count(make_pair(mi,mx))==0){
                    has.insert(make_pair(mi,mx));
                    //cout<<mx<<" "<<mi<<endl;
                    ans+=c[mi]*c[mx];
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>n>>k){
        for(int i = 1;i<=n;i++){
            cin>>c[i];
        }
        for(int i = 1;i<=k;i++){
            cin>>idk[i];
        }
        solve();


    }

    return 0;
}