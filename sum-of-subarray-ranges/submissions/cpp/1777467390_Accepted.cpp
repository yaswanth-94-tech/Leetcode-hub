class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long answer=0;
        for (int i = 0; i <= n - 1; i++) {
            int largest = nums[i];
            int smallest = nums[i];
            for (int j = i + 1; j <= n - 1; j++) {
                largest=max(largest,nums[j]);
                smallest=min(smallest,nums[j]);
                answer=answer+(largest-smallest);
            }
        }
        return answer;
    }
};