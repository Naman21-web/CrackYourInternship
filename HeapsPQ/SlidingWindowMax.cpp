vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < k; ++i)
        {
            pq.push({nums[i],i});
        }
        res.push_back(pq.top().first);
        for(int i = k; i < n; ++i)
        {
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second <= i-k)
                pq.pop();
            res.push_back(pq.top().first);
        }
        return res;
    }