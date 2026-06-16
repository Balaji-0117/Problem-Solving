class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0, i = 0;

        while(i < n) {
            char currChar = chars[i];
            int count = 0;
            while(i < n && chars[i] == currChar) {
                count++;
                i++;
            }
            chars[idx++] = currChar;
            if(count > 1) {
                string s = to_string(count);
                for(char &ch : s) {
                    chars[idx++] = ch;
                }
            }
        }
        return idx;
    }
};