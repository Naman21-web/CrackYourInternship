int calccost(int arr[], int N, int X)
{
    int cost = 0;
    for (int i = 0; i < N; i++){
        int diff = arr[i] - X;
        if(diff<0) diff = -diff;
        cost += diff;
    }
    return cost;
}

int minCostToMakeElementEqual(int arr[], int N)
{    

    int lo=arr[0],hi=arr[0];
    for(int i=1;i<N;i++){
        if(lo>arr[i]) lo=arr[i];
        if(hi<arr[i]) hi=arr[i];
    }
    while((hi-lo)>2){
        int mid1 = lo + (hi-lo)/3;
        int mid2 = hi + (lo-hi)/3;

        int cost1 = calccost(arr,N,mid1);
        int cost2 = calccost(arr,N,mid2);

        if(cost1<cost2) hi=mid2;
        else lo=mid1;
    }
    return calccost(arr,N,(lo+hi)/2);
}