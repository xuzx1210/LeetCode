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
            char endChar = s[end];
            if (targetCount[endChar])
                if (++counter[endChar] == targetCount[endChar])
                    --targetRemain;
            for (; start <= end; ++start)
            {
                char startChar = s[start];
                if (!targetCount[startChar])
                    continue;
                if (counter[startChar] > targetCount[startChar])
                    --counter[startChar];
                else
                    break;
            }
            if (!targetRemain && end - start < range.second - range.first)
                range = {start, end};
        }
        return targetRemain ? "" : s.substr(range.first, range.second - range.first + 1);
    }
};
