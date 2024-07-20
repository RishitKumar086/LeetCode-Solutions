class Solution
{
public:
    bool isValid(string s)
    {
        string ans;
        // stack<char> stack;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                ans += s[i];
            }
            if (ans.size() == 0)
                ans.push_back(s[i]);
            else if (s[i] == ']')
            {
                if (ans[ans.size() - 1] == '[')
                {
                    ans.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == '}')
            {

                if (ans[ans.size() - 1] == '{')
                {
                    ans.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == ')')
            {

                if (ans[ans.size() - 1] == '(')
                {
                    ans.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }
        if (ans.size() == 0)
            return true;
        return false;
    }
};