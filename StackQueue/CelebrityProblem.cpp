//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        // for(int i=0;i<n;i++){
        //     int zero=0;
        //     for(int j=0;j<n;j++){
        //         if(i!=j && M[i][j]==0) zero++;
        //     }
        //     if(zero==n-1){
        //         int one=0;
        //         for(int k=0;k<n;k++){
        //             if(i!=k && M[k][i]==1) one++;
        //         }
        //         if(one==n-1) return i;
        //     }
        // }
        // return -1;
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()!=1){
            int i = st.top();
            st.pop();
            int j=st.top();
            st.pop();
            //i knows j that means i is not a celebrity as celebrity doesnt know anyone
            //j can be so push j
            if(M[i][j]==1){
                st.push(j);
            }
            //if i doesnt know j that means j is not a celebrity as everybody should know 
            //celebrity so push i as i can be celebrity
            else st.push(i);
        }
        //Now at last element remaining can be a celebrity it is not confirm it is celebrity
        //so we have to check it;
        int k=st.top();
        for(int i=0;i<n;i++){
            if(i!=k && M[i][k]==0) return -1;
            if(M[k][i]==1) return -1;
        }
        return k;
    }
};