class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(int i,string str,int k,int n,string &ans){
        if(k==0 || i==n){
            ans = max(ans,str);
            return;
        }
        for(int j=i+1;j<n;j++){
            if(str[j]>str[i]){
                swap(str[j],str[i]);
                solve(i+1,str,k-1,n,ans);
                swap(str[j],str[i]);
            }
        }
        solve(i+1,str,k,n,ans);
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       int n = str.size();
       string ans=str;
       solve(0,str,k,n,ans);
       return ans;
    }
};