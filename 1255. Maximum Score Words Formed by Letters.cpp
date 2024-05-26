class Solution
{
private:
    int result;
    vector<int> remain;
    vector<vector<int>> wordsCount;
    vector<int> wordsScore;
    bool check(int index)
    {
        for (int i = 0; i < 26; ++i)
            if (remain[i] < wordsCount[index][i])
                return false;
        return true;
    }
    void dfs(const int tmp, const int index, vector<string> &words, vector<int> &score)
    {
        if (index == words.size())
        {
            result = max(result, tmp);
            return;
        }
        dfs(tmp, index + 1, words, score);
        if (!check(index))
            return;
        for (int i = 0; i < 26; ++i)
            remain[i] -= wordsCount[index][i];
        dfs(tmp + wordsScore[index], index + 1, words, score);
        for (int i = 0; i < 26; ++i)
            remain[i] += wordsCount[index][i];
    }

public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        result = 0;
        remain.resize(26, 0);
        for (const char letter : letters)
            ++remain[letter - 'a'];
        wordsCount.resize(words.size(), vector<int>(26, 0));
        wordsScore.resize(words.size(), 0);
        for (int i = 0; i < words.size(); ++i)
            for (const char c : words[i])
            {
                ++wordsCount[i][c - 'a'];
                wordsScore[i] += score[c - 'a'];
            }
        dfs(0, 0, words, score);
        return result;
    }
};
