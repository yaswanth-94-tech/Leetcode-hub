class Solution {
public:
    int n;
    string stack;
    vector<string>res;

    void backtrack(int open,int close,int n){
        if(open==close && close==n){
            res.push_back(stack);
            return;
        }
        if(open<n){
            stack.push_back('(');
            backtrack(open+1,close,n);
            stack.pop_back();
        }
        if(close<open){
            stack.push_back(')');
            backtrack(open,close+1,n);
            stack.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        this->n=n;   
        backtrack(0,0,n);
        return res; 
    }
};