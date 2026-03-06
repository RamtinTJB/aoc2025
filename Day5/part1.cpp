#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int ans = 0;

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

    i++;
    for (; i < v.size(); ++i) {
        long long num = stoll(v[i]);
        for (const auto [begin, end]: ranges) {
            if (num >= begin && num <= end) {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
