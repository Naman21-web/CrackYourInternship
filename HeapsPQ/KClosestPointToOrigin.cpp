class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<points.size();i++){
            int x = points[i][0]*points[i][0];
            int y = points[i][1]*points[i][1];
            double z = x+y;
            //z = sqrt((double) z);
            pq.push({z,i});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> s;
        while(!pq.empty()){
            int a = pq.top().second;
            pq.pop();
            s.push_back(points[a]);
        }
        return s;
    }
};