//
// Created by 王若璇 on 16/3/4.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int max_n = 1000+100;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        long long tmp;
        long long a = 0;
        long long b = 0;
        for(int i = 0; i < n;i++){
            cin>>tmp;
            a = a|tmp;
        }
        for(int i = 0;i < n;i++){
            cin>>tmp;
            b = b|tmp;
        }
        cout<<a+b<<endl;
    }

    return 0;
}
