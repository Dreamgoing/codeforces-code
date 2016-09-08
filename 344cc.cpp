//
// Created by 王若璇 on 16/3/5.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n = 200100;
int a[max_n];
pair<int,int> op[max_n];
vector<pair<int,int> > v;
/*template<class BidirIt> reverse sourse code
void reverse(BidirIt first, BidirIt last)
{
    while ((first != last) && (first != --last)) {
        std::iter_swap(first++, last);
    }
}*/
vector<int> ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while (cin>>n>>m){
        v.clear();
        ans.clear();

        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        for(int i = 0;i<m;i++){
            cin>>op[i].first>>op[i].second;
        }
        int pos = -1;
        int op_num = 0;
        for(int i = m-1;i>=0;i--){
            if(op[i].second>pos){
                v.push_back(op[i]);
                pos = op[i].second;
                op_num++;
            }
        }
        sort(a,a+v[op_num-1].second);
        //cout<<right<<"right"<<endl;
        int pos_ans = 0;
        reverse(v.begin(),v.end());
        v.push_back(make_pair(0,0));
        for(int i = n-1;i>=v[0].second;i--){
            ans.push_back(a[i]);
        }
        int left = 0,right = v[0].second-1;
        for(int i = 0;i<v.size();i++){
            int cnt = v[i].second-v[i+1].second;
           // cout<<"v[i] "<<v[i].second<<" v[i+1] "<<v[i+1].second<<endl;
           // cout<<cnt<<" *"<<endl;
            for(int j = 0;j<cnt;j++){
                if (v[i].first==1){
                    ans.push_back(a[right--]);
                } else{
                    ans.push_back(a[left++]);
              //      cout<<" *****";
                }

            }
        }
        reverse(ans.begin(),ans.end());
        for(int i = 0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';


    }

    return 0;
}

