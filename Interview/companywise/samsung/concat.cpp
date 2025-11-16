#include<bits/stdc++.h>
using namespace std;
void concat(char *a,char *b)
{
    while(*a!='\0')
    {
        a++;
    }
    while(*b!='\0')
    {
        *a=*b;
        a++;
        b++;
    }
    *a='\0';
}


int main()
{
    char a[100]="Hello";
    char b[]="World";
    concat(a,b);
    cout<<a<<endl;
    return 0;
}