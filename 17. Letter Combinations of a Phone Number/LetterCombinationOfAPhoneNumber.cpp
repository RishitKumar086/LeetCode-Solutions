class Solution
{
public:
    void solve(string digits, string op, int index, vector<string> &ans, string keymap[])
    {
        if (index >= digits.size())
        {
            ans.push_back(op);
            return;
        }
        int number = digits[index] - '0';
        string value = keymap[number];
        for (int i = 0; i < value.size(); i++)
        {
            op.push_back(value[i]);
            solve(digits, op, index + 1, ans, keymap);
            op.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        string keymap[10];
        keymap[0] = "";
        keymap[1] = "";
        keymap[2] = "abc";
        keymap[3] = "def";
        keymap[4] = "ghi";
        keymap[5] = "jkl";
        keymap[6] = "mno";
        keymap[7] = "pqrs";
        keymap[8] = "tuv";
        keymap[9] = "wxyz";

        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        string op;
        int index = 0;
        solve(digits, op, index, ans, keymap);
        return ans;
    }
};