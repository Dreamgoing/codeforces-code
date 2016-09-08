//
// Created by 王若璇 on 16/3/31.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    while (cin>>n>>a>>b){
        int tmp = a+b;
        while (tmp<=0){
            tmp+=n;
        }
        while (tmp>n){
            tmp-=n;
        }
        cout<<tmp<<endl;

    }
    return 0;
}