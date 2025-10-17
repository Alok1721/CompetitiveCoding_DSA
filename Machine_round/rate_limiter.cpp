#include<bits/stdc++>
#include<chrono>
using namespace std;

class RateLimiterManager{
    private:
        struct clientData{
            string strategy_type;
        };
        unordered_map<string,ClientData>clients;
    public:
        void register_client(const string&client_id,string &strategy_type, int max_request,chrono::milliseconds window_rate)
        {
            if(client.find(client_id))
        }
};


int main()
{
    int max_request=10;//change this count for maximum request


    return 0;
}