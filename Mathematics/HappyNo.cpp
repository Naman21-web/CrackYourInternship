class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        while(n!=1){
            if(mp.find(n)!=mp.end()) return 0;
            int sum = 0;
            mp[n]=1;
            while(n){
                int num = n%10;
                sum += num*num;
                n = n/10;
            }
            n = sum;
        }
        return 1;
    }
};