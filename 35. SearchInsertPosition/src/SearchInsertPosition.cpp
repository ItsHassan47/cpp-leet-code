#include <iostream>
#include <vector>
using namespace std;

int searchInsertHelper(vector<int> &nums, int target, int startIndex, int endIndex)
{
	if (startIndex > endIndex) {
		return startIndex;
	}

	int middleIndex = (startIndex + endIndex) / 2;
	int currentVal = nums[middleIndex];

	if (currentVal == target) {
		return middleIndex;
	}
	else if (target > currentVal) {
		return searchInsertHelper(nums, target, middleIndex + 1, endIndex);
	}
	else {
		return searchInsertHelper(nums, target, startIndex, middleIndex - 1);
	}
}

int searchInsert(vector<int> &nums, int target)
{
	return searchInsertHelper(nums, target, 0, nums.size() - 1);
}

int main()
{
	vector<int>v = {10,20,30,40,50,60,70,80};
	int target = 25;
	cout << searchInsert(v, target);
}