class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        int length = pattern.length();
        vector<int> target(length);
        for (int i = 0; i < length; ++i)
            target[i] = pattern[i] - 'a';
        vector<string> result = {};
        for (string &word : words)
        {
            vector<int> word2target(26, -1), target2word(26, -1);
            bool match = true;
            for (int i = 0; i < length; ++i)
            {
                int index = word[i] - 'a';
                if (word2target[index] != -1 && word2target[index] != target[i] || target2word[target[i]] != -1 && target2word[target[i]] != index)
                {
                    match = false;
                    break;
                }
                word2target[index] = target[i];
                target2word[target[i]] = index;
            }
            if (match)
                result.push_back(word);
        }
        return result;
    }
};
