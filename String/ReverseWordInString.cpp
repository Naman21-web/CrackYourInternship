class Solution {
public:
    string reverseWords(string s) {
        string a;
        int n = s.size();
        stack<string> st;
        for(int i=0;i<n;i++){
            if(s[i]==' ' && a!=""){
                st.push(a);
                a="";
            }
            else if(s[i]!=' ') a += s[i];
        }
        if(a!="") st.push(a);
        a="";
        while(!st.empty()){
            a += st.top();
            a += " ";
            st.pop();
        }
        a.pop_back();
        return a;
    }
};