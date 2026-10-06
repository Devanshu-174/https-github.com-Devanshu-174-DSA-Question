class Solution {
public:

class compare{
public:
    bool operator()(pair<string,int> p1,pair<string,int> p2){
        if(p1.second==p2.second){
            return p1.first < p2.first;
        }
        return p1.second>p2.second;
    }
};

    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<
        pair<string,int>,
        vector<pair<string,int>>,
        compare> pq;
        
        unordered_map<string,int> freq;

        for(int i=0;i<words.size();i++){
            if(freq.find(words[i])==freq.end()){
                freq.insert(make_pair(words[i],1));
            }
            else{
                freq[words[i]]++;
            }
        }

        for(const auto& [word, count] : freq){
            if  (pq.size() == k &&
                (count > pq.top().second ||
                (count == pq.top().second && word < pq.top().first))) {
                    pq.pop();
        }

            if(pq.size()!=k){
                pq.push({word,count});
            }
        }
        
        vector<string> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};