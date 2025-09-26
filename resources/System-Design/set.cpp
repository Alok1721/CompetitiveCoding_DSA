#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node*left;
    Node*right;
    Node(int x)
    {
        val=x;
        left=NULL;
        right=NULL;
    }
};


class MySet{
    Node*root;
    Node* insert(Node*root,int x)
    {
        if(!root)
        {
            root=new Node(x);
        }
        else if(x<root->val)
        {
            root->left=insert(root->left,x);
        }
        else if(x>root->val)
        {
            root->right=insert(root->right,x);
        }
        return root;
    }
    void display(Node*root)
    {
        if(!root)
        {
            return;
        }
        display(root->left);
        cout<<root->val<<" ";
        display(root->right);
    }
    Node*findMin(Node*root)
    {
        while(root && root->left)
        {
            root=root->left;
        }
        return root;
    }
    Node* erase(Node*root,int x)
    {
        if(!root)return NULL;
        else if(x<root->val)
        {
            root->left=erase(root->left,x);
        }else if(x>root->val)
        {
            root->right=erase(root->right,x);
        }
        else
        {
            //3 case for erase
            if(!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            else if(!root->left)
            {
                Node*temp=root->right;
                delete root;
                return temp;
            }
            else if(!root->right)
            {
                Node*temp=root->right;
                delete root;
                return temp;
            }
            else
            {
                Node*sucessor=findMin(root->right);
                root->val=sucessor->val;
                root->right=erase(root->right,sucessor->val);
                return root;
            }
        }
        return root;
    }
    public:
    MySet()
    {
        root=NULL;
    }
    void insert(int x){//overloading uses here
        root=insert(root,x);
    }
    void display(){//overloading uses here
        display(root);
    }
    void erase(int x)
    {
        root=erase(root,x);
    }
};


int main()
{
    MySet st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    st.display();
    cout<<"\n erasing 4 \n ";
    st.erase(4);
    st.display();

    return 0;
}