//
// Created by 王若璇 on 16/6/2.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int max_n = 100100;
int a[max_n];
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,h,k;
    while (scanf("%d%d%d",&n,&h,&k)){
        int now = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i = 0;i<n;i++){
            bool flag = false;
            while (now+a[i]<=h&&i<n){
                now+=a[i];
                flag = true;
                i++;
            }
            if(!flag){
                int tmp = (now+a[i]-h)/k;
                now-=tmp*k;
                ans+=tmp;
            }
            //now-=k;
            now = max(now,0);
            //cout<<now<<" *"<<endl;
            ans++;
            i--;
        }
        ans+=now/k;
        if(now%k>0){
            ans++;
        }
        prinf("%d\n",ans);
    }

    return 0;
}