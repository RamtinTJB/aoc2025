#include <iostream>
#include <string>
#include <utility>

using namespace std;

pair<long long, int> find_largest_dig(const string& s) {
    int idx = 0;
    long long dig = 0; 

    for (int i = 0; i < s.size(); ++i) {
        if (s[i]-'0' > dig) {
            idx = i;
            dig = s[i]-'0';
        }
    }
    
    return {dig, idx};
}

long long find_largest(const string& s) {
    long long res = 0;
    int last_idx = 0;

    for (int i = 11; i >= 0; --i) {
        auto [dig, idx] = find_largest_dig(s.substr(last_idx, s.size() - last_idx - i));
        res = res*10 + dig;
        last_idx += idx+1;
    }
    
    return res;
}

int main() {
    long long ans = 0;

    string line;
    while (getline(cin, line)) {
        ans += find_largest(line);      
    }

    cout << ans << endl;

    return 0;
}
