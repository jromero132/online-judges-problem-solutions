// Problem name: C - Triángulos
// Problem link: https://matcomgrader.com/problem/4700/triangulos/
// Submission link: https://matcomgrader.com/submission/62173/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: C - Tri�ngulos */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    deque<int> nums;
    int largo,n=0,nn,nnn;
    while(cin>>largo && largo!=0){
        nums.push_back(largo);
        n++;
    }
    nn=n-1;
    nnn=nn-1;
    bool hay=false;
    for(int i=0;i<nnn;i++){
        for(int j=i+1;j<nn;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]>nums[k] && nums[i]+nums[k]>nums[j] && nums[j]+nums[k]>nums[i]){
                    cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                    hay=true;
                    break;
                }
            }
            if(hay)
                break;
        }
        if(hay)
            break;
    }
    if(!hay)
        cout<<"NO"<<endl;
    return 0;
}