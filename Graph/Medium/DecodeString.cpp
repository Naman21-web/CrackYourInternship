class Solution {
public:
    string decodeString(string s) {
        // return "";
        int n = s.size();
        stack<string> st;
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]==']'){
                string temp;
                while(st.top()!="["){
                    temp = st.top()+temp;
                    st.pop();
                }
                st.pop();
                int no = stoi(st.top());
                st.pop();
                string res;
                for(int i=0;i<no;i++){
                    res += temp;
                }
                // cout<<res<<" ";
                st.push(res);
            }
            else{
                string temp;
                if(s[i]>='0' && s[i]<='9'){
                    while(s[i]>='0' && s[i]<='9')temp += s[i++];
                    i--;
                }
                else temp += s[i];
                // cout<<temp<<" ";
                st.push(temp);
            }
        }
        if(st.size()==1) return st.top();
        while(!st.empty()){
            ans = st.top()+ans;
            // cout<<ans<<" ";
            st.pop();
        }
        return ans;
    }
};