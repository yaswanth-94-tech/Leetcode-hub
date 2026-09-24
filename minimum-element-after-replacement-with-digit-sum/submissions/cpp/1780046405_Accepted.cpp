class Solution {
public:
    int minElement(vector<int>& nums) {
        int size=nums.size();
        vector<int> sohan;
        int sum;
        for (int i = 0; i < size; i++) {
            sum = 0;
            while (nums[i] > 0) {
                sum = sum + nums[i] % 10;
                nums[i] = nums[i] / 10;
            }
            sohan.push_back(sum);
        }
        return *min_element(sohan.begin(), sohan.end());
    }
};