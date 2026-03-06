#include <iostream>
#include <string>
#include <utility>

using namespace std;

pair<int, int> find_largest_dig(const string& s) {
    int idx = 0, dig = 0; 
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]-'0' > dig) {
            idx = i;
            dig = s[i]-'0';
        }
    }
    
    return {dig, idx};
}

int find_largest(const string& s) {
    auto [num, idx] = find_largest_dig(s.substr(0, s.size()-1));
    auto [dig, _] = find_largest_dig(s.substr(idx+1));
    
    return num*10 + dig;
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
