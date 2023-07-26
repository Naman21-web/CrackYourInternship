bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    int lo=0,hi=1;
    while(lo<n && hi<n){
        int diff = abs(arr[hi]-arr[lo]);
        if(lo!=hi && diff==n) return true;
        else if(arr[hi]-arr[lo]>n) lo++;
        else hi++;
    }
    return false;
}