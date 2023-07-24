class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=INT_MIN;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++){
            mini = min(mini,prices[i]);
            maxProfit = max(maxProfit,prices[i]-mini);
        }
        if(maxProfit==INT_MIN) return 0;
        return maxProfit;
    }
};