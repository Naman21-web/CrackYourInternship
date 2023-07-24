class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int a=0,b=n-1,c=0,d=m-1;
        vector<int> v;
        int i=0,j=0;
        while(a<=b && c<=d){
            // while(j<d){
            //     v.push_back(matrix[i][j]);
            //     j++;
            // }
            // d--;
            // i++;
            for(int j=c;j<=d;j++){
                v.push_back(matrix[a][j]);
            }
            a++;
            // while(i<b){
            //     v.push_back(matrix[i][j]);
            //     i++;
            // }
            // b--;
            // j--;
            for(int i=a;i<=b;i++){
                v.push_back(matrix[i][d]);
            }
            d--;
            // if(a<=b){
            // while(j>=c){
            //     v.push_back(matrix[i][j]);
            //     j--;
            // }
            // c++;
            // i--;
            // }
            if(a<=b){
                for(int j=d;j>=c;j--){
                    v.push_back(matrix[b][j]);
                }
                b--;
            }
            // if(c<=d){
            // while(i>a){
            //     v.push_back(matrix[i][j]);
            //     i--;
            // }
            // a++;
            // j++;
            // }
            if(c<=d){
                for(int i=b;i>=a;i--){
                    v.push_back(matrix[i][c]);
                }
                c++;
            }
        }
        return v;
    }
};