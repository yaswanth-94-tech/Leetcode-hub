class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi=0;
        stack<int>st;
        st.push(-1);
        int n=s.size();
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                st.push(i);
            }
            else if(ch==')'){
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len=i-st.top();
                    maxi=max(maxi,len);
                }
            }
        }
        return maxi;
    }
};