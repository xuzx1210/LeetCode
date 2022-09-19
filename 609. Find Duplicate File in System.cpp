class Solution
{
private:
    void split(string &str, char c, vector<string> &result)
    {
        int start = 0;
        for (int i = 0; i < str.length(); ++i)
            if (str[i] == c)
            {
                result.emplace_back(str.substr(start, i - start));
                start = i + 1;
            }
        result.emplace_back(str.substr(start, str.length() - start));
    }

public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        unordered_map<string, vector<string>> um{};
        for (string &path : paths)
        {
            vector<string> files{};
            split(path, ' ', files);
            string directory = files[0];
            for (int i = 1; i < files.size(); ++i)
            {
                int index = files[i].find('(');
                string name = files[i].substr(0, index), content = files[i].substr(index + 1, files[i].length() - index - 1);
                um[content].emplace_back(directory + '/' + name);
            }
        }
        vector<vector<string>> result{};
        for (auto &[content, filePaths] : um)
            if (filePaths.size() > 1)
            {
                vector<string> tmp{};
                for (string &filePath : filePaths)
                    tmp.emplace_back(filePath);
                result.emplace_back(tmp);
            }
        return result;
    }
};
