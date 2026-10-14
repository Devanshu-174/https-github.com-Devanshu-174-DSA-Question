class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(),piles.end());

        int i=1;
        while(i<=k){
            int top=pq.top();
            pq.pop();

            int x=top/2;
            pq.push(top-x);
            i++;
        }

        long long int ans=0;
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();

            ans+=top;
        }

        return ans;
    }
};