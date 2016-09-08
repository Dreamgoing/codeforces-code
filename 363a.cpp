//
// Created by 王若璇 on 16/7/19.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int max_n = 200200;
int a[max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 0x3f3f3f3f;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    for(int i = 0;i<n;i++){
        while (s[i]=='L'&&i<n){
            i++;
        }
        while (s[i]=='R'&&i<n){
            i++;
        }
        if(i<n&&s[i]=='L'){
            ans = min(ans,(a[i]-a[i-1])/2);
        }
    }
    if(ans==0x3f3f3f3f){
        cout<<-1<<endl;
    } else{
        cout<<ans<<endl;
    }
    return 0;
}