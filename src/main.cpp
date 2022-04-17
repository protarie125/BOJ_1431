#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Data {
public:
	string raw{ "" };
	int val{ 0 };
	int len{ 0 };
};

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto strs = vector<Data>(n);
	for (int i = 0; i < n; ++i) {
		string r;
		cin >> r;

		auto d = Data();
		d.raw = r;
		d.len = static_cast<int>(r.length());
		d.val = 0;
		for (int j = 0; j < d.len; ++j) {
			if ('0' <= r[j] && r[j] <= '9') {
				d.val += r[j] - '0';
			}
		}

		strs[i] = d;
	}

	sort(strs.begin(), strs.end(), [](const Data& l, const Data& r) {
		if (l.len != r.len) {
			return l.len < r.len;
		}

		if (l.val != r.val) {
			return l.val < r.val;
		}

		return l.raw < r.raw;
		});

	for (const auto& d : strs) {
		cout << d.raw << '\n';
	}

	return 0;
}