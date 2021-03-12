
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
       /* if(root->val < low || root ->val > high)
        {
        this is wrong condition that i was including , as it will directly return NULL without thinking of left and right subtree, kya pta nichr khi range m ho wale nodes mil jae
        so have have deal this by breaking
        if(root->val < low) and if(root->val > high)
            return NULL
        }
        */
        if(root == NULL)  // termination condition
        {
            return NULL;
        }  
        if(root->val < low)  // we can't include root and its left substree so return right subtree
        {  
            return  trimBST(root->right,low,high);
        }
        if(root->val > high) // we can't include root and its right substree so return left subtree
        {
            return trimBST(root->left,low,high);
        }
        if(root->val == low)   // we can't include roots left substree , but have to return root so, make left subtree NULL
        {
            root->left = NULL;
            root->right = trimBST(root->right,low,high);
            return root;
        }
        if(root->val == high)  // we can't include roots right substree , but have to return root so, make right subtree NULL
        {  
            root->right = NULL;
            root->left  = trimBST(root->left,low,high);
            return root;
        }
        // means lies between low and high
        root->right  = trimBST(root->right,low,high);
        root->left = trimBST(root->left,low,high);
        
        return root;
    }
};
// tc o(N) // N is the number of nodes in a BST
// sc o(N)
