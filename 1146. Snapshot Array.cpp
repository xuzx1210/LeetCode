class SnapshotArray
{
private:
    vector<map<int, int>> snaps;
    int snapId;

public:
    SnapshotArray(int length) : snaps(length, map<int, int>{{0, 0}}), snapId(0) {}
    void set(int index, int val)
    {
        snaps[index][snapId] = val;
    }
    int snap()
    {
        return snapId++;
    }
    int get(int index, int snap_id)
    {
        return prev(snaps[index].upper_bound(snap_id))->second;
    }
};
