class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // int n=manager.size();
        int head;
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(manager[i]==-1)head=i;
            else{
                graph[manager[i]].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        q.push({head,informTime[head]});
        int mintime=0;
        while(!q.empty()){
            int a=q.size();
            for(int i=0;i<a;i++){
                int node=q.front().first;
                int time=q.front().second;
                q.pop();
                for(auto x:graph[node]){
                    int y=informTime[x]+time;
                    mintime = max(mintime,y);
                    q.push({x,y});
                }
            }
        }
        return mintime;
    }
};