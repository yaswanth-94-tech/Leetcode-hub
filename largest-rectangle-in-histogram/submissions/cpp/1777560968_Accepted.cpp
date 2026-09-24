class Solution {
public:
    vector<int> findnse(vector<int> heights){
        int n=heights.size();
        vector<int> result(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            result[i]=st.empty()? n:st.top();
            st.push(i);
        }
        return result;
    }
    vector<int> findpse(vector<int> heights){
        int n=heights.size();
        vector<int> result(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            result[i]=st.empty()? -1:st.top();
            st.push(i);
        }
        return result;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse=findnse(heights);
        vector<int> pse=findpse(heights);
        int n=heights.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(nse[i]-pse[i]-1)*heights[i]);
        }
        return maxi;
    }
};