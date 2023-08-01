class Solution {
public:
    int minDeletions(string s) {
        /*
        int n=s.size();
        map<char,int,greater<int>> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<int> vis(n+1,0);//as max freq of any element can be n
        for(auto x:mp){
            vis[x.second]++;//count of freq at particular value
        }
        int ans=0;
        queue<int> q;
        for(int i=n;i>=0;i--){
            if(!vis[i]){//If no element has this freq
                if(!q.empty()){
                    ans += (q.front()-i);//Then make freq of element present at top of queue to this
                    //q.front()-i deletion
                    q.pop();
                    vis[i]=1;
                }
            }
            if(vis[i]==1) continue;//only 1 element present at this freq so no need to do anything
            for(int j=1;j<vis[i];j++) q.push(i);//only 1 ele at this freq rest push in queue to make deletions on that
        }
        while(!q.empty()){
            ans += q.front();//make freq of remaining ele 0 thatswhy adding whole q.front() in it
            q.pop();
        }
        return ans;
        */
        int n=s.size();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int totdel=0;
        sort(freq.begin(),freq.end());
        for(int i=24;i>=0;i--){
            if(freq[i]==0) break;
            int prev = freq[i];
            int del = max(0,freq[i+1]-1);
            if(del<freq[i]){
                freq[i]=del;
                totdel += prev-del;
            }
        }
        return totdel;
    }
};