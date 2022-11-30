class Solution
{
public:
    string toHex(int num)
    {
        if (!num)
            return "0";
        string result;
        for (int i = 0; i < 8 && num; ++i)
        {
            int cur = num & 15;
            result.push_back(cur + (cur < 10 ? '0' : 'a' - 10));
            num >>= 4;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
