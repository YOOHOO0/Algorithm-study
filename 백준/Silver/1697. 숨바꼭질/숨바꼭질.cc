#include <iostream>
using namespace std;
#include <queue>

queue<int> q;
int dist[100001] = { 0 };
bool visited[100001] = { false };
int n, k;
int ans;

void bfs() {
	q.push(n);
	visited[n] = true;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		int go[3] = { n - 1, n + 1, 2 * n }; // 한 칸 앞, 한 칸 뒤, 두배 점프
		for (int i = 0; i < 3; i++) {
			int nx = go[i];
			if (0 <= nx && nx <= 100000 && !visited[nx]) {
				q.push(nx);
				visited[nx] = true;
				dist[nx] = dist[n] + 1;
			}
			if (nx == k) {
				ans = dist[nx];
				return;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	if (n == k) {
		cout << '0';
	}
	else {
		bfs();
		cout << ans;
	}
}