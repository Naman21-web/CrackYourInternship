class Solution {
public:
    bool dfs(vector<unordered_set<int>> &gr, vector<bool> &vis, int s, int p)
    {
        // cout<<s;
        if(vis[s]) return true;
        vis[s] = true;
        for(auto e: gr[s])
        {   
            if(e!=p and dfs(gr, vis, e, s)) 
            return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<unordered_set<int>> gr(n+1);
        for(auto &v:edges)
        {
            gr[v[0]].insert(v[1]);
            gr[v[1]].insert(v[0]);
        }

        for(int i = n-1; i>=0;i--)
        {
            auto ed = edges[i];
            vector<bool> vis1(n+1, false);
            vector<bool> vis2(n+1, false);
            gr[ed[0]].erase(ed[1]);
            gr[ed[1]].erase(ed[0]);

            if(!dfs(gr, vis1, ed[0], 0) and !dfs(gr, vis2, ed[1], 0))
            return ed;

            gr[ed[0]].insert(ed[1]);
            gr[ed[1]].insert(ed[0]);
        }
        return {0,0};
    }
};