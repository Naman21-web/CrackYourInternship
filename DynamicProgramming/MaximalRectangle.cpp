class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxa=0,n=heights.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width=i;
                else width = i-st.top()-1;
                maxa=max(maxa,width*height);
            }
            st.push(i);
        }
        return maxa;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> dp(m,0);
        int maxa=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') dp[j]++;
                else dp[j]=0;
            }
            maxa = max(maxa,largestRectangleArea(dp));
        }
        return maxa;
    }
};