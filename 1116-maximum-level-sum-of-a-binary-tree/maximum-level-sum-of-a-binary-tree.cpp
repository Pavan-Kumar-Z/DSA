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

    int levelorder(TreeNode * root){
        if(root == nullptr) return 0 ;

        queue<TreeNode*> q ;
        int sum , maxi = INT_MIN, level = 0, maxl = 0 ;  
        q.push(root) ;

        while(!q.empty()){
            int levelsize = q.size() ; 
            sum = 0 ; 
            for(int i = 0 ; i < levelsize ; i++){
                TreeNode * current = q.front() ; 
                q.pop() ; 
                sum += current->val ;

                if(current->left) q.push(current->left) ;
                if(current->right) q.push(current->right) ;
            }
            level++ ;

            if(maxi < sum){
                maxi = sum ; 
                maxl = level ; 
            }
            
        }

        return maxl ;

    }
    int maxLevelSum(TreeNode* root) {
        return levelorder(root) ;
    }
};