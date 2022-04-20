class Solution
{
public:
    string s;
    int length;
    vector<string> wordDict;
    vector<string> cur;
    set<vector<string>> all;
    bool equal(int index, string &word)
    {
        if (index + word.length() > s.length())
            return false;
        for (int i = 0; i < word.length(); ++i)
            if (s[index + i] != word[i])
                return false;
        return true;
    }
    void dfs(int index)
    {
        if (index > length)
            return;
        if (index == length)
        {
            all.insert(cur);
            return;
        }
        for (string &word : wordDict)
            if (equal(index, word))
            {
                cur.push_back(word);
                dfs(index + word.length());
                cur.pop_back();
            }
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        this->s = s;
        length = s.length();
        this->wordDict = wordDict;
        cur.clear();
        all.clear();
        dfs(0);
        vector<string> result({});
        for (auto &one : all)
        {
            string tmp("");
            for (auto &word : one)
                tmp += (word + " ");
            tmp.pop_back();
            result.push_back(tmp);
        }
        return result;
    }
};
