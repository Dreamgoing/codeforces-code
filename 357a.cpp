//
// Created by 王若璇 on 16/6/15.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        string s;
        int before;
        int after;
        bool isok = false;
        for(int i =0;i<n;i++){
            cin>>s>>before>>after;
            if(before>=2400&&after>before){
                isok = true;
            }

        }
        if(isok){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}