#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long ans = 0;

    string line;
    vector<string> v;
    while (getline(cin, line)) {
        v.push_back(line);
    }

    vector<pair<long long, long long>> ranges;
    int i = 0;
    for (; i < v.size(); ++i) {
        if (v[i].empty()) break;

        int dash = v[i].find('-');
        ranges.push_back({
                stoll(v[i].substr(0, dash)),
                stoll(v[i].substr(dash+1))
                });
    }

    vector<pair<long long, long long>> merged;

    sort(ranges.begin(), ranges.end());
    auto [lb, le] = ranges[0];

    for (int i = 1; i < ranges.size(); ++i) {
        auto [begin, end] = ranges[i];
        if (begin <= le) {
            le = max(end, le);
        } else {
            merged.push_back({lb, le});
            lb = begin;
            le = end;
        }
    }

    merged.push_back({lb, le});

    for (const auto [begin, end]: merged) {
        ans += end - begin + 1;
    }

    cout << ans << endl;

    return 0;
}
