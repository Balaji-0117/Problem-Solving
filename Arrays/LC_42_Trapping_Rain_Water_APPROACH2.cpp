class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxIdx = distance(height.begin(), max_element(height.begin(), height.end()));

        int leftMax = 0, area1 = 0;
        for(int i = 0; i < maxIdx; i++) {
            if(leftMax < height[i]) {
                leftMax = height[i]; 
            } else {
                area1 += leftMax - height[i];
            }
        }

        int rightMax = 0, area2 = 0;
        for(int i = n-1; i > maxIdx; i--) {
            if(rightMax < height[i]) {
                rightMax = height[i];
            } else {
                area2 += rightMax - height[i];
            }
        }
        return area1 + area2;
    }
};