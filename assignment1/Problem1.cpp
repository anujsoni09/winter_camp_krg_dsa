#include<bits/stdc++.h>
using namespace std;
int main(){

    string st= {"Anuj Soni cr of kargil batch!"};
    int len=0;
    for(int i=0; st[i]!='\0'; i++){
        len++;
    }
    cout<<"length of string is: "<<len<<endl;
    cout<<st;
    string copyStr;
    for(int i=0; st[i]!='\0'; i++){
        copyStr += st[i];
    }
    cout<<endl<<"Copied string is: "<<copyStr<<endl;
    int i=0, j=len-1; 
    while(i<j){
        char temp;
        temp = st[i];
        st[i]=st[j];
        st[j]=temp;
        i++;
        j--;
    }
    cout<<endl<<"reversed string is: "<<st<<endl;
    st = copyStr + st;
    cout<<endl<<st<<endl;
}
