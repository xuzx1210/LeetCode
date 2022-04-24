class UndergroundSystem
{
public:
    map<int, pair<string, int>> checkInData;         //<id, <checkInStationName, checkInTime>>
    map<pair<string, string>, pair<int, int>> times; //<<checkInStationName, checkOutStationName>, <sum, num>>
    UndergroundSystem()
    {
        checkInData.clear();
        times.clear();
    }
    void checkIn(int id, string stationName, int t)
    {
        checkInData[id] = {stationName, t};
    }
    void checkOut(int id, string stationName, int t)
    {
        auto &data = checkInData[id];
        auto &history = times[{data.first, stationName}];
        history.first += (t - data.second);
        ++history.second;
    }
    double getAverageTime(string startStation, string endStation)
    {
        auto &history = times[{startStation, endStation}];
        return (double)history.first / history.second;
    }
};
