class Solution
{
public:
    // recursive
    void solve(string s, long &ans, int i, int sign)
    {
        if (i == s.length())
        {
            return;
        }
        if (s[0] == ' ' || !isdigit(s[i]))
            return;

        ans = ans * 10 + s[i] - '0';
        if (sign == -1 && -1 * ans < INT_MIN)
        {
            ans = INT_MIN;
            return;
        }
        if (sign == 1 && ans > INT_MAX)
        {
            ans = INT_MAX;
            return;
        }

        solve(s, ans, i + 1, sign);
    }
    int myAtoi(string s)
    {
        if (s.length() == 0)
            return 0;

        int i = 0;
        // removal of leading whitespaces
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }
        s = s.substr(i); // i ---> last of string

        int sign = +1;
        long ans = 0;

        if (s[0] == '-')
            sign = -1;

        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        solve(s, ans, i, sign);

        // iterative

        // int MAX = INT_MAX, MIN = INT_MIN;

        // while (i < s.length()) {
        //     if (s[0] == ' ' || !isdigit(s[i]))
        //         break;

        //     ans = ans * 10 + s[i] - '0';
        //     // range check
        //     if (sign == -1 && -1 * ans < MIN)
        //         return MIN;
        //     if (sign == 1 && ans > MAX)
        //         return MAX;

        //     i++;
        // }

        return (int)(sign * ans);
    }
};