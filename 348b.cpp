//
// Created by 王若璇 on 16/4/25.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
const int max_n = 100100;
int d[max_n];
string str;
int n;
bool vis[max_n];
bool solve(){
    int pos = 1;
    bool res = true;
    memset(vis,0, sizeof(vis));
    while (true){
        if(pos<1||pos>n){
            res = false;
            break;
        } else{
            if(!vis[pos]){
                vis[pos] = true;
                if(str[pos-1]=='>'){
                    pos+=d[pos];
                } else{
                    pos-=d[pos];
                }
            } else{
                res = true;
                break;
            }
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin>>n){
        memset(d,0, sizeof(d));
        cin>>str;
        for(int i = 1;i<=n;i++){
            cin>>d[i];
        }
        if(solve()){
            cout<<"INFINITE"<<endl;
        } else{
            cout<<"FINITE"<<endl;
        }

    }
    return 0;
}
