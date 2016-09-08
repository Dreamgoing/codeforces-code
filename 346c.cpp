//
// Created by 王若璇 on 16/3/31.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;
const int max_n = (int)1e9+10;
int a[100100];
vector<int> ans;
unordered_map<int,bool> has;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while (cin>>n>>m){
        has.clear();
        ans.clear();
        for(int i = 0;i<n;i++){
            cin>>a[i];
            has[a[i]] = true;
        }
        int tmp = m;
        for(int i = 1;i<max_n&&tmp>=i;i++){
            if(has[i]!=true){
                ans.push_back(i);
                tmp-=i;
                has[i] = true;
            }
        }
        cout<<ans.size()<<endl;
        for(int i = 0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';


    }
    return 0;
}
