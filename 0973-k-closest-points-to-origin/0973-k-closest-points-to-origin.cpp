class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<pair<int,int>> distIdx;

        // Store {distance, index}
        for(int i = 0; i < points.size(); i++) {

            int dist = points[i][0] * points[i][0]
                     + points[i][1] * points[i][1];

            distIdx.push_back({dist, i});
        }

        // Min heap
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap(distIdx.begin(), distIdx.end());

        vector<vector<int>> ans;

        // Take k closest points
        for(int i = 0; i < k; i++) {

            int idx = minHeap.top().second;

            ans.push_back(points[idx]);

            minHeap.pop();
        }

        return ans;
    }
};