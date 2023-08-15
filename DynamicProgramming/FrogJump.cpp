class Solution {
public:
    // bool findAns(int i,vector<int>& stones,int prevjump,int n){
    //     if(i==n-1) return true;
    //     int curr=stones[i++];
    //     bool ans=false;
    //     while(i<n && stones[i]<=curr+prevjump+1){
    //         if(stones[i]==curr+prevjump+1){
    //             ans |= findAns(i,stones,prevjump+1,n);
    //         }
    //         else if(stones[i]==curr+prevjump-1){
    //             ans |= findAns(i,stones,prevjump-1,n);
    //         }
    //         else if(stones[i]==curr+prevjump){
    //             ans |= findAns(i,stones,prevjump,n);
    //         }
    //         i++;
    //     }
    //     return ans;
    // }

    // bool findAns(int i,vector<int>& stones,int prevjump,int n,map<pair<int,int>,int> &mp){
    //     if(i==n-1) return true;
    //     if(mp.find({i,prevjump})!=mp.end()) return mp[{i,prevjump}];
    //     int curr=stones[i++];
    //     bool ans=false;
    //     while(i<n && stones[i]<=curr+prevjump+1){
    //         if(stones[i]==curr+prevjump+1){
    //             ans |= findAns(i,stones,prevjump+1,n,mp);
    //         }
    //         else if(stones[i]==curr+prevjump-1){
    //             ans |= findAns(i,stones,prevjump-1,n,mp);
    //         }
    //         else if(stones[i]==curr+prevjump){
    //             ans |= findAns(i,stones,prevjump,n,mp);
    //         }
    //         i++;
    //     }
    //     return mp[{i,prevjump}]=ans;
    // }

    // bool findAns(int i,vector<int>& stones,int prevjump,int n,map<pair<int,int>,int> &mp){
    //     if(i==n-1) return true;
    //     if(mp.find({i,prevjump})!=mp.end()) return mp[{i,prevjump}];
    //     int curr=stones[i++];
    //     bool ans=false;
    //     while(i<n && stones[i]<=curr+prevjump+1){
    //         if(stones[i]==curr+prevjump+1){
    //             ans |= findAns(i,stones,prevjump+1,n,mp);
    //         }
    //         else if(stones[i]==curr+prevjump-1){
    //             ans |= findAns(i,stones,prevjump-1,n,mp);
    //         }
    //         else if(stones[i]==curr+prevjump){
    //             ans |= findAns(i,stones,prevjump,n,mp);
    //         }
    //         i++;
    //     }
    //     return mp[{i,prevjump}]=ans;
    // }

    bool findAns(int i,vector<int>& stones,int prevjump,int n,vector<vector<int>> &dp){
        if(i==n-1) return true;
        if((stones[i+1]-stones[i])>prevjump+1) return false;
        if(dp[i][prevjump]!=-1) return dp[i][prevjump];
        int curr=stones[i];
        int j=i;
        cout<<curr<<" ";
        j++;
        bool ans=false;
        while(j<n && stones[j]<=curr+prevjump+1){
            if(stones[j]==curr+prevjump+1){
                ans |= findAns(j,stones,prevjump+1,n,dp);
            }
            else if(stones[j]==curr+prevjump-1){
                ans |= findAns(j,stones,prevjump-1,n,dp);
            }
            else if(stones[j]==curr+prevjump){
                ans |= findAns(j,stones,prevjump,n,dp);
            }
            j++;
        }
        return dp[i][prevjump]=ans;
    }

    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1]!=1) return 0;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return findAns(1,stones,1,n,dp);
    }
};
