// Problem name: D - Palindromes
// Problem link: https://matcomgrader.com/problem/6064/palindromes/
// Submission link: https://matcomgrader.com/submission/96993/

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    char s[ 1000005 ];
    scanf("%s", s);
    int len = strlen(s), cantd = 0, i, a = 0;
    sort(s, s + len);
    for(i = 0 ; s[ i ] != '\0' ; i++){
        if(!a && s[ i ] == s[ i - 1 ]){
            a = 1;
            cantd++;
        }
        else
            a = 0;
    }
    cantd *= 2;
    if(cantd != len)
        cantd++;
    printf("%d", cantd);
    return 0;
}