#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;
set<string> res;
string s;
bool vis[10000][4];
void solve(int idx,int len){
    if(idx<=5){
        return;
    }
    if(vis[idx][len]){
        return;
    }
    vis[idx][len] = true;
    if(len!=2||s.substr(idx-1,2)!=s.substr(idx+1,2)){
        res.insert(s.substr(idx-1,2));
        solve(idx-2,2);
    }
    if(idx==6){
        return;
    }
    if(len!=3||s.substr(idx-2,3)!=s.substr(idx+1,3)){
        res.insert(s.substr(idx-2,3));
        solve(idx-3,3);
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>s){
        memset(vis,0, sizeof(vis));
        res.clear();
        solve(s.size()-1,0);
        cout<<res.size()<<endl;
        for(auto i = res.begin();i!=res.end();i++){
            cout<<*i<<endl;
        }

    }
    return 0;
}