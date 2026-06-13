class Solution {
public:

    int findPosition(vector<int>& nums, int n, int target) {
        int low = 0, high = n-1;
        while(low < high) {
            while(low < high && nums[low] == nums[low+1]) low++;
            while(low < high && nums[high] == nums[high-1]) high--;

            int mid = low + (high-low)/2;
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return high;
    }

    bool binarySearch(vector<int>& nums, int low, int high, int target) {
        while(low <= high) {
            while(low < high && nums[low] == nums[low+1]) low++;
            while(low < high && nums[high] == nums[high-1]) high--;
            int mid = low + (high-low)/2;
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPosition(nums, n, target);
        if(binarySearch(nums, 0, pivot-1, target)) {
            return true;
        } else if(binarySearch(nums, pivot, n-1, target)) {
            return true;
        }
        return false;
    }
};