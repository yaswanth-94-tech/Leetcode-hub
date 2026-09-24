class Solution {
public:
    bool checkOverlap(int radius, int xcenter, int ycenter, int x1, int y1,
                      int x3, int y3) {
        int x2 = x1;
        int y2 = y3;
        int x4 = x3;
        int y4 = y1;
        int xll = max(x1, min(xcenter, x3));
        int yll = max(y1, min(ycenter, y3));
        double distance = sqrt(pow(xll - xcenter, 2) + pow(yll - ycenter, 2));

        if (distance <= radius)
            return true;
        else
            return false;
    }
};