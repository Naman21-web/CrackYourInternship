class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        if(n==0) return m;
        unordered_map<char,int> mp;
        int maxi=0;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
            maxi=max(mp[tasks[i]],maxi);
        }
        int slot=maxi-1;
        int idle = (n+1)*(slot);
        cout<<idle<<" ";
        for(auto x:mp){
            idle -= min(slot,x.second);
            cout<<idle<<" ";
        }
        cout<<m;
        return m + max(0,idle);
    }
};
