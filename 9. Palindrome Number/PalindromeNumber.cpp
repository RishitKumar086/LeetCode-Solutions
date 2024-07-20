bool isPalindrome(int n)
{
    unsigned int rev = 0, rem, m = n;

    if (n < 0)
        return false;

    if (n == 0)
        return true;

    if (n % 10 == 0)
        return false;

    while (n != 0)
    {
        rem = n % 10;
        rev = rem + 10 * rev;
        n = n / 10;
    }

    if (m == rev)
        return true;
    else
        return false;
}