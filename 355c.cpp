//
// Created by 王若璇 on 16/6/2.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
const int modn = 1000000007;
typedef long long ll;
int tree[20];

int getNum(char c) {
    if (c == '-') {
        return 62;
    } else if (c == '_') {
        return 63;
    } else if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 36;
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    } else {
        return -1;
    }
}

/*int getZero(int num){
    int ans = 0;
    for(int i = 0;i<8;i++){
        if((num&1)==1){
            ans++;
        }
        num = num>>1;
    }
    return  (8-ans);
}*/
int BitCount(int n) {
    unsigned int c = 0; // 计数器
    while (n > 0) {
        if ((n & 1) == 1) // 当前位是1
            ++c; // 计数器加1
        n >>= 1; // 移位
    }
    return c;
}

void init() {
    tree[0] = 1;
    for (int i = 1; i <= 10; i++) {
        tree[i] = tree[i - 1] * 3;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    init();
    while (cin >> s) {
        ll ans = 1;
        for (int i = 0; i < s.size(); i++) {
            int num = getNum(s[i]);
            //cout<<num<<endl;
            int zeronum = 6 - BitCount(num);
            //cout<<zeronum<<endl;
            ans *= ((tree[zeronum]) % modn);
            ans = ans % modn;
        }
        cout << ans << endl;
    }
    return 0;
}