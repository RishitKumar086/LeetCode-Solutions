class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() <= 1)
        {
            return s;
        }

        int max_len = 1;
        int start = 0;
        int end = 0;
        // this is initializing the dp matrix by false
        vector<vector<bool>> dp(s.length(),
                                vector<bool>(s.length(), false));

        for (int i = 0; i < s.length(); ++i)
        {
            dp[i][i] = true; // all length one are palindromes
            for (int j = 0; j < i; ++j)
            {
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1]))
                {
                    // start and end of an index should be equal
                    // and in between the two should be palindrome
                    dp[j][i] = true;
                    // update the max_length and start and end of the longest
                    // palindromic substring
                    if (i - j + 1 > max_len)
                    {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};