class Solution
{
private:
    bool isVowel(char c)
    {
        return (1 << (c & 0x1f)) & 0x208222;
    }

public:
    string sortVowels(string s)
    {
        map<char, int> vowelCount{};
        for (char c : s)
            if (isVowel(c))
                ++vowelCount[c];
        vector<pair<char, int>> counter{};
        for (pair<const char, int> &p : vowelCount)
            counter.emplace_back(p);
        int vowelIndex = 0;
        for (char &c : s)
        {
            if (!isVowel(c))
                continue;
            c = counter[vowelIndex].first;
            if (--counter[vowelIndex].second == 0)
                ++vowelIndex;
        }
        return s;
    }
};
