
#include <bits/stdc++.h>
using namespace std;

static bool myCompare(pair<int,int> &p1, pair<int,int> &p2) {
	if(p1.first == p2.first) {
		return p1.second > p2.second; 
	}
	return p1.first < p2.first;
}

bool areBookingsPossible(int arrival[],
						int departure[], int n, int k)
{
	vector<pair<int, int> > ans;

	for (int i = 0; i < n; i++) {
		ans.push_back(make_pair(arrival[i], 1));
		ans.push_back(make_pair(departure[i], 0));
	}


	sort(ans.begin(), ans.end(), myCompare);

	int curr_active = 0, max_active = 0;

	for (int i = 0; i < ans.size(); i++) {

		// if new arrival, increment current
		// guests count and update max active
		// guests so far
		if (ans[i].second == 1) {
			curr_active++;
			max_active = max(max_active,
							curr_active);
		}

		else
			curr_active--;
	}
	return (k >= max_active);
}

int main()
{
	int arrival[] = {100, 300, 500 };
	int departure[] = { 900, 400, 600};
	int n = sizeof(arrival) / sizeof(arrival[0]);
	cout << (areBookingsPossible(arrival,
								departure, n, 1)
				? "Yes\n"
				: "No\n");
	return 0;
}
