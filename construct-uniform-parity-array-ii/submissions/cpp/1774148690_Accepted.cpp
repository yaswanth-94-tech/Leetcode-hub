class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int n = nums1.size();

        int odd = 0, even = 0;
        int mn = *min_element(nums1.begin(), nums1.end());

        for (int x : nums1) {
            if (x % 2)
                odd++;
            else
                even++;
        }

        bool makeOdd = (odd >= 1);

        if (makeOdd) {
            for (int x : nums1) {
                if (x % 2 == 0) {

                    if (x <= mn)
                        return false;
                }
            }
            return true;
        }

        return true;
    }
};