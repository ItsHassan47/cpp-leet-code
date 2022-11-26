#include <iostream>
#include <vector>
#include <array>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
/*	const int N = nums.size();
	int *right = new int[N];
	int *left = new int[N];
	left[0] = 1;
	right[N-1] = 1;

	vector<int>result;
	
	for (int i = 1; i < nums.size(); i++) {
		left[i] = nums[i - 1] * left[i - 1];		
	}
	for (int i = nums.size() - 2; i >= 0; i--) {
		right[i] = nums[i + 1] * right[i + 1];	
	}
	for (int i = 0; i < nums.size(); i++) {
		result.push_back(left[i] * right[i]);
	}

	delete[]left;
	delete[]right;*/	
	
	//const int N = nums.size();
	//int *right = new int[N];
	//int *left = new int[N];
	//left[0] = 1;
	//right[N-1] = 1;

	vector<int>result {1};
	
	for (int i = 0; i < nums.size() -1; i++) {
		result.push_back(nums[i] * result[i]);				
	}
	int R = 1;
	for (int i = nums.size() - 1; i >= 0; i--) {
		result[i] = result[i] * R;
		R *= nums[i];
	}

	return result;
}

int main()
{
	vector<int>nums {1,2,3,4};
	for (const auto &v : productExceptSelf(nums))
		cout << v << ' ';

	return 0;
}