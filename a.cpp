//
// Created by 王若璇 on 16/8/25.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
const int max_n = 1100100;
using namespace std;
int a[max_n];
int n,b,d;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>n>>b>>d){
        int sum = 0;
        int num = 0;
        for(int i = 0;i<n;i++){
            cin>>a[i];
            if(a[i]<=b){
                sum+=a[i];
            }
            if(sum>d){
                sum = 0;
                num++;
            }
        }
        cout<<num<<endl;
    }

    return 0;
}