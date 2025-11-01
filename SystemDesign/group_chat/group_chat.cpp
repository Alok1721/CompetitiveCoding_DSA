#include<bits/stdc++.h>
using namespace std;
// !user :track users in groupchat
class User{
    static int id;
    public:
        string name;
        set<int>joinedGroups; //store group id
        User(string name)
        {
            this->name=name;
            this->id=id++;
        }
        bool canJoin()
        {
         return joinedGroups.size()<20;//can join only 20 groups at a time    
        }
        void joinGroup(int groupId)
        {
            joinedGroups.insert(groupId);
        }
};



int User::id=0;



int main(){

    return 0;
}
