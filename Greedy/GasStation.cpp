class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans =  0;
        int mini = INT_MAX;
        int sum = 0;
        int n=gas.size();
       for(int i=0;i<n;i++){
           int y = gas[i]-cost[i];
           sum += y;
           if(sum<mini){
               mini = sum;
               ans = (i+1)%n;//index jha se sum badhna chalu hua
               //agar ye index se bhi sum nhi badhega to agle iteration m  waapis value change hoke i+1 ho jaegi
               //aur agar kisi index p sum isse bhi kam hua to i+1 ans h jaega
           }
       }
       //agar final ans negative hua matlab soln exist nhu karta
       if(sum<0) return -1;
       return ans;
    }
};