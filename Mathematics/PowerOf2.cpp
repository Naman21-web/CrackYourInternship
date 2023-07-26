class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if(n<=0) return false;
        // if(n==1) return true;
        // if(n%2 !=0 && n!=1) return false;
        // return isPowerOfTwo(n/2);
        if(n<0) return 0;
        if(n==0) return 0;
        return !(n&(n-1));
    }
};