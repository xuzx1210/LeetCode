class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> targetCount, counter;
        for (char &c : t)
            ++targetCount[c];
        int targetRemain = targetCount.size(), length = s.length(), start = 0;
        pair<int, int> range = {0, length - 1};
        for (int end = 0; end < length; ++end)
        {
            char e = s[end];
            if (targetCount[e])
            {
                ++counter[e];
                if (counter[e] == targetCount[e])
                    --targetRemain;
            }
            for (; start <= end; ++start)
            {
                char cur = s[start];
                if (!targetCount[cur])
                    continue;
                if (counter[cur] > targetCount[cur])
                    --counter[cur];
                else
                    break;
            }
            if (!targetRemain && end - start < range.second - range.first)
                range = {start, end};
        }
        return targetRemain ? "" : s.substr(range.first, range.second - range.first + 1);
    }
};
