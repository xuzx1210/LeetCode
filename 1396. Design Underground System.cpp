class UndergroundSystem
{
private:
    unordered_map<string, unordered_map<string, pair<int, int>>> history;
    unordered_map<int, pair<string, int>> customer;

public:
    UndergroundSystem() : history{}, customer{} {}
    void checkIn(int id, string stationName, int t)
    {
        customer[id] = {stationName, t};
    }
    void checkOut(int id, string stationName, int t)
    {
        const auto &[startStation, startTime] = customer[id];
        auto &[totalTime, count] = history[startStation][stationName];
        const int time = t - startTime;
        totalTime += time;
        ++count;
    }
    double getAverageTime(string startStation, string endStation)
    {
        const auto &[totalTime, count] = history[startStation][endStation];
        return (double)totalTime / count;
    }
};
