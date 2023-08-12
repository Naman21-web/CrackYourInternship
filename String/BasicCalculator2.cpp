class Solution {
public:
    // int calculate(string s) {
    //     int n=s.size();
    //     stack<string> st;
    //     int i=0;
    //     while(i<n){
    //         if(s[i]==' ') i++;
    //         else if(s[i++]=='+' || s[i++]=='-'){
    //             string temp;
    //             temp += s[i++];
    //             st.push(temp);
    //         }
    //         else if(s[i]=='*' || s[i]=='/'){
    //             string exp;
    //             exp += s[i++];
    //             string temp1 = st.top();
    //             st.pop();
    //             string temp2;
    //             while(s[i]==' ') i++;
    //             while(i<n && s[i]>='0' && s[i]<='9'){
    //                 temp2 += s[i++];
    //             }
    //             int num1 = stoi(temp1);
    //             int num2 = stoi(temp2);
    //             int resnum;
    //             if(exp=="*") resnum = num1*num2;
    //             else resnum=num1/num2;
    //             st.push(to_string(resnum));
    //         }
    //         else{
    //             string temp;
    //             while(i<n && s[i]>='0' && s[i]<='9'){
    //                 temp += s[i++];
    //             }
    //             st.push(temp);
    //         }
    //     }
    //     while(st.size()!=1){
    //         string s1 = st.top();st.pop();
    //         string exp;
    //         exp += st.top();st.pop();
    //         string s2 = st.top();st.pop();
    //         int num1 = stoi(s1);
    //         int num2 = stoi(s2);
    //         int resnum;
    //         if(exp=="+") resnum = num1+num2;
    //         else resnum = num2-num1;
    //         st.push(to_string(resnum));
    //     }
    //     return stoi(st.top());
    // }
    int calculate(string s) {
        int n=s.size();
        stack<int> st;
        int i=0;
        bool pos=true;
        while(i<n){
            if(s[i]==' ') i++;
            else if(s[i]=='+' || s[i]=='-'){
                if(s[i++]=='+') pos=true;
                else pos=false;
            }
            else if(s[i]=='*' || s[i]=='/'){
                string exp;
                exp += s[i++];
                int num1 = st.top();
                st.pop();
                string temp2;
                while(s[i]==' ') i++;
                while(i<n && s[i]>='0' && s[i]<='9'){
                    temp2 += s[i++];
                }
                int num2 = stoi(temp2);
                int resnum;
                if(exp=="*") resnum = num1*num2;
                else resnum=num1/num2;
                st.push(resnum);
            }
            else{
                string temp;
                while(i<n && s[i]>='0' && s[i]<='9'){
                    temp += s[i++];
                }
                int num = stoi(temp);
                if(!pos) num=-num;
                st.push(num);
            }
        }
        while(st.size()!=1){
            int num1 = st.top();st.pop();
            int num2 = st.top();st.pop();
            int resnum=num1+num2;
            st.push(resnum);
        }
        return st.top();
    }
};


vector<int> l(n,0),ud(2*n-1,0),ld(2*n-1,0);
fot(int i=0;i<n;i++){
    if(l[row]==0 && ld[row+col]==0 && ud[row-col+n-1]==0){
        l[row]=1;
        ld[row+i]=1;
        ud[row-i+n-1]=1;
    }
    else return false;
}