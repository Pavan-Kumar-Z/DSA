class Solution {
public:

    int addtosum(string temp){
        int p = 0, sum = 0;
        for(int i = temp.size()-1 ; i >= 0 ; i--){
            sum += (temp[i] - '0') * pow(2, p) ; 
            p++; 
        }
        return sum ; 
    }

    void traverse(TreeNode * root, int & sum , string temp){
        if(root == nullptr){
            return;
        } 

        temp += (root->val + '0');  

        if(root->left == nullptr && root->right == nullptr){
            sum += addtosum(temp);
            return;
        }

        traverse(root->left, sum, temp);
        traverse(root->right, sum, temp);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        traverse(root, sum, "");
        return sum;
    }
};