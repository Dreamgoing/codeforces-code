//
// Created by 王若璇 on 16/5/25.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int max_n = 10100;
const double eps = 1e-6;
double tree[12][27];
int n,t;
void add(double x,int i,int j){
    if(x<eps||j<1||j>i||i>n){
        return;
    }
    if(tree[i][j]+x<=1+1e-6){
        tree[i][j]+=x;
        return;
    } else{
        //tree[i][j] = 1;
        double tmpx = x-(1.-tree[i][j]);
        tree[i][j] = 1;
        add(tmpx/2,i+1,j);
        add(tmpx/2,i+1,j+1);
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin>>n>>t){
        memset(tree,0, sizeof(tree));
        for (int i = 0; i < t; ++i) {
            add(1,1,1);
        }
        int num = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=i;j++){
                if(fabs(tree[i][j]-1.)<=eps){
                    num++;
                }
            }

        }
        cout<<num<<endl;
    }

    return 0;
}