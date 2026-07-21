class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && nums2[i]>nums2[st.top()]){
                mp[nums2[st.top()]]=nums2[i];
                st.pop();
            }
            st.push(i);
        }

        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]==0){
                ans.push_back(-1);
            }
            else{
            ans.push_back(mp[nums1[i]]);
            }
        }
        return ans;
    }
};