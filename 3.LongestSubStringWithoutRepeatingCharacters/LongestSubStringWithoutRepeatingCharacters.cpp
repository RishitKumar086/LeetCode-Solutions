class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int hash[256];
        if (s.size() == 0)
            return 0;
        for (int i = 0; i < 256; i++)
        {
            hash[i] = -1;
        }
        int maxLength = INT_MIN;
        int n = s.size();
        int left = 0;
        int right = 0;
        while (right < n)
        {
            if (hash[s[right]] != -1)
            {
                // if the character has already occured move the window till the
                // position of that character + 1 so that it can be removed from
                // to avoid repetition
                if (hash[s[right]] >= left)
                {
                    left = hash[s[right]] + 1;
                }
            }
            int len = right - left + 1;
            maxLength = max(len, maxLength);
            hash[s[right]] = right;
            right++;
        }
        return maxLength;
    }
};