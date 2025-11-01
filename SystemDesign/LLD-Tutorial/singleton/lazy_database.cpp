#include<bits/stdc++.h>
using namespace std;
//*singleton design pattern
class Database
{
    private:
    static Database* instance;//single instance shared among each object
    Database(){};
    vector<string>records;
public:
    // Database(const Database& other) = delete;
    static Database* get_instance()
    {
        if(instance==NULL)
        {
            instance=new Database();
        }
        return instance;
    }
    void connect()
    {
        cout<<"Connected to database"<<endl;
    }
    
    void disconnect()
    {
        cout<<"Disconnected from database"<<endl;
    }

    void add_record(string record)
    {
        records.push_back(record);
    }
    void delete_record(string record)
    {
        records.erase(records.begin(),records.end());
    }
    void get_records()
    {
        for(auto record:records)
        {
            cout<<record<<endl;
        }
    }
    
};

Database* Database::instance=NULL;

int main()
{
    Database *db=Database::get_instance();
    Database *db2=Database::get_instance();
    db->connect();
    db->add_record("record1");
    // db->delete_record("record1");
    db2->connect();
    db2->add_record("record2");
    // db2->delete_record("record2");
    db->get_records();
    db->disconnect();
    db2->disconnect();
    return 0;
}