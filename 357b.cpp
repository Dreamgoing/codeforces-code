//
// Created by 王若璇 on 16/6/15.
//
//数论方面加强
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int c[3] = {1234,123456,1234567};
typedef long long ll ;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll r=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
bool linear_equation(ll a,ll b,ll c,ll &x,ll &y)
{
    ll d=exgcd(a,b,x,y);
    if(c%d)
        return false;
    ll k=c/d;
    x*=k; y*=k;    //求得的只是其中一组解
    ll b1 = b/d;
    ll a1 = a/d;
    ll i = 0;

    //cout<<x<<" "<<y<<endl;
    if(y<0){
        while (y<=0){
            y+=a1;
            x-=b1;

        }
    }
    while (y-a1>=0){
        y-=a1;
        x+=b1;
    }
    if(y>=0&&x>=0){
        return true;
    } else{
        return false;
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll s;
    while (cin>>s){
        ll a = s/c[2]+1;
        //cout<<a<<endl;
        bool ok = false;
        for(ll i = 0;i<=a;i++){
            ll tmp = s-c[2]*i;
            //cout<<tmp<<" "<<endl;
            if(tmp>=0){
                ll x,y;
                if(linear_equation(c[0],c[1],tmp,x,y)){
                    ok = true;
                    //cout<<i<<" "<<x<<" "<<y<<" "<<endl;
                    break;
                }
            }
        }
        if(ok){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}