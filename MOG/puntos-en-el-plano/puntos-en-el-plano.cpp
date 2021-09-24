// Problem name: B - Puntos en el plano
// Problem link: https://matcomgrader.com/problem/262/puntos-en-el-plano/
// Submission link: https://matcomgrader.com/submission/62108/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: B - Puntos en el plano */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a==b && a%2==0) printf("%d\n",a*2);
        else if(a==b && a%2==1) printf("%d\n",a*2-1);
        else if(a-b==2 && a%2==0) printf("%d\n",(a-1)*2);
        else if(a-b==2 && a%2==1) printf("%d\n",b*2+1);
        else printf("No Number\n");
    }
    return 0;
}