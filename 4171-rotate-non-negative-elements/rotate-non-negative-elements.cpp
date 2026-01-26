class Solution {
public:
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }

    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> pos;
        for (int num : nums) {
            if (num >= 0) pos.push_back(num);
        }

        int n = pos.size();
        if (n == 0) return nums;

        k = k % n;
        if (k == 0) return nums;

        reverse(pos, 0, k - 1);
        reverse(pos, k, n - 1);
        reverse(pos, 0, n - 1);

        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                nums[i] = pos[j];
                j++;
            }
        }

        return nums;
    }
};
