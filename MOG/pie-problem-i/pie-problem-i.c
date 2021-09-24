// Problem name: C - Pie Problem I
// Problem link: https://matcomgrader.com/problem/4478/pie-problem-i/
// Submission link: https://matcomgrader.com/submission/62118/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: A - Fito Task */

int main()
{
    int a,b,i,j,max=0,now,num,raiz;
    scanf("%d%d",&a,&b);
    for(i=a;i<=b;i++){
        now=2;
        raiz=i/2;
        for(j=2;j<raiz;j++)
            if(i%j==0)
                now++;
        if(now>max){
            max=now;
            num=i;
        }
    }
    printf("%d\n",num);
    return 0;
}