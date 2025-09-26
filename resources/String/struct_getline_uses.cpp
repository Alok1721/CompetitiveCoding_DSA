struct T
{
    string city,name,original;
    int price,time;
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n=transactions.size();
        vector<T>trans;
        vector<int>invalid(n,false);
        for(auto t:transactions)
        {
            stringstream ss(t);
            string name,time,city,price;
            getline(ss,name,',');
            getline(ss,time,',');
            getline(ss,price,',');
            getline(ss,city,',');

            trans.push_back({city,name,t,stoi(price),stoi(time)});
        }

        for(int i=0;i<n;i++)
        {
            auto tt1=trans[i];
            if(tt1.price>1000) invalid[i]=true;
            for(int j=0;j<n;j++)
            {
                auto tt2=trans[j];
                if(i==j)continue;
                if(tt2.name==tt1.name && tt1.city!=tt2.city && abs(tt2.time-tt1.time)<=60)
                {
                    invalid[i]=true;
                    invalid[j]=true;
                }
            }
        }
        vector<string>result;
        for(int i=0;i<n;i++)
        {
            auto tt=trans[i];
            if(invalid[i])result.push_back(tt.original);
        }
        return result;
    }
};