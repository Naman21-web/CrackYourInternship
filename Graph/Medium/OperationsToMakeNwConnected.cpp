class Solution {
public:
    void cntDisconnected(int i,vector<vector<int>> &graph,vector<int> &vis){
        // vis[i]
        for(auto x:graph[i]){
            if(!vis[x]){
                vis[x]=1;
                cntDisconnected(x,graph,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                vis[i]=1;
                cntDisconnected(i,graph,vis);
                cnt++;
            }
        }
        if(connections.size()>=n-1) return cnt-1;
        return -1;
    }
};