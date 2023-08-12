class NumMatrix {
public:
    vector<vector<int>> pref;
    int n,m;
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        pref.resize(n+1, vector<int>(m+1,0));
        // pref.resize(n , vector(m));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pref[i][j] = pref[i][j-1]+matrix[i-1][j-1]+pref[i-1][j]-pref[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=pref[row2+1][col2+1]-pref[row2+1][col1]-pref[row1][col2+1]+pref[row1][col1];
        return sum;
    }
};