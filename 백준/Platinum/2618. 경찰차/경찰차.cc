/*
 * untitled.cxx
 * Copyright 2024 YUK SEHYUN <yuksehyun@YUKui-MacBookAir.local>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 *backjoon 2618
 */


#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#include<stack>

#define ll long long
using namespace std;

int distance(pair<int, int> a, pair<int, int> b) {

	return	(int)(abs(a.first - b.first) + abs(a.second - b.second));

}

int main() {

	int N, M;


	cin >> N >> M;

	int event[M + 1][2];
	int dp[M + 1][M + 1];
	int p[M + 1][M + 1][2];

	for (int i = 1; i < M + 1; i++) {
		cin >> event[i][0] >> event[i][1];
	}

	memset(dp, 0, (M + 1) * (M + 1) * sizeof(int));
	memset(p, 0, 2 * (M + 1) * (M + 1) * sizeof(int));


	dp[0][1] = distance({ 1,1 }, { event[1][0],event[1][1] });
	dp[1][0] = distance({ N,N }, { event[1][0],event[1][1] });


	for (int i = 2; i < M + 1; i++) {
		dp[0][i] = dp[0][i - 1] + distance({ event[i - 1][0] ,event[i - 1][1] }, { event[i][0] ,event[i][1] });
		p[0][i][0] = 0;
		p[0][i][1] = i - 1;
	}

	for (int i = 2; i < M + 1; i++) {

		dp[i][0] = dp[i - 1][0] + distance({ event[i - 1][0] ,event[i - 1][1] }, { event[i][0] ,event[i][1] });
		p[i][0][0] = i - 1;
		p[i][0][1] = 0;
	}



	for (int i = 1; i < M; i++) {

		int m = 10000000;
		int idx = 0;
		for (int k = 0; k <= i - 1; k++) {

			if (k == 0) {
				event[0][0] = 1;
				event[0][1] = 1;
			}
			int dis = distance({ event[i + 1][0],event[i + 1][1] }, { event[k
			][0], event[k][1]
				});
			if (m > dp[i][k] + dis) {
				m = dp[i][k] + dis;
				idx = k;
			}
		}

		// cout << m << endl;
		dp[i][i + 1] = m;
		p[i][i + 1][0] = i;
		p[i][i + 1][1] = idx;

		m = INT32_MAX;
		idx = 0;

		for (int j = i + 2; j < M + 1;j++) {
			dp[i][j] = dp[i][j - 1] + distance({ event[j][0],event[j][1] }, { event[j - 1][0],event[j - 1][1] });
			p[i][j][0] = i;
			p[i][j][1] = j - 1;
		}

		for (int k = 0; k <= i - 1; k++) {

			if (k == 0) {
				event[0][0] = N;
				event[0][1] = N;
			}
			if (m > dp[k][i] + distance({ event[i + 1][0],event[i + 1][1] }, { event[k
			][0], event[k][1]
				})) {
				m = dp[k][i] + distance({ event[i + 1][0],event[i + 1][1] }, { event[k
			][0], event[k][1]
					});
				idx = k;
			}
		}

		dp[i + 1][i] = m;
		p[i + 1][i][0] = idx;
		p[i + 1][i][1] = i;


		for (int j = i + 2; j < M + 1;j++) {
			dp[j][i] = dp[j - 1][i] + distance({ event[j][0],event[j][1] }, { event[j - 1][0],event[j - 1][1] });
			p[j][i][0] = j - 1;
			p[j][i][1] = i;
		}

	}

	// for (int i = 0; i < M + 1; i++) {

	// 	for (int j = 0; j < M + 1;j++) {

	// 		cout << dp[i][j] << " ";

	// 	}

	// 	cout << endl;
	// }

	// for (int i = 0; i < M + 1; i++) {

	// 	for (int j = 0; j < M + 1;j++) {

	// 		cout << p[i][j] << " ";

	// 	}

	// 	cout << endl;
	// }


	stack<int> s;
	pair<int, int> n;
	int num = INT32_MAX;


	for (int i = 0; i < M; i++) {


		if (num > dp[M][i]) {
			num = dp[M][i];
			n = { M,i };
		}
		if (num > dp[i][M]) {
			num = dp[i][M];
			n = { i,M };
		}

	}
	// cout << n.first << n.second << endl;
	while (n.first | n.second) {

		if (n.first > n.second) {
			s.push(2);

		}
		else {
			s.push(1);
		}
		// cout << n.first << " " << n.second << endl;
		n = { p[n.first][n.second][0],p[n.first][n.second][1] };
		// cout << n.first << n.second << endl;

	}

	cout << num << endl;
	while (!s.empty()) {
		int tmp = s.top();
		cout << tmp << endl;
		s.pop();
	}

	return 0;
}


