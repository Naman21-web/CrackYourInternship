class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        unordered_map<char,int> mp1,mp2;
        int start=0,end=0;
        int cntchar=0;
        for(int i=0;i<m;i++){
            mp2[t[i]]++;
            if(mp2[t[i]]==1) cntchar++;
        }
        int cntdist=0;
        int ans1=0,ans2=INT_MAX;
        while(end<n){
            mp1[s[end]]++;
            if(mp1[s[end]]==mp2[s[end]]) cntdist++;
            while(cntdist==cntchar){
                if(end-start<ans2-ans1){
                    ans2=end;
                    ans1=start;
                }
                if(mp1[s[start]]==mp2[s[start]]){
                    cntdist--;
                }
                mp1[s[start]]--;
                start++;
            }
            end++;
        }
        if(ans2==INT_MAX) return "";
        return s.substr(ans1,ans2-ans1+1);
    }
};