//
// Created by 王若璇 on 16/8/25.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (cin>>s){
        int i = 0;
        while (s[i]=='a'&&i<s.length()){
            i++;
        }
        bool flag = false;
        while (s[i]!='a'&&i<s.length()){
            s[i]=s[i]-1;
            flag = true;
            i++;
        }
        //cout<<i<<endl;
        if(!flag){
            s[s.length()-1]='z';
        }
        cout<<s<<endl;
    }
    return 0;
}

