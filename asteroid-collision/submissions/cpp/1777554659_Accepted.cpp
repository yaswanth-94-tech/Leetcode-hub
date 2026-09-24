class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                result.push_back(asteroids[i]);
            } else {
                while (!result.empty() && result.back()>0 && result.back() < abs(asteroids[i])) {
                    result.pop_back();
                }
                if (!result.empty()  &&
                    result.back() == abs(asteroids[i])) {
                    result.pop_back();
                } else if (result.empty() || result.back() < 0) {
                    result.push_back(asteroids[i]);
                }
            }
        }
        return result;
    }
};