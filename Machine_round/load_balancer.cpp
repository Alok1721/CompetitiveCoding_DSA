#include <bits/stdc++.h>
using namespace std;

struct Server {
    int id;
    int activeConnection;
    Server(int id = -1) : id(id), activeConnection(0) {}
};

class LoadBalancer {
public:
    vector<Server> servers;
    int currentIndex;//this index will change by different strategy

    LoadBalancer() : currentIndex(0) {}

    void addServer(int id) {
        servers.push_back(Server(id));
    }

    int getServerRoundRobin() {
        if (servers.empty()) return -1;
        int serverId = servers[currentIndex].id;
        currentIndex = (currentIndex + 1) % servers.size();
        return serverId;
    }

    int getServerByHashing(int clientId) {
        if (servers.empty()) return -1;
        return servers[clientId % servers.size()].id;
    }

    int getServerByLeastConnections() {
        if (servers.empty()) return -1;
        int minConnections = INT_MAX;
        int serverId = -1;
        for (auto &s : servers) {
            if (s.activeConnection < minConnections) {
                minConnections = s.activeConnection;
                serverId = s.id;
            }
        }
        return serverId;
    }

    void removeServer(int id) {
        servers.erase(remove_if(servers.begin(), servers.end(),
                     [id](const Server& s){ return s.id == id; }),
                     servers.end());
        if (!servers.empty()) currentIndex %= servers.size();
        else currentIndex = 0;
    }

    void addConnection(int id) {
        for (auto &s : servers) if (s.id == id) { s.activeConnection++; break; }
    }

    void removeConnection(int id) {
        for (auto &s : servers) if (s.id == id && s.activeConnection > 0) { s.activeConnection--; break; }
    }
};

int main() {
    LoadBalancer lb;
    lb.addServer(1);
    lb.addServer(2);
    lb.addServer(3);

    cout << "Round Robin: " << lb.getServerRoundRobin() << endl;
    cout << "Hashing: " << lb.getServerByHashing(101) << endl;

    lb.addConnection(1);
    lb.addConnection(1);
    lb.addConnection(2);
    cout << "Least Connections: " << lb.getServerByLeastConnections() << endl;

    lb.removeServer(2);
    cout << "After removing server 2 -> Round Robin: " << lb.getServerRoundRobin() << endl;
}
