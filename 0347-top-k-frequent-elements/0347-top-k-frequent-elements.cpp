class Solution {
public:

    class Compare {
public:
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
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

        for(auto f : freq){
            pq.push({f.first,f.second});
        }

        int i=1;
        vector<int> ans;
        while(i<=k){
            ans.push_back(pq.top().first);
            pq.pop();
            i++;
        }
        return ans;
    }
};