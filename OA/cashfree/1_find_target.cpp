#include<bits/stdc++.h>
using namespace std;

int findMinSteps(int target)
{

    queue<pair<int,int>>q;
    q.push({0,0}); //{position,steps}
    set<int>s;
    s.insert(0);
    while(!q.empty())
    {
        auto curr=q.front();
        q.pop();
        int pos=curr.first;
        int step=curr.second;
        if(pos==target)
        {
            return step;
        }
        for(int i=-1;i<=1;i+=2)
        {
            int newPos=pos+(step+1)*i;
            if(s.find(newPos)==s.end() && newPos>=-1000 && newPos<=1000)
            {
                s.insert(newPos);
                q.push({newPos,step+1});
            }
        
        }
    }
    return -1;
}



int main()
{
    int target;
    cin >> target;
    cout<<findMinSteps(target)<<endl;
    return 0;
}