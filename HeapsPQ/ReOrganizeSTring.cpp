class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto s:mp){
            cout<<s.second<<" ";
            pq.push({s.second,s.first});
        }
        string ans;
        while(!pq.empty()){
            int x = pq.top().first;
            char ch1 = pq.top().second;
            ans += ch1;
            x--;
            pq.pop();
            if(pq.empty() && x!=0) return "";
            if(x==0 && pq.empty()) return ans;
            int y=pq.top().first;
            char ch2 = pq.top().second;
            ans += ch2;
            y--;
            pq.pop();
            if(x!=0)pq.push({x,ch1});
            if(y!=0)pq.push({y,ch2});
        }
        return ans;
    }
};