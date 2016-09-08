#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e5+1;
int n, c;
int p[N], w[N], a[N];
vector<int> g[N];

void dfs(int u, long long d) {
    if (d > a[u]) return;
    c++;
    d = max(0ll, d);
    for(int i=0; i<g[u].size(); ++i) {
        int v = g[u][i];
        dfs(v, d+w[v]);
    }
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", a+i);
    for(int i=2; i<=n; ++i) {
        scanf("%d", p+i);
        scanf("%d", w+i);
        g[p[i]].push_back(i);
    }

    dfs(1, 0);
    printf("%d\n", n-c);

    return 0;
}