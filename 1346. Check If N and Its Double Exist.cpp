//https://leetcode.com/problems/check-if-n-and-its-double-exist/

// Approach #1 : Using Sorting and Binary Search 
class Solution {
public:
	// Time - O(nlong), Space - O(1) 
	bool checkIfExist(vector<int>& arr) {

		sort(arr.begin(), arr.end()); // Time - O(nlogn)

		for (int i=0; i<arr.size(); i++) {  // Time - O(n)
			if (binarySearch(arr, 2*arr[i], i))  // Time - O(n)
				return true;
		} // loop and binarySearch Inside it = Time : O(nlogn)

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

// Approach #2 : Using HashMap
class Solution {
public:

	// Time - O(n), Space - O(n)
	bool checkIfExist(vector<int>& arr) {

		unordered_map<int, int> map;

		for (auto n : arr) {
			map[n]++;
		}

		for (auto n  : arr) 
			if (n == 0 && map[n] == 1) // Corner case
				continue;
			else if (map.find(n*2) != map.end()) 
				return true;

		return false;

	}
};
