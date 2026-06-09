class Solution {
public:

    int findPivot(vector<int>& nums, int n) {
        int low = 0, high = n-1;
        int resultIdx = 0;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] < nums[resultIdx]) {
                resultIdx = mid;
            } else if(nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return resultIdx;
    }

    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivotIdx = findPivot(nums, n);

        int resultIdx = binarySearch(nums, 0, pivotIdx-1, target);
        if(resultIdx != -1){
            return resultIdx;
        }
        resultIdx = binarySearch(nums, pivotIdx, n-1, target);
        return resultIdx;
    }
};