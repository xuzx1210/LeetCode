class Solution
{
public:
    string simplifyPath(string path)
    {
        for (int i = path.length() - 1; i > 0; --i)
            if (path[i] == '/')
                if (path[i - 1] == '/')
                    path.erase(path.begin() + i);
        path.erase(path.begin());
        if (path.length())
            if (path.back() == '/')
                path.pop_back();
        vector<string> directories({});
        for (int i = 0; i < path.length(); ++i)
            if (path[i] == '/')
            {
                directories.push_back(string(path, 0, i));
                path.erase(0, i + 1);
                i = -1;
            }
        directories.push_back(path);
        vector<string> directoryStack({});
        for (string directory : directories)
        {
            if (directory == ".")
                continue;
            if (directory == "..")
            {
                if (!directoryStack.empty())
                    directoryStack.pop_back();
                continue;
            }
            directoryStack.push_back(directory);
        }
        if (directoryStack.empty())
            return "/";
        string result("");
        for (string directory : directoryStack)
            result += ("/" + directory);
        return result;
    }
};
