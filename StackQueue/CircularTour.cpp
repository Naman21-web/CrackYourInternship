class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int ans=0;
       int mini = INT_MAX;
       int totsum=0;
       int sum=0;
       for(int i=0;i<n;i++){
           int y = p[i].petrol-p[i].distance;
           totsum += y;
           sum += y;
           if(sum<0){
               sum=0;
               ans = (i+1)%n;
           }
       }
       if(totsum<0) return -1;
       return ans;
    }
};