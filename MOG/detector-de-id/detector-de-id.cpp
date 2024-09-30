// Problem name: A - Detector de id
// Problem link: https://matcomgrader.com/problem/65/detector-de-id/
// Submission link: https://matcomgrader.com/submission/62234/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: A - Detector de id */

using namespace std;

string mail,usuario,facultad,departamento;
int len,slashes,arrobas,user_len,facultad_len,departamento_len;
bool caracteres_invalidos(){
    bool invalido=false;
    arrobas=0;
    slashes=0;
    if(mail[0]<97)
        return true;
    for(int i=0;i<len;i++){
        if(mail[i]=='@')
            arrobas++;
        else if(mail[i]=='/')
            slashes++;
        else if(((mail[i]<97 && mail[i]>57) || (mail[i]>=33 && mail[i]<48)) && mail[i]!='_' && mail[i]!='.'){
            invalido=true;
            break;
        }
    }
    if(arrobas!=1 || slashes>1)
        invalido=true;
    return invalido;
}
bool puntos_invalidos(){
    if(facultad[0]=='.' || facultad[facultad_len-1]=='.' || (facultad_len>=16 && find(facultad.begin(),facultad.begin()+16,'.')==facultad.begin()+16))
        return true;
    bool seguidos=false,hay=true;
    facultad_len--;
    for(int i=1;i<facultad_len;i++){
        if((facultad[i]=='.' && facultad[i-1]=='.') || (facultad_len-i>=16 && find(facultad.begin()+i,facultad.begin()+i+16,'.')==facultad.begin()+i+16))
            return true;
    }
    return false;
}
int validar(){

    int desde;
    for(int i=0;i<len;i++){
        if(mail[i]!='@')
            usuario+=mail[i];
        else{
            desde=i+1;
            break;
        }
    }
    bool aaa=true;
    for(int i=desde;i<len;i++){
        if(mail[i]!='/')
            facultad+=mail[i];
        else{
            desde=i+1;
            aaa=false;
            break;
        }
    }
    if(aaa)
        desde=len;
    for(int i=desde;i<len;i++)
        departamento+=mail[i];
    user_len=usuario.length();
    facultad_len=facultad.length();
    departamento_len=departamento.length();
    //cout<<usuario<<" "<<facultad<<" "<<departamento<<endl;
    if(user_len>32 || facultad_len==0 || facultad_len>56 || facultad[0]<97 || departamento_len>15 || (departamento_len==0 && slashes==1) || (departamento_len>0 && departamento[0]<97) || usuario.find('.',0)!=string::npos || departamento.find('.',0)!=string::npos || puntos_invalidos())
        return 0;
    if(departamento_len==0)
        return 1;
    else
        return 2;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    string usuario,facultad,departamento;
    int res;
    cin>>mail;
    len=mail.length();
    if(caracteres_invalidos())
        cout<<"I"<<endl;
    else{
        res=validar();
        if(res==2)
            cout<<"P"<<endl;
        else if(res==1)
            cout<<"E"<<endl;
        else
            cout<<"I"<<endl;
    }
    return 0;
}