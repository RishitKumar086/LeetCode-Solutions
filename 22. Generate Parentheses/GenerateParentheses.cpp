class Solution
{
public:
    void solve(vector<string> &ans, string ch, int open, int close, int n)
    {
        if (ch.size() == 2 * n)
        {
            ans.push_back(ch);
            return;
        }
        if (open < n)
            solve(ans, ch + '(', open + 1, close, n);
        if (close < open)
            solve(ans, ch + ')', open, close + 1, n);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        int openCount = 0;
        int closeCount = 0;
        string ch;
        solve(ans, ch, openCount, closeCount, n);
        return ans;
    }
};