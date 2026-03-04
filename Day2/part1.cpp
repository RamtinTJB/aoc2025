#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& s, char delim) {
    auto idx = s.find(delim);
    int begin = 0;
    vector<string> res;

    while (idx != string::npos) {
        res.push_back(s.substr(begin, idx-begin));
        begin = idx+1;
        idx = s.find(delim, begin);
    }

    res.push_back(s.substr(begin));

    return res;
}

long long num_digits(long long n) {
    int count = 0;
    while (n) {
        n /= 10;
        count++;
    }

    return count;
}

// true if the number repeats twice
bool check(long long n) {
    auto nd = num_digits(n);
    if (nd & 1) return false;

    auto half = nd / 2;
    long long mod = pow(10, half);

    long long rh = n % mod;
    long long lf = n / mod;

    return rh == lf;
}

int main() {
    string line;
    getline(cin, line);

    long long ans = 0;

    auto ranges = split(line, ',');
    for (const auto& range: ranges) {
        auto r = split(range, '-');
        auto begin = stoll(r[0]), end = stoll(r[1]);

        for (auto i = begin; i <= end; ++i) {
            if (check(i)) ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}
