class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int size = nums.size();
        int left[size];
        int right[size];
        left[0] = 0;
        for (int i = 1; i < size; i++) {
            left[i] = nums[i - 1] + left[i - 1];
        }
        right[size - 1] = 0;
        for (int i = size - 2; i >= 0; i--) {
            right[i] = nums[i + 1] + right[i + 1];
        }
        vector<int> answer(size);
        for (int i = 0; i < size; i++) {
            answer[i] = abs(left[i] - right[i]);
        }
        return answer;
    }
};
