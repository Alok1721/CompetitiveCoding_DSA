#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;



int main()
{
    int t;
    t=1;
    while(t--)
    {
       int x,n;
       cin>>x>>n;
       set<int> position;
       
       //inserting the gap in which we have to install the traffic light
        position.insert(0);
        position.insert(x);
        
        //multiset to store the length in increasing order
        multiset<int> length;
        length.insert(x-0);

        for(int i=0;i<n;i++)
        {
            int no;
            cin>>no;

            // position.insert(no);
            auto it=position.insert(no).first;
            int previousPos=*prev(it);
            int nextPos=*next(it);
            length.erase(length.find(nextPos-previousPos));
            length.insert(no-previousPos);
            length.insert(nextPos-no);

            cout<<*length.rbegin()<<" ";
        }
        cout<<endl;

    }
    return 0;
}