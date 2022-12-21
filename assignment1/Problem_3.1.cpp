
#include <bits/stdc++.h>
using namespace std;
int isMatch(string text, string pattern)
{
	if (text == "" or pattern == "")
		return false;

	int N = text.size();
	int M = pattern.size();
	vector<vector<bool> > dp(N + 1,
							vector<bool>(M + 1, false));

	// Base Case
	dp[0][0] = true;
	for (int i = 0; i < M; i++) {
		if (pattern[i] == '*' && dp[0][i - 1]) {
			dp[0][i + 1] = true;
		}
	}
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {
			if (pattern[j] == '.') {
				dp[i + 1][j + 1] = dp[i][j];
			}

			if (pattern[j] == text[i]) {
				dp[i + 1][j + 1] = dp[i][j];
			}
			if (pattern[j] == '*') {

				if (pattern[j - 1] != text[i]
					&& pattern[j - 1] != '.') {
					dp[i + 1][j + 1] = dp[i + 1][j - 1];
				}

				else {

					
					dp[i + 1][j + 1]
						= (dp[i + 1][j] or dp[i][j + 1]
						or dp[i + 1][j - 1]);
				}
			}
		}
	}


	return dp[N][M];
}
int main()
{
	string text = "Anujsoni";
	string pattern = "A*ujsoni";

	if (isMatch(text, pattern))
		cout << "Yes";
	else
		cout << "No";
}

