class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        while(!pq.empty() && pq.top()<=0) pq.pop();
        if(pq.empty()) return 1;
        int top=0;
        while(!pq.empty()){
            while(!pq.empty() && pq.top()==top) pq.pop();
            if(pq.empty()) return top+1;
            int currtop = pq.top();
            // cout<<top<<currtop<<" ";
            pq.pop();
            if(currtop != top+1) return top+1;
            top = currtop;
        }
        return top+1;
    } 
};