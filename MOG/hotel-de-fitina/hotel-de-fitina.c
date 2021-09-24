// Problem name: B - Hotel de Fitiña
// Problem link: https://matcomgrader.com/problem/129/hotel-de-fitina/
// Submission link: https://matcomgrader.com/submission/62175/

#include <stdio.h>
#include <stdlib.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: B - Hotel de Fiti�a */

int main()
{
    long long a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF){
        while(b-a>0){
            b-=a;
            a++;
        }
        printf("%lld\n",a);
    }
    return 0;
}