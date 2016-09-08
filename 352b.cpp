//
// Created by 王若璇 on 16/5/12.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
bool vis[100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        string s;
        memset(vis,0, sizeof(vis));
        cin>>s;
        if(n>26){
            cout<<-1<<endl;
            continue;
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(vis[s[i]-'a']){
                ans++;
            } else{
                vis[s[i]-'a'] = true;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}