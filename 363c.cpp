//
// Created by 王若璇 on 16/7/19.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int max_n = 110;
int a[max_n];
int n;
int ans = 0x3f3f3f3f;
void dfs(int pos,int rest,int pre){

    if(pos>=n){
        ans = min(ans,rest);
        return;
    }
    if(a[pos]==0){
        dfs(pos+1,rest+1,0);
    }else if(a[pos]==1){
        if(pre!=1){
            dfs(pos+1,rest,1);
        } else{
            dfs(pos+1,rest+1,0);
        }
    }else if(a[pos]==2){
        if(pre!=2){
            dfs(pos+1,rest,2);
        } else{
            dfs(pos+1,rest+1,0);
        }
        //
    }else if(a[pos]==3){
        if(pre!=2){
            dfs(pos+1,rest,2);
        }
        if(pre!=1){
            dfs(pos+1,rest,1);
        }
        //dfs(pos,rest+1,0);
    } else;
    //cout<<rest<<"*"<<pos<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>n){
        ans = 0x3f3f3f3f;
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        dfs(0,0,0);
        cout<<ans<<endl;
    }

    return 0;
}