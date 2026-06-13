class Solution {
public:


    int findPeak(MountainArray &nums, int n) {
        int low = 0, high = n-1;
        while(low < high) {
            int mid = low + (high-low)/2;
            if(nums.get(mid) < nums.get(mid+1)) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int binarySearch(MountainArray &nums, int low, int high, int target, bool isAsc) {
        while(low <= high) {
            int mid = low + (high-low)/2;
            int val = nums.get(mid);
            if(val == target) {
                return mid;
            }
            if(isAsc) {
                if(val < target) {
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            } else {
                if(val < target) {
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = findPeak(mountainArr, n);
        int resultIdx = binarySearch(mountainArr, 0, peak-1, target, true);
        if(resultIdx != -1) {
            return resultIdx;
        }
        resultIdx = binarySearch(mountainArr, peak, n-1, target, false);
        return resultIdx;
    }
};