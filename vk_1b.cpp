//
// Created by 王若璇 on 16/3/29.
//
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int max_n = 150050;
struct Bear{
    int a;
    int b;
    bool operator<(const Bear& c)const {
        return this->b>c.b;
    }
}bears[max_n];
priority_queue<Bear> pq;
bool isExist[max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,q;
    while (cin>>n>>k>>q){
        memset(isExist,0, sizeof(isExist));
        while (!pq.empty()){
            pq.pop();
        }
        for(int i = 1;i<=n;i++){
            cin>>bears[i].b;
            bears[i].a = i;
        }
        for(int i = 0;i<q;i++){
            int id,num;
            cin>>id>>num;
            if(id == 1){
                if(pq.size()<k){
                    pq.push(bears[num]);
                    isExist[bears[num].a] = true;

                } else{
                    Bear tmp = pq.top();

                    if(bears[num].b<tmp.b){
                        continue;
                    }
                    //cout<<" *"<<tmp.a<<endl;
                    isExist[tmp.a] = false;
                    pq.pop();
                    pq.push(bears[num]);
                    isExist[bears[num].a] = true;
                }
            } else{
                if(isExist[bears[num].a]){
                    cout<<"YES"<<endl;
                } else{
                    cout<<"NO"<<endl;
                }

            }
        }
    }

    return 0;
}