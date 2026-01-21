class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int prev = 0;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 2)
                res.push_back(-1);
            else {
                for (int j = 0; j < 32; j++) {
                    if ((nums[i] & (1 << j)) > 0)
                        continue;
                    else {
                        prev = j - 1;
                        res.push_back((nums[i] ^ (1 << prev)));
                        break;
                    }
                }
            }
        }

        return res;
    }
};