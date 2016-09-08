//
// Created by 王若璇 on 16/84.
///
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n;
    int num1,num2;
    while (cin>>n){
        int x,y;
        num1 = 0;
        num2 = 0;
        for(int i = 0;i<n;i++){
            cin>>x>>y;
            if(x>y){
                num1++;
            }else if(x<y){
                num2++;
            }
        }
        if(num1>num2){
            cout<<"Mishka"<<endl;
        }else if(num1==num2){
            cout<<"Friendship is magic!^^"<<endl;
        } else{
            cout<<"Chris"<<endl;
        }

    }
    return 0;
}
