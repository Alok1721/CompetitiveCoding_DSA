#include<bits/stdc++.h>
using namespace std;



int solve(int budget,vector<vector<int>>books,int index,int hCount,int sCount)
{
    if(index==books.size()||budget==0)
    {
        if(hCount==0||sCount==0)
        {
            return -1e7;
        }
        return 0;
    }
    if(budget<0)
    {
        return -1e7;
    }
    int take=0,notTake=0;
    if(budget>=books[index][1])
    {
        if(books[index][2]==0)
        {
            take=books[index][0]+ solve(budget-books[index][1],books,index+1,hCount+1,sCount);
        }
        else
        {
            take=books[index][0]+ solve(budget-books[index][1],books,index+1,hCount,sCount+1);
        }   
    }
    notTake=solve(budget,books,index+1,hCount,sCount);
    return max(take,notTake);


}
int maxStarRating(int budget,vector<pair<int,int>>horror,vector<pair<int,int>>scifi)
{
    vector<vector<int>> books;
    for(auto it:horror)
    {
        books.push_back({it.first,it.second,0});//rating,cost,type
    }
    for(auto it:scifi)
    {
        books.push_back({it.first,it.second,1});
    }
    sort(books.begin(),books.end());
    return solve(budget,books,0,0,0);//budget,books,index,horrorCount,scifiCount
    
}
int main()
{

    int budget;
    cin>>budget;
    int hCount,dummyH;
    cin>>hCount>>dummyH;
    vector<pair<int,int>>horror(hCount);
    for(int i=0;i<hCount;i++)
    {
        int rating,cost;
        cin>>rating>>cost;
        horror[i]={rating,cost};//cost,rating
    }
    int sCount,dummyS;
    cin>>sCount>>dummyS;
    vector<pair<int,int>>scifi(sCount);
    for(int i=0;i<sCount;i++)
    {
        int rating,cost;
        cin>>rating>>cost;
        scifi[i]={rating,cost};
    }
    cout<<maxStarRating(budget,horror,scifi)<<endl;
    return 0;
}