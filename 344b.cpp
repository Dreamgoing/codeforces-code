//
// Created by 王若璇 on 16/3/4.
//
//Time limit exceeded
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int max_size = 5050;
int mapp[max_size][max_size];
stack<pair<int,pair<int,int> > > st;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    while (cin>>n>>m>>k){
        memset(mapp,0, sizeof(mapp));

        int op,id,num;
        for(int i = 0;i<k;i++){
            cin>>op>>id>>num;
            st.push(make_pair(op,make_pair(id,num)));

        }
        pair<int,pair<int,int> > now;
        while (!st.empty()){
            now = st.top();
            st.pop();
            if(now.first==1){
                for(int i = 1;i<=m;i++){
                    if(!mapp[now.second.first][i]){
                        mapp[now.second.first][i] = now.second.second;
                    }
                }
            } else{
                for(int i = 1;i<=n;i++){
                    if(!mapp[i][now.second.first]){
                        mapp[i][now.second.first] = now.second.second;
                    }
                }
            }
        }
        for(int j = 1;j<=n;j++){
            for(int i = 1;i<=m;i++){
                cout<<mapp[j][i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
