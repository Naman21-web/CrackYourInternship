class Solution {
public:
    vector<vector<string>> ans;
    bool check(int i,int j,string &s){
        while(i<j && s[i]==s[j]){
            i++;
            j--;
        }
        if(s[i]!=s[j]) return false;
        return true;
    }
    void plaindromePartition(int i,int n,vector<string> &temp,string s){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<n;j++){
            if(check(i,j,s)){
                string res=s.substr(i,j-i+1);
                temp.push_back(res);
                plaindromePartition(j+1,n,temp,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string> temp;
        plaindromePartition(0,n,temp,s);
        return ans;
    }
};