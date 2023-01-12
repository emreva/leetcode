#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;



double get_slope(vector<int>& p, vector<int>& q)
{
	if (p[0] == q[0]) return INFINITY;
	if (p[1] == q[1]) return 0.0;

	auto& xright = p[0] > q[0] ? p : q;
	auto& xleft = p[0] < q[0] ? p : q;

	return static_cast<double>(xright[1] - xleft[1]) / (xright[0] - xleft[0]);
}

size_t find_max(map<double, size_t>& sm)
{
	size_t max = 0u;

	for (auto& e : sm)
	{
		if (e.second > max)
		{
			max = e.second;
		}
	}

	return max;
}
int maxPoints(vector<vector<int>>& points) {

	int max = INT_MIN;
	map<double, size_t> slope_counts;
	for (auto i = 0u; i < points.size() - 1u; i++)
	{
		for (auto j = i + 1u; j < points.size(); j++)
		{
			slope_counts[get_slope(points[i], points[j])]++;
		}
		auto largest = find_max(slope_counts);
		slope_counts.clear();
		if (max < static_cast<int>(largest))
		{
			max = largest;
		}
	}
	return max + 1; 
}


int main()
{
	vector<vector<int>> points{ {1, 1}, {2, 2}, {3, 3}};


	cout << "Maximum points on reference points line: " << maxPoints(points) << endl;
	return 0;
}