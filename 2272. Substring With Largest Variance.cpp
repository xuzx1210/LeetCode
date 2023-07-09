class Solution
{
public:
    int largestVariance(string s)
    {
        int result = 0;
        for (char most = 'a'; most <= 'z'; ++most)
            for (char least = 'a'; least <= 'z'; ++least)
            {
                if (most == least)
                    continue;
                int mostCount = 0, leastCount = 0;
                bool previousLeast = false;
                for (const char c : s)
                {
                    if (c == most)
                        ++mostCount;
                    else if (c == least)
                        ++leastCount;
                    if (leastCount)
                        result = max(result, mostCount - leastCount);
                    else if (previousLeast)
                        result = max(result, mostCount - 1);
                    if (mostCount < leastCount)
                    {
                        mostCount = leastCount = 0;
                        previousLeast = true;
                    }
                }
            }
        return result;
    }
};
