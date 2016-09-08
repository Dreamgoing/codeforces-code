//
// Created by 王若璇 on 16/6/9.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
map<int,int> mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fflush(stdout);
    int a[5];
    int sum = 0;
    mp.clear();
    for(int i = 0;i<5;i++){
        cin>>a[i];
        sum+=a[i];
        mp[a[i]]++;
    }
    int ans = sum;
    for(map<int,int>::iterator it = mp.begin();it!=mp.end();it++){
        if(it->second>=2){
            ans = min(sum-min(it->second,3)*it->first,ans);
        }
    }
    cout<<ans<<endl;
    fflush(stdout);
    return 0;

}