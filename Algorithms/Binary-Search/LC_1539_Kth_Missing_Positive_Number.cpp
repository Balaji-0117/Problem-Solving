class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            int miss_till_mid = arr[mid] - (mid+1);
            if(miss_till_mid < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low + k;
    }
};