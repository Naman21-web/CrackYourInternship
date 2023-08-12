class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1,-1);
        v[0]=0;
        for(int i=1;i<=n;i++){
            int cnt=0;
            int j=i;
            while(j!=0){
                if(v[j]!=-1){
                    cnt += v[j];
                    break;
                }
                j = j&(j-1);
                // cout<<i
                cnt++;
            }
            v[i]=cnt;
        }
        return v;
    }
};