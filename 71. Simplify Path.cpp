class Solution
{
public:
    string simplifyPath(string path)
    {
        // split path by '/'
        path.push_back('/');
        const int length = path.length();
        vector<string> directories{};
        for (int begin = 0, i = 0; i < length; ++i)
        {
            if (path[i] != '/')
                continue;
            if (begin < i)
                directories.emplace_back(path, begin, i - begin);
            begin = i + 1;
        }
        // remove useless directories
        const int size = directories.size();
        int end = 0;
        for (int i = 0; i < size; ++i)
            if (directories[i] == ".")
                continue;
            else if (directories[i] == "..")
                end = max(0, end - 1);
            else
                directories[end++] = directories[i];
        // return result
        if (!end)
            return "/";
        string result{};
        for (int i = 0; i < end; ++i)
            result += ("/" + directories[i]);
        return result;
    }
};
