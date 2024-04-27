class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        const int ringLength = ring.length(), keyLength = key.length();
        vector<vector<int>> indicesOfCharacters(26, vector<int>{});
        for (int ringPosition = 0; ringPosition < ringLength; ++ringPosition)
            indicesOfCharacters[ring[ringPosition] - 'a'].emplace_back(ringPosition);
        vector<int> dp(ringLength, 0);
        for (int keyIndex = keyLength - 1; keyIndex >= 0; --keyIndex)
        {
            vector<int> tmp(ringLength, INT_MAX);
            for (int currPosition = 0; currPosition < ringLength; ++currPosition)
                for (const int nextPosition : indicesOfCharacters[key[keyIndex] - 'a'])
                {
                    const int minimumPosition = min(currPosition, nextPosition), maximumPosition = max(currPosition, nextPosition);
                    tmp[currPosition] = min(tmp[currPosition], dp[nextPosition] + min(maximumPosition - minimumPosition, minimumPosition + ringLength - maximumPosition));
                }
            dp.swap(tmp);
        }
        return dp[0] + keyLength;
    }
};
