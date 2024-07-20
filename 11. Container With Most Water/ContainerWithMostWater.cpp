class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;

        int maxArea = INT_MIN;

        while (left < right)
        {
            int mini = min(height[left], height[right]);

            int area = mini * (right - left);

            maxArea = max(maxArea, area);

            if (mini == height[left])
                left++;
            if (mini == height[right])
                right--;
        }
        return maxArea;
    }
};