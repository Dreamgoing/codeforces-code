//
// Created by 王若璇 on 16/6/9.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
const int p[40] = {2,4,3,5,7,9,11,13,17,19,23,25,29,31,37,41,49,43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};//25
bool vis[100];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //fflush(stdout);
    char s[5];
    int pos = 0;
    while (!pq.empty()){
        pq.pop();
    }
    int num = 0;
    //pq.push(100);
    int sum = 1;
    while (pos<20){
        printf("%d\n",p[pos++]);
        fflush(stdout);
        //fflush(stdout);
        scanf("%s",s);
        if(strcmp(s,"yes")==0){

            num++;
        }
        if(num>=2){
            printf("composite\n");
            fflush(stdout);
            return 0;
        }

    }

        printf("prime\n");
        fflush(stdout);

    return 0;
}
