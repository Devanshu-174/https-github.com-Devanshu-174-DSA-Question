class Solution {
public:

    class Compare {
public:
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        Compare> pq;
        
        unordered_map<int,int> freq;

        for(int i=0;i<nums.size();i++){
            if(freq.find(nums[i])==freq.end()){
                freq.insert(make_pair(nums[i],1));
            }
            else{
                freq[nums[i]]++;
            }
        }

        for(const auto& [num, count] : freq){
            if(pq.size() == k && count > pq.top().second) {
                pq.pop();
            }

            if(pq.size()!=k){
                pq.push({num,count});
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};