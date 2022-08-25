#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct interval
{
    int start;
    int end;
    interval(int x, int y) : start(x), end(y)
    {
    }
    interval()
    {
        start = -1;
        end = -1;
    }
};
bool mycmp(interval a, interval b)
{
    if (a.start == b.start)
        return a.end > b.end;

    return a.start < b.start;
}

bool overlap(interval a, interval b)
{
    return b.start <= a.end;
}

int maximumGuests(vector<interval> &arr)
{
    sort(arr.begin(), arr.end(), mycmp);

    int count = 0;
    int ans = 0;

    int ind = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[ind].end >= arr[i].start)
        {
            arr[ind].start = min(arr[ind].start, arr[i].start);
            arr[ind].end = max(arr[ind].end, arr[i].end);
            ++count;
        }
        else
        {
            ans = max(ans, count);
            count = 1;
            ++ind;
            arr[ind] = arr[i];
        }
        ans = max(ans, count);
    }

    cout << ans << endl;
    return ans;
}

int maximumGuests(vector<int> &arr, vector<int> &dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int curr = 0;
    int maxGuests = 0;

    int i = 0, j = 0;
    while (i < arr.size())
    {
        if (arr[i] < dep[j])
        {
            ++curr;
            ++i;
        }
        else if (arr[i] > dep[j])
        {
            --curr;
            ++j;
        }
        maxGuests = max(maxGuests, curr);
    }

    cout << maxGuests << endl;
    return maxGuests;
}
int main()
{
    // vector<interval> intervals = {{800, 840}, {700, 820}, {600, 830}, {500, 530}};
    // vector<interval> intervals = {{900, 910}, {940, 1200}, {950, 1120}, {1100, 1130}, {1500, 1900}, {1800, 2000}};
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    // vector<int> arr = {900, 600, 700};
    // vector<int> dep = {1000, 800, 730};
    maximumGuests(arr, dep);
    return 0;
}