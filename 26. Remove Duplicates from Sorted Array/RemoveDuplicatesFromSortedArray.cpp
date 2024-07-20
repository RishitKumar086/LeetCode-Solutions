class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        int n = nums.size();
        int index = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[index] != nums[i])
            {
                index++;
                nums[index] = nums[i];
            }
        }
        return index + 1;
    }
};