class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n=adjacentPairs.size();
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<n;i++){
            graph[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            graph[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);       
        }
        vector<int> ans;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(graph[adjacentPairs[i][0]].size()==1){
                q.push({adjacentPairs[i][0],-1});
                break;
            }
            if(graph[adjacentPairs[i][1]].size()==1){
                q.push({adjacentPairs[i][1],-1});
                break;
            }
        }
        // cout<<q.front().first;
        while(!q.empty()){
            int node=q.front().first;
            int parent = q.front().second;
            // cout<<node<<parent<<" ";
            q.pop();
            ans.push_back(node);
            for(auto neighbour:graph[node]){
                if(neighbour!=parent){
                    q.push({neighbour,node});
                }
            }
        }      
        return ans;
    }
};