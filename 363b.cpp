//
// Created by 王若璇 on 16/7/19.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n = 1100;
char deop[max_n][max_n];
bool vis[max_n][max_n];
int n,m;
bool flag = true;
int row[max_n];
int cal[max_n];
bool solve(int &x,int &y){
    int num = 0;
    for(int i = 0;i<n;i++){
        for(int j= 0;j<n;j++){
            if(deop[i][j]=='*'){
                row[i]++;
                cal[j]++;
                num++;
            }

        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(deop[i][j]=='*'){
                if(row[i]+cal[j]-1==num){
                    x = i+1;
                    y = j+1;
                    return true;
                }
            } else{
                if(row[i]+cal[j]==num){
                    x = i+1;
                    y = j+1;
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    while (scanf("%d%d",&n,&m)!=EOF){
        memset(row,0, sizeof(row));
        memset(cal,0, sizeof(cal));
        for(int i = 0;i<n;i++){
            scanf("%s",deop[i]);
        }
        int x,y;
        if(solve(x,y)){
            cout<<"YES"<<endl;
            cout<<x<<" "<<y<<endl;
        } else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}