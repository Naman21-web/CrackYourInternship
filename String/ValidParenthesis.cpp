class Solution {
public:
    bool isMatch(char open,char close){
        if((open=='(' && close==')') || (open=='{' && close=='}') || (open=='[' && close==']')) return true;
        return false;
    }
    bool isValid(string s) {
        if(s.size()==1) return false;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                if(st.empty()) return false;
                char open=st.top();
                st.pop();
                if(!isMatch(open,s[i])) return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};