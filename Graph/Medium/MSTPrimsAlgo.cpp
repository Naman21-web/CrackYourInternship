int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        set<pair<int,int>> st;
        st.insert({0,0});
        int cost=0;
        vector<int> vis(V,0);
        while(!st.empty()){
            auto it = *st.begin();
            int node=it.second;
            int dist = it.first;
            st.erase(*st.begin());
            if(vis[node]) continue;
            cost += dist;
            vis[node]=1;
            for(auto neighbour:adj[node]){
                if(!vis[neighbour[0]]){
                    st.insert({neighbour[1],neighbour[0]});
                }
            }
        }
        return cost;
    }