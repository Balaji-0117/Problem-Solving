class Solution {
public:

    bool canComplete(vector<int>& time, long long givenTime, int totalTrips) {
        long long actualTrips = 0;
        for(int &t : time) {
            actualTrips += givenTime/t;
        }
        return actualTrips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long low = 1, high = (long long) *min_element(time.begin(), time.end()) * totalTrips;
        while(low < high) {
            long long mid_time = low + (high-low)/2;
            if(canComplete(time, mid_time, totalTrips)) {
                high = mid_time;
            } else {
                low = mid_time + 1;
            }
        }
        return low;
    }
};