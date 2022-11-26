#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
	// we will subtract the target value from the nums it will result in other value and check if it is present in the map or not. if it is then we will push the value (index in the case), and also the current index in the vector

	vector<int>result;
	map<int, int>cache;

	for (int i = 0; i < nums.size(); i++) {
		int num = target - nums[i];
		if (cache.contains(num)) {
			result.push_back(cache[num]);
			result.push_back(i);
			return result;
		}
		cache.insert(make_pair(nums[i], i));
	}
	return result;
}

int main()
{
	vector<int>nums {10,1,3,6,9};
	int target = 12;

	for (const auto &v : twoSum(nums, target))
		cout << v << ' ';

	return 0;
}