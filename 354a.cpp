//
// Created by 王若璇 on 16/5/25.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n = 1000;
int a[max_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        pair<int,int> maxnum;
        pair<int,int> minnum;
        maxnum.first = 0;
        maxnum.second = -1;
        minnum.first = 0x3f3f3f3f;
        minnum.second = -1;
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            if(maxnum.first<x){
                maxnum.first = x;
                maxnum.second = i;
            }
            if(minnum.first>x){
                minnum.first = x;
                minnum.second = i;
            }
        }
        int ans = max(n-1-min(minnum.second,maxnum.second),max(minnum.second,maxnum.second)-0);
        cout<<ans<<endl;

    }


    return 0;
}