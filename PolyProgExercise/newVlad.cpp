#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;
#define MAXN 333
#define eps 0.00000001
#define point pair<double, double>
#define x first
#define y second

int N, K;
int V[MAXN][MAXN];
double sol[MAXN];
vector<point> aux;
deque<point> polyline[MAXN];
double abs(double a){ if ( a< 0 ) return -a; return a;}
point getIntersection(point p1, point p2, point t1, point t2) {
	double m1 = (p2.y - p1.y) / (p2.x - p1.x);
	double m2 = (t2.y - t1.y) / (t2.x - t1.x);

	if (abs(m1 - m2) < eps) return make_pair(-1, -1);

	double xSol = (m1 * p1.x - p1.y + t1.y - m2 * t1.x) / (m1 - m2);

	if (xSol < t1.x || xSol > t2.x) return make_pair(-1, -1);

	return make_pair(xSol, p1.y + (xSol - p1.x) * m1);
}

bool isAbove(point seg1, point seg2, point p) {
	double m = (seg2.y - seg1.y) / (seg2.x - seg1.x);
	double ySol = seg1.y + (p.x - seg1.x) * m;

	if (p.y > ySol || abs(p.y - ySol) < eps) return true;
	return false;
}

double getArea(deque<point>& polyline) {
	polyline.push_front(make_pair(0, 0));
	polyline.push_back(make_pair(1, 0));

	int n = polyline.size();
	double area = 0.0;
	for (int i = 0; i < n; i++) {
		area += (polyline[i].x * polyline[(i+1)%n].y - polyline[(i+1)%n].x * polyline[i].y);
	}
	area = area / 2.0;

	polyline.pop_back();
	polyline.pop_front();

	return abs(area);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			cin >> V[i][j];
		}
	}

	for (int j = 0; j < K; j++) {
		polyline[j].push_back(make_pair(0, V[1][j]));
		polyline[j].push_back(make_pair(1, V[1][j+1]));

		sol[1] += getArea(polyline[j]);
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < K; j++) {
			// Compute new polyline.
			sol[i] -= getArea(polyline[j]);

			aux.clear();
			aux.push_back(polyline[j][0]);
			for (int k = 0; k < polyline[j].size()-1; k++) {
				pair<double, double> intersectPoint = getIntersection(make_pair(0, V[i][j]), make_pair(1, V[i][j+1]),
						polyline[j][k], polyline[j][k+1]);
				if (intersectPoint.x > -1) {
					aux.push_back(intersectPoint);
				}

				aux.push_back(polyline[j][k+1]);
			}

			polyline[j].clear();
			for (int k = 0; k < aux.size(); k++) {
				if (isAbove(make_pair(0, V[i][j]), make_pair(1, V[i][j+1]), aux[k])) {
					if (polyline[j].size() == 0 || aux[k] != polyline[j][polyline[j].size()-1]) {
						polyline[j].push_back(aux[k]);
					}
				}
			}

			if (polyline[j].size() == 0) {
				polyline[j].push_back(make_pair(0, V[i][j]));
				polyline[j].push_back(make_pair(1, V[i][j+1]));
			} else {
				if (!(abs(polyline[j][0].x - 0.0) < eps)) {
					polyline[j].push_front(make_pair(0, V[i][j]));
				}
				if (!(abs(polyline[j][polyline[j].size()-1].x - 1.0) < eps)) {
					polyline[j].push_back(make_pair(1, V[i][j+1]));
				} else {
					if (polyline[j][polyline[j].size()-1].y < V[i][j+1]) {
						polyline[j].pop_back();
						polyline[j].push_back(make_pair(1, V[i][j+1]));
					}
				}
			}

			sol[i] += getArea(polyline[j]);

			/**
				cout << "where: " << j << " - " << j+1 << endl;
				for (int k = 0; k < polyline[j].size(); k++) {
				cout << "(" << polyline[j][k].x << ", " << polyline[j][k].y << "), ";
				} cout << endl;
			 **/
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << std::fixed << setprecision(8) << sol[i] << '\n';
	}

	return 0;
}
