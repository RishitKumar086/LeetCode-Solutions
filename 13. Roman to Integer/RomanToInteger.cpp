class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mp;
        // mapping to store the roman numerals to integer mapping
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int ans = 0;
        // iterate over the string and
        // check that if ith character is small than i+1th character
        // if yes then subtract else add
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] < mp[s[i + 1]])
                ans -= mp[s[i]];
            else
                ans += mp[s[i]];
        }
        return ans;
    }
};