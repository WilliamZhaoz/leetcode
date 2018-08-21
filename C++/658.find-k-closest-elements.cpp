
class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int start = 0, end = arr.size() - k;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (x - arr[mid] <= arr[mid + k - 1] - x) {
				// if (abs(arr[mid] - x) <= abs(arr[mid + k - 1] - x) && arr[mid + k - 1] >= x) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		vector<int> left = vector<int>(arr.begin() + start, arr.begin() + start + k);
		vector<int> right = vector<int>(arr.begin() + end, arr.begin() + end + k);
		if (abs(arr[start] - x) <= abs(arr[end + k - 1] - x)) {
			return left;
		}
		return right;

	}
};
/*
class Solution {
public:
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
int left = 0, right = arr.size() - k;
while (left < right) {
int mid = left + (right - left) / 2;
if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
else right = mid;
}
return vector<int>(arr.begin() + left, arr.begin() + left + k);
}
};
*/