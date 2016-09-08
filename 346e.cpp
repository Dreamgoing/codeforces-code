//
// Created by 王若璇 on 16/3/31.
////并查集求所有的连通分量,判断联通分量里面是否有回路
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int max_n = 100100;
int par[max_n];
int vrank[max_n];
int n,m;
void init(int n){
    for(int i = 0;i<=n;i++){
        vrank[i] = 0;
        par[i] = i;
    }

}
/*path compression find*/
int find(int x){
    if(par[x]==x){
        return x;
    } else{
        return par[x] = find(par[x]);
    }
}
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y){
        return;
    }
    if(vrank[x]<vrank[y]){
        par[x] = y;
    } else{
        par[y] = x;
        if(vrank[x]==vrank[y]){
            vrank[x]++;
        }
    }
}
bool same(int x,int y){
    return find(x) == find(y);
}
vector<int> graph[max_n];
bool isExist[max_n];
bool dfs(int s,int f){
    if(isExist[s]){
        return false;
    }
    isExist[s] = true;
    bool res = true;
    for(int i = 0;i<graph[s].size();i++){
        int tmp = graph[s][i];
        if(tmp!=f){
            if(!dfs(tmp,s)){
                res = false;
            }
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin>>n>>m) {
        init(n);
        int from,to;
        memset(isExist,0, sizeof(isExist));
        for(int i = 0;i<=n;i++){
            graph[i].clear();
        }
        for(int i = 0;i<m;i++) {
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(!isExist[i]){
                ans+=dfs(i,0);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
