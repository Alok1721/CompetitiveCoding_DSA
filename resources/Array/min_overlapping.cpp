int getMinOverlapping(vector<vector<int>>& points)
    {
        int n=points.size();
        if(n==1)return 0;
        auto prev=points[0];
        int count=0;

        for(int i=1;i<n;i++)
        {
            auto next=points[i];
            if(next[0]<=prev[1])
            {
                count++;
                if(next[1]<prev[1])
                {
                    prev=next;
                }
                continue;
            }
            prev=next;
        }
        return count;
    }