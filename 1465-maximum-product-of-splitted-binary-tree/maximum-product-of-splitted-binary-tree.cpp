/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long subsum(TreeNode* root, auto & subs){
        if(root == nullptr) return 0 ; 

        long long left = subsum(root->left , subs) ; 
        long long right = subsum(root->right,subs) ;

        int sum = root->val + left + right ; 
        subs.push_back(sum) ;
        return sum ; 
    }
    int maxProduct(TreeNode* root) {
        vector<long long>subs ; 
        long long totalsum = subsum(root,subs) ;

        long long product = 0 ;
        for(long long num : subs){
            product = max(product, (totalsum - num) * num) ; 
        }
        int mod = 1e9 + 7 ;
        return product % mod ;  
        
    }
};