class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        // Elements left in the stack have no next greater element
        while (!st.empty()) {
            mp[nums2[st.top()]] = -1;
            st.pop();
        }

        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};