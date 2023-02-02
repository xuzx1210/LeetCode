class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        const size_t size = words.size();
        unordered_map<char, size_t> index{};
        for (size_t i = 0; i < 26; ++i)
            index[order[i]] = i;
        for (size_t i = 1; i < size; ++i)
        {
            const size_t length0 = words[i - 1].length(), length1 = words[i].length();
            const size_t minLength = min(length0, length1);
            bool sorted = false;
            for (size_t j = 0; j < minLength; ++j)
                if (index[words[i - 1][j]] > index[words[i][j]])
                    return false;
                else if (index[words[i - 1][j]] < index[words[i][j]])
                {
                    sorted = true;
                    break;
                }
            if (sorted)
                continue;
            if (length0 > length1)
                return false;
        }
        return true;
    }
};
