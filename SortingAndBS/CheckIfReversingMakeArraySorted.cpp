bool check(vector<int> arr){
    int n=arr.size();
    vector<int> temp=arr;
    sort(temp.begin(),temp.end());
    int lo=0;
    while(temp[lo]==arr[lo]) lo++;
    int hi=n-1;
    while(temp[hi]==arr[hi]) hi--;
    if(lo>=hi) return true;
    for(int i==lo;i<hi;i++){
        if(arr[i]<arr[i+1]) return false;
    }
    return true;
}