class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        if(s.size()==0){
            return 0;
        }
        int count=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            if(i>=g.size()){
                return count;
            }
            if(s[j]>=g[i]){
                i++;
                count++;
            }
        }
        return count;
    }
};