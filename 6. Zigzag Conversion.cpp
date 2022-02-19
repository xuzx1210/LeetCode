class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int length = s.length();
        int halfGroupLength = numRows - 1;
        int groupLength = halfGroupLength << 1;
        vector<string> group;
        group.clear();
        for (int i = 0; i < length / groupLength; ++i)
            group.push_back(string(s, i * groupLength, groupLength));
        int remainLength = length % groupLength;
        string remainString;
        remainString.clear();
        if (remainLength)
            remainString = string(s, groupLength * group.size(), remainLength);
        string result;
        result.clear();
        for (int g = 0; g < group.size(); ++g)
            result.push_back(group[g][0]);
        if (remainLength)
            result.push_back(remainString[0]);
        for (int i = 1; i < halfGroupLength; ++i)
        {
            int second = groupLength - i;
            for (int g = 0; g < group.size(); ++g)
            {
                result.push_back(group[g][i]);
                result.push_back(group[g][second]);
            }
            if (remainLength > i)
                result.push_back(remainString[i]);
            if (remainLength > second)
                result.push_back(remainString[second]);
        }
        for (int g = 0; g < group.size(); ++g)
            result.push_back(group[g][halfGroupLength]);
        if (remainLength >= numRows)
            result.push_back(remainString[halfGroupLength]);
        return result;
    }
};
