#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;



int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        //find the smallers non-negative integer y that present in both x and y
        int x, y;
        cin >> x ;
        //find the smallest non-negative digit in x

        y=INT_MAX;
        while(x)
        {
            int digit = x % 10;
            if(digit >= 0 )
                y = min(y,digit);
            x /= 10;
        }
        cout<<y<<endl;
        
       
    }
    return 0;
}