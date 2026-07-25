class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> r(n);
        vector<int> l(n);
        stack<int> st;

        for(int j=0;j<n;j++){
            while(!st.empty() && heights[j]<=heights[st.top()]){
                r[st.top()]=j;
                st.pop();
            }
            st.push(j);
        }
        while(!st.empty()){
            r[st.top()]=n;
            st.pop();
        }

        for(int k=n-1;k>=0;k--){
            while(!st.empty() && heights[k]<heights[st.top()]){
                l[st.top()]=k;
                st.pop();
            }
            st.push(k);
        }
        while(!st.empty()){
            l[st.top()]=-1;
            st.pop();
        }

        int maxarea=0;
        for(int i=0;i<n;i++){
            int h=heights[i];
            int w=r[i]-l[i]-1;
            int area=h*w;
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};