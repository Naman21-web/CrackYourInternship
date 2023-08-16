bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> graph(N);
	    vector<int> indeg(N,0);
	    for(int i=0;i<P;i++){
	        graph[prerequisites[i].second].push_back(prerequisites[i].first);
	        indeg[prerequisites[i].first]++;
	    }
	    queue<int> q;
	    vector<int> ans;
	    for(int i=0;i<N;i++){
	        if(indeg[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	        for(auto nodes:graph[node]){
	            indeg[nodes]--;
	            if(indeg[nodes]==0) q.push(nodes);
	        }
	    }
	    return ans.size()==N;
	}