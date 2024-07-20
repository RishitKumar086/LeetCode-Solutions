class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int ans = nums.size();
        int start = 0, end = nums.size() - 1;
        int mid = start + (end - start) / 2;
        while (start <= end)
        {
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
                start = mid + 1;
            else
            {
                ans = mid;
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return ans;
    }
};