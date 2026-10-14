class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for(int gift:gifts){
            pq.push(gift);
        }

        int i=1;
        while(i<=k){
            int top=pq.top();
            pq.pop();

            int x=sqrt(top);
            pq.push(x);
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