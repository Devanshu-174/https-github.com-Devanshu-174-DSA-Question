class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> ans(score.size());
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<n;i++){
            pq.push({score[i],i}); //value,idx dont write idx,score[i] then it will take i as a priority factor
        }

        for(int i=0;i<n;i++){
            auto top=pq.top();
            pq.pop();

            int idx=top.second;
            if(i==0){
                ans[idx]="Gold Medal";
            }
            else if(i==1){
                ans[idx]="Silver Medal";
            }
            else if(i==2){
                ans[idx]="Bronze Medal";
            }
            else{
                ans[idx]=to_string(i+1);
            }
        }
        return ans;
    }
};