#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000000

enum cmd {
	center,
	forward,
	left,
	backward,
	right
};

int cost[5][5] = {
	{ 1, 2, 2, 2, 2 },
	{ 0, 1, 3, 4, 3 },
	{ 0, 3, 1, 3, 4 },
	{ 0, 4, 3, 1, 3 },
	{ 0, 3, 4, 3, 1 }
};

int main() {
	int cost_endLeft[2] = { 0, 0 };
	int cost_endRight[2] = { 0, 0 };

	pair<int, int> pos_endLeft[2] = { {0, 0}, {0, 0} };
	pair<int, int> pos_endRight[2] = { {0, 0}, {0, 0} };

	int cur = 0;
	int next = 1;

	int nextStep;
	cin >> nextStep;

	while (nextStep) {
		int val[4] = { MAX, MAX, MAX, MAX };

		/** Case: step by Left **/

		// endLeft -> endLeft
		if (pos_endLeft[cur].second != nextStep)
			val[0] = cost_endLeft[cur] + cost[pos_endLeft[cur].first][nextStep];
		// endRight -> endLeft
		if (pos_endRight[cur].second != nextStep)
			val[1] = cost_endRight[cur] + cost[pos_endRight[cur].first][nextStep];


		if (val[0] < val[1]) {
			// endLeft -> endLeft
			cost_endLeft[next] = val[0];
			pos_endLeft[next].first = nextStep;
			pos_endLeft[next].second = pos_endLeft[cur].second;
		}
		else {
			// endRight -> endLeft;
			cost_endLeft[next] = val[1];
			pos_endLeft[next].first = nextStep;
			pos_endLeft[next].second = pos_endRight[cur].second;
		}


		/** Case: step by Right **/

		// endLeft -> endRight
		if (pos_endLeft[cur].first != nextStep)
			val[2] = cost_endLeft[cur] + cost[pos_endLeft[cur].second][nextStep];
		// endRight -> endRight
		if (pos_endRight[cur].first != nextStep)
			val[3] = cost_endRight[cur] + cost[pos_endRight[cur].second][nextStep];

		if (val[2] < val[3]) {
			// endLeft -> endRight
			cost_endRight[next] = val[2];
			pos_endRight[next].first = pos_endLeft[cur].first;
			pos_endRight[next].second = nextStep;
		}
		else {
			// endRight -> endRight
			cost_endRight[next] = val[3];
			pos_endRight[next].first = pos_endRight[cur].first;
			pos_endRight[next].second = nextStep;
		}

		int tmp = next;
		next = cur;
		cur = tmp;

		cin >> nextStep;
	}

	cout << ((cost_endLeft[cur] < cost_endRight[cur]) ? cost_endLeft[cur] : cost_endRight[cur]);


	return 0;


}