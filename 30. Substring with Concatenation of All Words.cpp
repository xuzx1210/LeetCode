class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int wordsSize = words.size(), wordLength = words[0].length();
        int wordsLength = wordsSize * wordLength;
        int length = s.length();
        unordered_map<string, int> wordCount = {};
        for (string &word : words)
            ++wordCount[word];
        vector<int> result = {};
        for (int start = 0; start <= length - wordsLength; ++start)
        {
            auto curWordCount = wordCount;
            bool match = true;
            for (int i = 0; i < wordsSize; ++i)
            {
                string curWord = s.substr(start + i * wordLength, wordLength);
                if (!curWordCount[curWord])
                {
                    match = false;
                    break;
                }
                --curWordCount[curWord];
            }
            if (match)
                result.push_back(start);
        }
        return result;
    }
};
