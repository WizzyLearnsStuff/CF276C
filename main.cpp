// #pragma GCC optimize("O3,unroll-loops")

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define lli long long int

int main() {
	int n, q;

	cin >> n >> q;

	vector<int> v(n);

	for (int &e : v) {
		cin >> e;
	}

	sort(v.begin(), v.end());

	// Observation 1: The maximum accessed elem must be max
	// Observation 2: building the array if coefficients costs extra
	// Observation 3: We need coefficients in order
	// Observation 4: Increment segments faster than O(n)

	vector<int> uses(n + 1);

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		uses[--l]++;
		uses[r]--;
	}

	uses.pop_back();

	int rsum = 0;
	for (int &e : uses) {
		rsum += e;
		e = rsum;
	}

	sort(uses.begin(), uses.end());

	lli s = 0;

	for (int i = n - 1; i >= 0; i--) {
		s += ((lli)uses[i]) * ((lli)v[i]);
	}
	cout << s;
	
}
