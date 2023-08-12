class Solution {
public:
    bool  check(int i,int j,string s){
        while(i<j && s[i]==s[j]){
            i++;
            j--;
        }
        if(s[i]==s[j]) return true;
        return false;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        bool deleted=false;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
               if(!deleted){
                   deleted=true;
                   bool ans=false;
                    if(s[i+1]==s[j]) ans = ans || check(i+1,j,s);
                    if(s[i]==s[j-1]) ans = ans || check(i,j-1,s);
                    return ans;
                }
                else return false;
            }
        }
        return true;
    }
};