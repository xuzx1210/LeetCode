class BrowserHistory
{
private:
    vector<string> history;
    int index;
    int last;

public:
    BrowserHistory(string homepage)
    {
        history.clear();
        history.emplace_back(homepage);
        index = 0;
        last = 0;
    }
    void visit(string url)
    {
        ++index;
        if (index == history.size())
            history.emplace_back(url);
        else
            history[index] = url;
        last = index;
    }
    string back(int steps)
    {
        index = max(0, index - steps);
        return history[index];
    }
    string forward(int steps)
    {
        index = min(last, index + steps);
        return history[index];
    }
};
