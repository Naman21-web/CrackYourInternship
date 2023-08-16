void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1) matrix[i][j]=1e9;
	        }
	    }
	    vector<vector<int>> dist=matrix;
	    for(int k=0;k<n;k++){
    	    for(int i=0;i<n;i++){
    	        for(int j=0;j<n;j++){
    	            if(dist[i][k]+dist[k][j]<dist[i][j]){
    	                dist[i][j] = dist[i][k]+dist[k][j];
    	            }
    	        }
    	    }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(dist[i][j]>=1e9) dist[i][j]=-1;
	        }
	    }
	    matrix=dist;
	}