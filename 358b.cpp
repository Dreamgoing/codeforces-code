//
// Created by 王若璇 on 16/6/18.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int max_n = 100100;
int a[max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int now = 0;
        for(int i = 0;i<n;i++){
            if(a[i]>=now+1){
                now++;
            }
        }
        cout<<now+1<<endl;
    }


    return 0;
}