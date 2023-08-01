int minCost(string &s,vector<int> &cost){
    int n=cost.size();
    int totcost=0;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            if(cost[i]<cost[i+1]){
                totcost += cost[i];
            }
            else{
                totcost += cost[i+1];
                cost[i+1] = cost[i];
            }
        }
    }
    return totcost;
}