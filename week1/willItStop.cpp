// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
    
    // int n;
    // cin>>n;
    // while(n>1){
    //     if(n%2 == 0){
    //         n = n/2;
    //     }
    //     else{
    //         n = 3*n +3;
    //     }
    // }

//   what value of n will terminate 
//  if number power will be power of 2 then terminate eventually
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 4;
    if((n^n-1)&n  == n){ // define n is even 
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}