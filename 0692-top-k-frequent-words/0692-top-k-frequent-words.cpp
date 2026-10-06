class Solution {
public:

class compare{
public:
    bool operator()(pair<string,int> p1,pair<string,int> p2){
        if(p1.second==p2.second){
            return p1.first > p2.first;
        }
        return p1.second<p2.second;
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

        for(auto f : freq){
            pq.push({f.first,f.second});
        }

        int i=1;
        vector<string> ans;
        while(i<=k){
            ans.push_back(pq.top().first);
            pq.pop();
            i++;
        }
        return ans;
    }
};