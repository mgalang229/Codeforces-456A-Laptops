#include <bits/stdc++.h>

using namespace std;

struct Laptop {
	int price;
	int quality;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Laptop> vec(n);
	int sz = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i].price >> vec[i].quality;
		sz = max(sz, vec[i].price);
	}
	vector<set<int>> a(sz + 1);
	for (int i = 0; i < n; i++) {
		a[vec[i].price].insert(vec[i].quality);
	}
	int mx = 0;
	bool first = true;
	bool checker = false;
	for (int i = 0; i < sz + 1; i++) {
		if (a[i].size() > 0) {
			if (first) {
				first = false;
				mx = *--a[i].end();
			} else {
				if (*a[i].begin() >= mx) {
					mx = *--a[i].end();
				} else {
					checker = true;
					break;
				}
			}
		}
	}
	cout << (checker ? "Happy Alex" : "Poor Alex") << '\n';
	return 0;
}
