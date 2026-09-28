class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        // Min-heap:
        // first  -> number of soldiers
        // second -> row index
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        for (int i = 0; i < mat.size(); i++) {
            int count = 0;

            for (int j = 0; j < mat[i].size() && mat[i][j] == 1; j++) {
                count++;
            }

            pq.push({count, i});
        }

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};