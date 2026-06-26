class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        unordered_set<int> st;

        for (int num : nums) {
            st.insert(num);
        }

        int longest = 1;

        for (auto it : st) {
            // Start of a sequence
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;   //x is the first element

                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};