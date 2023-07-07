class Solution
{
private:
    void add(const char c, int &fCount, int &tCount)
    {
        if (c == 'F')
            ++fCount;
        else
            ++tCount;
    }
    void minus(const char c, int &fCount, int &tCount)
    {
        if (c == 'F')
            --fCount;
        else
            --tCount;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        const int n = answerKey.length();
        int result = 0, fCount = 0, tCount = 0, maxFrequency = 0;
        for (int i = 0; i < n; ++i)
        {
            add(answerKey[i], fCount, tCount);
            maxFrequency = max({maxFrequency, fCount, tCount});
            if (result < maxFrequency + k) // push right
                ++result;
            else // pull left
                minus(answerKey[i - result], fCount, tCount);
        }
        return result;
    }
};
