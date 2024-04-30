class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        long long result = 0;
        vector<int> counter(1024, 0);
        counter[0] = 1;
        int bitmask = 0;
        for (const char c : word)
        {
            const int index = c - 'a';
            bitmask ^= 1 << index;
            result += counter[bitmask]++;
            for (int flip = 1; flip < 1024; flip <<= 1)
                result += counter[bitmask ^ flip];
        }
        return result;
    }
};
