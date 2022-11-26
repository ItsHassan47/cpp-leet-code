#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
	vector<vector<int>>output;
	set<vector<int>>myset;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = i + 1; j < nums.size(); ++j) {
			for (int k = j + 1; k < nums.size(); ++k) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					vector<int>v {nums[i], nums[j], nums[k]};
					sort(v.begin(), v.end());
					myset.insert(v);
				}
			}
		}
	}

	for (auto it = myset.begin(); it != myset.end(); ++it)
		output.push_back(*it);

	return output;
}



int main()
{
	vector<int>nums {-1,0,1,2,-1,-4};
	for (const auto &v : threeSum(nums)) {
		for (const auto &v2 : v)
			cout << v2 << " ";
		cout << endl;
	}

	return 0;
}