//
// Created by 王若璇 on 16/7/19.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int max_n = 200200;
bool vis[max_n];
int a[max_n];
int par[max_n];
vector<int> g[max_n];
int root = -1;
bool viscicle[max_n];
bool circle(int u,int pre,int &x,bool &hasroot){
    vis[u] = true;
    if(u==root){
        hasroot = true;
    }
    for(int i = 0;i<g[u].size();i++){
        int now = g[u][i];
        if(now!=pre){
            if(!vis[now]){
                circle(now,u);
            } else{
                x = u;
                return false;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    while (cin>>n){
        for(int i = 1;i<=n;i++){
            cin>>a[i];
            par[i] = a[i];
            if(a[i]==i){
                root = i;
            }
            g[i].push_back(a[i]);
            g[a[i]].push_back(i);
        }
        if(root==-1){
            root = 1;
            par[1] = 1;
        }
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                if(i!=root&&par[i]==i){
                    par[i] = root;
                    vis[i] = true;
                } else{
                    if(i!=root){
                        int x;
                        bool hasroot = false;
                        if(!circle(i,0,x,hasroot)){
                            par[x] = root;
                        }
                        if(!hasroot){
                            par[i] = root;
                        }
                    }
                }
            }
        }
        for(int i = 1;i<=n;i++){
            cout<<par[i]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
