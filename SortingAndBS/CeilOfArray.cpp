int ceilSearch(int arr[], int low, int high, int x)
{
     
    int ans=-1;
    while(low<hight){
        int mid = low + (high-low)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
    }  