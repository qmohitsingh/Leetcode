//https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution {
public:
	bool checkIfExist(vector<int>& arr) {

		sort(arr.begin(), arr.end());

		for (int i=0; i<arr.size(); i++) {
			if (binarySearch(arr, 2*arr[i], i)) 
				return true;
		}

		return false;

	}

	bool binarySearch(vector<int> & nums, int target, int srcIndex) {

		int size = nums.size();

		int low = 0;
		int high= size-1;

		while(low < high) {
			int mid = low + (high - low)/2;

			if (nums[mid] < target) low = mid + 1;
			else high = mid;
		}

		return nums[low] == target && low !=srcIndex;
	}
};
