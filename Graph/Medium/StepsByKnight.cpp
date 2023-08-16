	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    if(KnightPos==TargetPos) return 0;
	    vector<int> y = {-2,-2,-1,-1,1,1,2,2};
	    vector<int> x = {-1,1,-2,2,-2,2,-1,1};
	    vector<vector<int>> vis(n+1,vector<int> (n+1,0));
	    int targetx = TargetPos[0];
	    int targety = TargetPos[1];
	    int cnt=-1;
	    queue<pair<int,int>> q;
	    vis[KnightPos[0]][KnightPos[1]]=1;
	    q.push({KnightPos[0],KnightPos[1]});
	    while(!q.empty()){
	        cnt++;
	        int sz = q.size();
	        for(int i=0;i<sz;i++){
	            int row = q.front().first;
	            int col = q.front().second;
	           // cout<<row<<col<<" ";
	            q.pop();
	            for(int k=0;k<8;k++){
	                int newr = row+x[k];
	                int newc = col+y[k];
	               // cout<<newr<<newc<<" ";
	                if(newr>0 && newc>0 && newr<n+1 && newc<n+1 && !vis[newr][newc]){
	                   // cout<<"here"<<" ";
	                    if(newr==targetx && newc==targety) return cnt+1;
	                    vis[newr][newc]=1;
	                    q.push({newr,newc});
	                }
	            }
	        }
	    }
	    return -1;
	}