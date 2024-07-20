class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // for sign of the answer take a variable and store sign in it
        // base case
        if (dividend == divisor)
            return 1;
        int sign = 1; // initially take positive sign
        if ((dividend >= 0 && divisor < 0) || (dividend <= 0 && divisor > 0))
            sign = -1;
        // take absolute values of dividend and divisor
        long n = abs(dividend);
        long q = abs(divisor);
        long long ans = 0;
        while (n >= q)
        {
            long count = 0;
            // checking how much power of 2 can be removed
            while (n >= (q << (count + 1)))
            {
                count++;
            }
            ans += 1 << count; // adding how many divisor can be removed
            n = n - (q << count);
        }
        // edge cases
        if (ans == (1 << 31) && sign == 1)
            return INT_MAX;
        if (ans == (1 << 31) && sign == -1)
            return INT_MIN;
        return sign * ans;
    }
};