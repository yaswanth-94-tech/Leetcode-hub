class Solution {
public:
    vector<string> ans;
    void get(string num,int n){
        if(num.size()==n){
            ans.push_back(num);
            return;
        }
        if(num.back()=='0'){
            get(num+'1',n);
        }
        else{
            get(num+'1',n);
            get(num+'0',n);
        }
    }
    vector<string> validStrings(int n) {
        get("0",n);
        get("1",n);
        return ans;
    }
};