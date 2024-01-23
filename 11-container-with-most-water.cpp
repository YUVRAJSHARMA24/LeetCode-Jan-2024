class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int s = 0, e = n-1, area = 0;
        while(s < e)
        {
            int maxArea = min(height[s], height[e]) * (e-s);
            area = max(maxArea, area);
            
            if(height[s] < height[e])
                s++;
            else
                e--;
        }
        
        return area;
    }
};
