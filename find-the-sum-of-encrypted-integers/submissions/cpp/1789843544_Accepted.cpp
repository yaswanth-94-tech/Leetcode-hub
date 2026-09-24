class Solution {
public:
    int enc(int n){
        int size=to_string(n).size();
        int temp=n;
        int m=0;
        while(temp>0){
            m=max(m,temp%10);
            temp=temp/10;


        }
        int result=m;
        for(int i=1;i<size;i++){
            result=m+result*10;
        }
        return result;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        for(int &it:nums){
            int temp=enc(it);
            it=temp;
        }
        int sum=0;
        for(auto it:nums){
            sum=sum+it;
        }
        return sum;
    }
};