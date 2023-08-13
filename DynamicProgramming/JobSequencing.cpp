struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
class Solution 
{
    public:
    static bool mycmp(Job a,Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        
        
        vector<int>v;
        sort(arr,arr+n,mycmp);
        bool isvisited[n]={false};
        int res=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead-1;j>=0;j--){
                if(isvisited[j]==false){
                    isvisited[j]=true;
                    res+=arr[i].profit;
                    count++;
                    break;
                }
            }
            
            
        }
        v.push_back(count);
        v.push_back(res);
        
        
        return v;
        
    } 
};