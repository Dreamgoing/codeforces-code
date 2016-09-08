#include<cstdio>
int i,n,m,c[100010],a;
long long ans,sum;
bool f[100010];
//copied...

int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&c[i]),sum+=c[i];
    for(i=1;i<=m;i++){
        scanf("%d",&a);
        sum-=c[a];
        ans+=sum*c[a];
        f[a]=1;
    }
    for(i=1;i<=n;i++)
        if(!f[i]&&!f[(i%n)+1])ans+=c[i]*c[(i%n)+1];
    printf("%I64d",ans);
    return 0;
}