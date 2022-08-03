class MyCalendar
{
private:
    vector<pair<int, int>> events;

public:
    MyCalendar()
    {
        events.clear();
    }
    bool book(int start, int end)
    {
        for (auto &event : events)
            if (!(start < event.first && end <= event.first || event.first < start && event.second <= start))
                return false;
        events.push_back({start, end});
        return true;
    }
};
