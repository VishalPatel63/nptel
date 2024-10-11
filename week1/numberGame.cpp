#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int a, b;
    cin>>a>>b;

    int x = a/b;
    int y = b/a;
    if(x>1){
        cout<<"Arya wins"<<endl;
    }
    else if(y>1){
        cout<<"Arya wins"<<endl;
    }
    else{
        cout<<"bob wins"<<endl;
    }
    return 0;
}