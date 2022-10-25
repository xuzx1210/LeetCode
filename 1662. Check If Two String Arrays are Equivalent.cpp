class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int w1 = 0, i1 = 0, w2 = 0, i2 = 0;
        while (true)
        {
            if (word1[w1][i1] != word2[w2][i2])
                return false;
            if (++i1 == word1[w1].length())
            {
                ++w1;
                i1 = 0;
            }
            if (++i2 == word2[w2].length())
            {
                ++w2;
                i2 = 0;
            }
            if (w1 == word1.size() && w2 == word2.size())
                break;
            if (w1 == word1.size() || w2 == word2.size())
                return false;
        }
        return true;
    }
};
