//
// Created by 王若璇 on 16/5/8.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int max_n = 100100;
bool vis[max_n];
set<int> div1;
set<int> div2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while (cin>>n>>m){
        memset(vis,0, sizeof(vis));
        div1.clear();
        div2.clear();
        div2.insert(0);
        bool ans = true;
        int max_up = 0;
        for(int i =0;i<m;i++){
            int u,v;
            cin>>u>>v;
            vis[u] = true;
            vis[v] = true;
            if(u>v) swap(u,v);
            if(div2.count(v)||div1.count(u)){
                ans = false;
            }
            div1.insert(v);
            div2.insert(u);
            max_up = max(max_up,u);

        }
        int num = 0;
        //cout<<max_up<<endl;
        if(ans){
           // cout<<*div2.begin()<<" *"<<endl;
            for(int i = 1;i<=n;i++){
                if(!vis[i]){
                    //cout<<*div2.end()<<" *"<<endl;
                    if(max_up<i){
                        num++;
                    }
                }
            }
            cout<<num+1<<endl;
        } else{
            cout<<0<<endl;
        }

    }
    return 0;
}