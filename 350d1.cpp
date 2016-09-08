//
// Created by 王若璇 on 16/5/6.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int max_n = 100100;
struct Ingredient{
    int must;
    int res;
    int need;
    int num;
    int tot;
    bool operator<(const Ingredient& a)const {
        if(num!=a.num){
            return num>a.num;
        } else{
            return need>a.need;
        }
    }
}ingr[max_n];
priority_queue<Ingredient> pq;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    while (cin>>n>>k){
        while (!pq.empty()){
            pq.pop();
        }
        for(int i = 0;i<n;i++){
            cin>>ingr[i].must;
        }
        for(int i = 0;i<n;i++){
            cin>>ingr[i].tot;
            ingr[i].num = ingr[i].tot/ingr[i].must;
            ingr[i].res = ingr[i].tot%ingr[i].must;
            ingr[i].need = ingr[i].must-ingr[i].res;
            pq.push(ingr[i]);
        }
        int tmpk = k;
        //int ans = 0;
        while (tmpk>0){
            Ingredient now = pq.top();
            pq.pop();
            if(tmpk>=now.need){
                tmpk-=now.need;
                now.need = now.must;
                now.num++;
                now.res = 0;
                pq.push(now);
            } else{
                pq.push(now);
                break;
            }
        }
        Ingredient low = pq.top();
        cout<<low.num<<endl;


    }
    return 0;
}