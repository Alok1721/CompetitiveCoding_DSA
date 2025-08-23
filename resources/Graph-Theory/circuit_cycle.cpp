class Solution {
    public:
        bool isCircle(vector<string>& arr) {
            unordered_map<char,int> inDeg, outDeg;
            unordered_map<char, vector<char>> graph;
            unordered_set<char> chars; // set of all characters involved
    
            for(auto &s: arr) {
                char u = s[0];
                char v = s.back();
                outDeg[u]++;
                inDeg[v]++;
                graph[u].push_back(v);
                chars.insert(u);
                chars.insert(v);
            }
    
            // 1. Check in-degree = out-degree for all chars
            for(char c: chars) {
                if(inDeg[c] != outDeg[c]) return false;//!cycle present but not sure about it will cover all the node of graph or not

            }
    
            // 2. Check connectivity (DFS)
            unordered_set<char> visited;//!all nodes are visited or not
            function<void(char)> dfs = [&](char u){
                visited.insert(u);
                for(char v: graph[u]) {
                    if(!visited.count(v)) dfs(v);
                }
            };
    
            dfs(arr[0][0]); // start DFS from first string's first char
            return visited.size() == chars.size(); // all chars reachable?
        }
    };
    