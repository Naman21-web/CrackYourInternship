class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans; 
        while(columnNumber>0){
            int x = columnNumber%26;
            if(x==0) {
                x=26;
                columnNumber--;//so that when divide by 26 give correct ans
            }
            ans += (char)(x+64);
            if(columnNumber<27) break;//No further no possible
            columnNumber = columnNumber/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};