int minSwaps(vector<int> &arr)
	{
	    // Code here
	    int n=arr.size();
        vector<pair<int, int>> newarr(n);
        for (int i = 0; i < n; i++) {
            newarr[i].first = arr[i];
            newarr[i].second = i;
        }
    
        sort(newarr.begin(), newarr.end());
    
        vector<bool> vis(n, false);
        int ans = 0;
    
        for (int i = 0; i < n; i++) {
            if (vis[i] || newarr[i].second == i)
                continue;
            int cycle_size = 0;
            int j = i;
            while (!vis[j]) {
                vis[j] = 1;
                j = newarr[j].second;
                cycle_size++;
            }
     
            if (cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }
     
        return ans;
	}