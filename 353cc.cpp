//
// Created by 王若璇 on 16/5/17.
//
//not have a good time complex
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
using namespace std;
const int max_n = 110000;
map<int,int> res;
set<int> ss;
int a[max_n];
int t[max_n*1000];
void insert(int x){
    int root = 1;
    while (t[root]!=0){
        if(x>t[root]){
            root = 2*root+1;
        } else{
            root = 2*root;
        }
    }
    //cout<<"in "<<x<<" idx "<<root<<" ";
    t[root] = x;
    res[x] = t[root/2];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        res.clear();
        //int s = 1e9;
        //cout<<s<<endl;
        cin>>a[0];
        memset(t,0, sizeof(t));
        t[1] = a[0];
        res[a[0]] = a[0];

        for(int i = 1;i<n;i++){
            cin>>a[i];
            insert(a[i]);
        }
        /*for(set<int>::iterator it = ss.begin();it!=ss.end();it++){
            cout<<*it<<" ";
        }*/
        for(int i = 1;i<n;i++){
            cout<<res[a[i]]<<" ";
        }
        cout<<'\n';


    }
    return 0;
}