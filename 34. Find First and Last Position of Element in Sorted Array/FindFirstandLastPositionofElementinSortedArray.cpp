class Solution
{
public:
    int firstOcc(vector<int> nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                ans = mid;
                e = mid - 1;
            }
            else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;

            mid = s + (e - s) / 2;
        }

        return ans;
    }
    int lastOcc(vector<int> nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;

            mid = s + (e - s) / 2;
        }

        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = firstOcc(nums, target);
        int last = lastOcc(nums, target);

        vector<int> ans = {first, last};
        return ans;
    }
};