#include <bits/stdc++.h>
using namespace std;

vector<long long> findShoeShuffles(vector<int>&a)
{
    int n=a.size();
    //a vector in place-> collect the rotated shoe sizes of same window size
    unordered_map<int, int> shoeFreq;
    vector<int> result;
    // Step 1: Count the frequency of each shoe size
    for(int i=0; i<n; i++)
    {
        shoeFreq[a[i]]++;
    }

    for(auto i:shoeFreq)
    {
        if(i.second ==1) // If a shoe size appears more than once
        {
            return {};
        }
    }

    vector<long long> students(n);
    for(int i=0; i<n; i++)
    {
        students[i] = i+1;
    }

    long long l=0,r=0;

    while(r<n)
    {
        if(a[l]==a[r])
        {
            r++;
        }
        else
        {
            rotate(students.begin() + l, students.begin() + l+1, students.begin() + r );
            l=r;
        }
    }

    rotate(students.begin() + l, students.begin() + l+1, students.begin() + r );
    return students; // return the final arrangement of students
    
}



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<long long> result=findShoeShuffles(a);
        
        if(result.empty())
        {
            cout<<-1<<endl;
        }
        else
        {
            for(int i=0;i<result.size();i++)
            {
                cout<<result[i]<<" ";
            }
            cout<<endl;
        }
       
    }
    return 0;
}