class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string v = s;
        reverse(v.begin(),v.end());
        if(v==s){
            return true;
        }
        return false;
    }
};