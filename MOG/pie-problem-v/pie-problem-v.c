// Problem name: G - Pie Problem V
// Problem link: https://matcomgrader.com/problem/4493/pie-problem-v/
// Submission link: https://matcomgrader.com/submission/62119/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: G - Pie Problem V */

int main()
{
    double circulos[10],x,y,dist;
    int t,r,a,tot=0,i,k,kk;
    scanf("%d%d",&r,&t);
    circulos[0]=r;
    for(i=1;i<=9;i++)
        circulos[i]=2*circulos[i-1];
    for(k=1;k<=t;k++){
        scanf("%lf%lf",&x,&y);
        dist=sqrt(x*x+y*y);
        for(i=0;i<=9;i++){
            if(dist<=circulos[i]){
                tot+=11-i-1;
                break;
            }
        }
    }
    printf("%d\n",tot);
    return 0;
}