//
// Created by 王若璇 on 16/5/17.
//
//not have a good time complexity
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int max_n = 110000;
map<long long ,long long > res;
struct Node{
    long long x;
    Node *left;
    Node *right;
    Node(){
        x = 0;
        left = NULL;
        right = NULL;
    }
    Node(long long _x){
        x = _x;
        left = NULL;
        right = NULL;

    }
}*root;
void insert(long long x){
    Node *in = new Node(x);
    Node *tmp = root;
    Node *fin;
    while (tmp!=NULL){
        fin = tmp;
        if(x>tmp->x){
            tmp = tmp->right;
        } else{
            tmp = tmp->left;
        }
    }
    if(x>fin->x){
        fin->right = in;
    } else{
        fin->left = in;
    }
    res[x] = fin->x;
}
long long a[max_n];
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    while (~scanf("%d",&n)){
        res.clear();
        //cin>>a[0];
        scanf("%lld",&a[0]);
        root = new Node(a[0]);
        for(int i = 1;i<n;i++){
            //cin>>a[i];
            scanf("%lld",&a[i]);
            insert(a[i]);
        }
        for(int i = 1;i<n;i++){
            //cout<<res[a[i]]<<" ";
            printf("%lld ",res[a[i]]);
        }
        printf("\n");

    }
    return 0;
}