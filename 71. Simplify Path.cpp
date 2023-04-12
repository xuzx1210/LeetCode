class Solution
{
public:
    string simplifyPath(string path)
    {
        string line{};
        stringstream ss(path);
        vector<string> directories{};
        while (getline(ss, line, '/'))
            if (line == "" || line == ".")
                continue;
            else if (line != "..")
                directories.emplace_back(line);
            else if (directories.empty())
                continue;
            else
                directories.pop_back();
        if (directories.empty())
            return "/";
        string result{};
        for (const string &directory : directories)
            result += ("/" + directory);
        return result;
    }
};
