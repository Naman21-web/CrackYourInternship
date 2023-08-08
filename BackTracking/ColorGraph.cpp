bool colorgraph(int i,int m,int n,vector<vector<int>> &graph,vector<int> &color){
        if(i==n) return true;
        if(color[i]==0){
            bool ans = false;
            for(int j=1;j<=m;j++){
                bool isSame=false;
                for(auto neighbour:graph[i]){
                    if(color[neighbour]==j){isSame=true; break;}
                }
                if(!isSame){
                    color[i]=j;
                    ans = ans || colorgraph(i+1,m,n,graph,color);
                    if(ans==true) return true;
                    color[i]=0;
                }
            }
            return ans;
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code 
        vector<vector<int>> newgraph(101);
        vector<int> color(n,0);
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                if(graph[i][j]==1) newgraph[i].push_back(j);
            }
        }
        return colorgraph(0,m,n,newgraph,color);    
    }