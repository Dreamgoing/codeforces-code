//
// Created by 王若璇 on 16/8/29.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int max_n = 1010;
string str[max_n];
bool solve(int n){
    for(int i = 0;i<n;i++){
        if(str[i][0]=='O'&&str[i][1]=='O'){
            str[i][0]='+';
            str[i][1]='+';
            return true;
        }
        if(str[i][3]=='O'&&str[i][4]=='O'){
            str[i][3]='+';
            str[i][4]='+';
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n){
        bool flag = false;
        for(int i = 0;i<n;i++){
            cin>>str[i];
        }
        if(solve(n)){
            cout<<"YES"<<endl;
            for(int i = 0;i<n;i++){
                cout<<str[i]<<endl;
            }
        } else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}

