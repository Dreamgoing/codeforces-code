//
// Created by 王若璇 on 16/3/7.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const int max_n = 2000;
int a[max_n];
int cnt[max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        memset(cnt,0, sizeof(cnt));
        int lop = 0;
        for(int i = 0;i<n;i++){
            cin>>a[i];
            cnt[a[i]]++;
            lop = max(lop,cnt[a[i]]);
        }
        int ans = 0;
        for(int i = 0;i<lop;i++){
            int num = 0;
            for(int j = 0;j<n;j++){
                if(cnt[a[j]]>0){
                    cnt[a[j]]--;
                    num++;
                }
            }
            ans+=num-1;

        }
        cout<<ans<<endl;




    }
    return 0;
}
