class Solution {
public:
    // vector<int> nsle(vector<int> v){
    //     vector<int> s(v.size());
    //     stack<pair<int,int>> S;
    //     for(int i=0;i<v.size();i++){
    //         while (!S.empty() && S.top().first >= v[i])
    //         S.pop();
 
    //     // If all elements in S were greater than arr[i]
    //     if (S.empty())
    //         s[i]=-1;
    //     else  //Else print the nearest smaller element
    //         s[i]=S.top().second;
 
    //     // Push this element
    //     S.push({v[i],i});
    //     }
    //     return s;
    // }
    // vector<int> nsre(vector<int> v){
    //     vector<int> s(v.size());
    //     stack<pair<int,int>> S;
    //     for(int i=v.size()-1;i>=0;i--){
    //         while (!S.empty() && S.top().first >= v[i])
    //         S.pop();
 
    //     // If all elements in S were greater than arr[i]
    //     if (S.empty())
    //         s[i]=v.size();
    //     else  //Else print the nearest smaller element
    //         s[i]=S.top().second;
 
    //     // Push this element
    //     S.push({v[i],i});
    //     }
    //     return s;
    // }
    // int largestRectangleArea(vector<int>& heights) {
    //     int maxTillNow=INT_MIN;
    //     vector<int> nsl,nsr;
    //     nsl = nsle(heights);
    //     nsr = nsre(heights);
    //     for(int i=0;i<heights.size();i++){
    //         int s = nsl[i];
    //         int e = nsr[i];
    //         int x = e-s-1;
    //         int ans = heights[i]*x;
    //         maxTillNow = max(maxTillNow,ans);
    //     }
    //     return maxTillNow;
    // }

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
};