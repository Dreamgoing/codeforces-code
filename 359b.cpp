//
// Created by 王若璇 on 16/6/24.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n = 1000;
const int max_op = 20000;
int a[max_n];
bool solve(int a[],int n){
    int pos = 1;
    int l,r;
    bool update = false;
    for(;pos<=n-1;pos++){
        if(a[pos]>a[pos+1]){
            l = pos;
            r = pos+1;
            swap(a[pos],a[pos+1]);
            update = true;
            pos+=2;
            while (a[pos]>a[pos+1]&&pos<=n-1){
                r = pos+1;
                swap(a[pos],a[pos+1]);
                pos+=2;

            }
            cout<<l<<" "<<r<<endl;
            break;
        }
    }
    return update;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        for(int i = 1;i<=n;i++){
            cin>>a[i];
        }
        int time = 0;
        while (time<max_op&&solve(a,n)){
            time++;
        }
        //cout<<'\n';
    }
    return 0;
}