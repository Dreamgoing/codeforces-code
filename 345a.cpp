//
// Created by 王若璇 on 16/3/7.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int solve(int a,int b){
    int num = 0;
    while (a>0&&b>0){
        if(a<b){
            swap(a,b);
        }
        if(a==1){
            break;
        }
        a-=2;
        b+=1;
        num++;
    }
    return num;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    while (cin>>a>>b){
        cout<<solve(a,b)<<endl;
    }
    return 0;
}
