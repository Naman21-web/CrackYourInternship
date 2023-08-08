class Solution {
  public:
    bool isPalindrome(int i,int j,string s){
        while(i<j && s[i]==s[j]){
            i++;
            j--;
        }
        if(s[i]==s[j]) return true;
        return false;
    }
    void solve(int i,string s,int n,vector<string> &temp,vector<vector<string>> &ans){
        if(i==n){
           ans.push_back(temp);
           return;
        }
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,s,n,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        int n=S.size();
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,S,n,temp,ans);
        return ans;
    }
};