int mini=INT_MAX;
void findDiff(int i,int arr[],int n,int size,int ele,int sum,int totalSum){
    if(i==n) return;
    if(ele==size){
        mini = min(min,totalSum-sum);
        return;
    }
    findDiff(i+1,arr,n,size,ele,sum,totalSum);
    findDiff(i+1,arr,n,size,ele+1,sum+arr[i],totalSum);
}
int findMinDiff(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++) sum += arr[i];
    findDiff(0,arr,n,n/2,0,0,sum);
    return mini;
}