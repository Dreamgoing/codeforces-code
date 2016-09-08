//
// Created by 王若璇 on 16/6/24.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
ll getNum(ll n){
    ll len = 1;
    for(ll a = 7;a<n;a*=7){
        len+=1;
    }
    return len;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    while (cin>>n>>m){
        ll num_n = getNum(n);
        ll num_m = getNum(m);
        //cout<<num_n<<" "<<num_m<<endl;
        if(num_n+num_m>7){
            cout<<0<<endl;
            continue;
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                vector<int> used(7,0);
                for(int a = i,k=0;k!=num_n;a/=7,k++){
                    used[a%7]+=1;
                }
                for(int b = j,k=0;k!=num_m;b/=7,k++){
                    used[b%7]+=1;
                }
                if(*max_element(used.begin(),used.end())<=1){
                    ++ans;
                }
            }

        }
        cout<<ans<<endl;


    }
    return 0;
}
