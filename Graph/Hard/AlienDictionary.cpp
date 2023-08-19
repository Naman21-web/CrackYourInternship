// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>> adj(K);
        for(int i=0;i<N-1;i++){
            for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++){
                if(dict[i][j]!=dict[i+1][j]){
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        string ans;
        vector<int> indeg(K,0);
        for(int i=0;i<K;i++){
            for(auto node:adj[i]){
                indeg[node]++;
            }
        }
        queue<int> q;
        for(int i=0;i<K;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans += 'a'+x;
            for(auto node:adj[x]){
                indeg[node]--;
                if(indeg[node]==0) q.push(node);
            }
        }
        return ans;
    }
};