#include <iostream>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>

using namespace std;

// true if the number repeats twice
bool check(long long i) {
    string si = to_string(i);
    auto nd = si.size();

    for (int i = 1; i < si.size(); ++i) {
        if (nd % i == 0) {
            int num_rep = nd / i;
            string rep = si.substr(0, i);
            string repeated;
            for (int i = 0; i < num_rep; ++i) repeated += rep;

            if (si == repeated) return true;
        }
    }

    return false;
}

int main() {
    string line;
    getline(cin, line);

    long long ans = 0;

    for (auto part: line | views::split(',')) {
        string range(part.begin(), part.end());

        auto dash = range.find('-');
        long long begin = stoll(range.substr(0, dash));
        long long end = stoll(range.substr(dash+1));

        for (auto i = begin; i <= end; ++i) {
            if (check(i)) ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}
