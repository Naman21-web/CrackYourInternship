int evaluate(int num1,int num2,char op){
        if(op=='+') return num1+num2;
        else if(op=='-') return num1-num2;
        else if(op=='*') return num1*num2;
        else return num1/num2;
    }
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for(int i=0;i<S.size();i++){
            if(S[i]>='0' && S[i]<='9'){
                st.push(S[i]-'0');
            }
            else{
                int num2 = st.top();
                // cout<<num2<<" ";
                st.pop();
                int num1 = st.top();
                // cout<<num1<<" ";
                st.pop();
                st.push(evaluate(num1,num2,S[i]));
                // cout<<evaluate(num1,num2,S[i])<<" ";
            }
        }
        return st.top();
    }