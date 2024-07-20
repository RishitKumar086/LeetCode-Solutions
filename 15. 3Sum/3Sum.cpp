class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int ele = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = ele + nums[left] + nums[right];
                if (sum == 0)
                {
                    vector<int> v;
                    v.push_back(ele);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    ans.push_back(v);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    ;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum < 0)
                    left++;
                else
                    right--;
            }
        }
        return ans;
    }
};