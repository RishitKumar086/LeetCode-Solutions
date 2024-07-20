class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int index = -1;
        int n = nums.size();
        // finding the break point in the array
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }

        // checking if the last lexicographically permutation
        if (index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // swapping the first largest number from the breakpoint number
        for (int i = n - 1; i > index; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // reversing to get the smallest possible
        reverse(nums.begin() + index + 1, nums.end());
        return;
    }
};