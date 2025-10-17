//need user and comments details for comments

#include <bits/stdc++.h>
using namespace std;
class User
{
    public:
    int id;
    string name;
    User(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
};
class Comment
{
    public:
    int id;
    string comment;
    Comment(int id, string comment)
    {
        this->id = id;
        this->comment = comment;
    }
};


class FacebookManager
{
    public:
    vector<User> users;
    vector<Comment> comments;
    FacebookManager()
    {
        
    }
    void addUser(int id, string name)
    {
        users.push_back(User(id,name));
    }
    void addComment(int id, string comment)
    {
        comments.push_back(Comment(id,comment));

    }
    void removeUser(int id)
    {
        users.erase(users.begin() + id);
    }
    void removeComment(int id)
    {
        comments.erase(comments.begin() + id);
    }
    void getUser(int id)
    {
        cout<<users[id].name<<endl;
    }
    void getComment(int id)
    {
        cout<<comments[id].comment<<endl;
    }
    void getAllUsers()
    {
        if(users.size()==0)
        {
            cout<<"No users"<<endl;
            return;
        }
        for(int i=0;i<users.size();i++)
        {
            cout<<users[i].name<<" ";
        }
        cout<<endl;
    }
    void getAllComments()
    {
        if(comments.size()==0)
        {
            cout<<"No comments"<<endl;
            return;
        }
        for(int i=0;i<comments.size();i++)
        {
            cout<<comments[i].comment<<" ";
        }
        cout<<endl;
    }
};


int main()
{
    FacebookManager fb;
    fb.addUser(1,"Alok");
    fb.addUser(2,"Bharath");
    fb.addComment(1,"Hello");
    fb.addComment(2,"Hi");
    fb.getAllUsers();
    fb.getAllComments();
    fb.getUser(1);
    fb.getComment(1);
    fb.removeUser(1);
    fb.removeComment(1);
    fb.getAllUsers();
    fb.getAllComments();
    return 0;
}