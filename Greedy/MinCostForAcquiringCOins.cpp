int minCost(vector<int> &arr,int k){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int ans = (n+k)/(k+1);//ceil of n/k+1
    int cost=0;
    for(int i=0;i<ans;i++) cost += arr[i];
    return cost;
}