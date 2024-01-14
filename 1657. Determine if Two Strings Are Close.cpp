class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        vector<int> counter1(26, 0), counter2(26, 0);
        for (const char c : word1)
            ++counter1[c - 'a'];
        for (const char c : word2)
            ++counter2[c - 'a'];
        for (int i = 0; i < 26; ++i)
            if (counter1[i] && !counter2[i] || !counter1[i] && counter2[i])
                return false;
        sort(counter1.begin(), counter1.end());
        sort(counter2.begin(), counter2.end());
        return counter1 == counter2;
    }
};
