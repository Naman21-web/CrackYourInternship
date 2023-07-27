class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int result=0;
        for(char ch='A';ch<='Z';ch++){
            int start=0,end=0;
            int ans=0,cnt=0;
            while(end<n){
                if(s[end]!=ch) cnt++;
                while(cnt==k+1){
                    if(s[start]!=ch) cnt--;
                    start++;
                }
                end++;
                ans = max(ans,end-start);
            }
            result = max(result,ans);
        }
        return result;
    }
};