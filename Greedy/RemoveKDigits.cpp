class Solution {
public:
    string removeKdigits(string s, int k) {
        int n=s.size();
        stack<char> st;
        if(s[0]!='0') st.push(s[0]);
        for(int i=1;i<n;i++){
            if(s[i]>s[i-1]) st.push(s[i]);
            else{
                while(!st.empty() && s[i]<st.top() && k>0){
                    st.pop();
                    k--;
                }
                if(s[i]=='0' && !st.empty()) st.push(s[i]);
                else if(s[i]!='0') st.push(s[i]);
            }
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};