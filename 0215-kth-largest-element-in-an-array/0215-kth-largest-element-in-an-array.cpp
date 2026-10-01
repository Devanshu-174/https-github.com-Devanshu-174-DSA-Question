class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int i=0;
        int n=nums.size();

        while(i<n){
            if(pq.size()==k &&pq.top()<nums[i]){
                pq.pop();
            }
            
            if(pq.size()!=k){
                pq.push(nums[i]);
            }
            i++;
        }
        return pq.top();
    }
};