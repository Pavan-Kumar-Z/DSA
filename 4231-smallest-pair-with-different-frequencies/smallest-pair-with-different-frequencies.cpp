class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {

        unordered_map<int,int> hashmap ; 
        for(int num : nums) hashmap[num]++ ;

        sort(nums.begin() , nums.end()) ;
        for(int i=0 ; i < nums.size() ; i++){

            int temp = i+1 ; 
            while(temp < nums.size()){
                if(hashmap[nums[temp]] != hashmap[nums[i]]) return {nums[i],nums[temp]} ;
                else temp++ ;
            }
        }

        return {-1,-1} ;
    }
};