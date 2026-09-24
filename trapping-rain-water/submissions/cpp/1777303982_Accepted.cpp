class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int prefixmax[n];
        prefixmax[0]=height[0];
        for(int i=1;i<=n-1;i++){
            prefixmax[i]=max(prefixmax[i-1],height[i]);
        }
        int suffixmax[n];
        suffixmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffixmax[i]=max(suffixmax[i+1],height[i]);
        }
        int total=0;
        for(int i=0;i<=n-1;i++){
            if(height[i]<prefixmax[i] && height[i]<suffixmax[i]){
                total=total+min(prefixmax[i],suffixmax[i])-height[i];
            }
        }
        return total;
    }
};