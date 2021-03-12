
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void inorder1(TreeNode* root , vector<int>&ans)
    {
        if(root == NULL)
        {
            return;
        }
        inorder1(root->left,ans);
        root->val = ans.back();
        ans.pop_back();
        inorder1(root->right,ans);
    }
    TreeNode* bstToGst(TreeNode* root)
    {
        vector<int>ans;
        if(root == NULL)
        {
            return NULL;
        }
        inorder(root, ans);
        reverse(ans.begin(),ans.end());
        for(int i = 1; i < ans.size(); i++)
        {
            ans[i] += ans[i - 1];
        }
        
        inorder1(root, ans);
        return root;
    }
};

// tc o(n)
// sc o(n)

// OR



class Solution {
public:
    int sum = 0;
    void inorder(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root->right);
        sum += root->val;
        root->val = sum;
        inorder(root->left);
    }

    TreeNode* bstToGst(TreeNode* root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        inorder(root);
        return root;
    }
};

// tc o(n)
// sc o(1)
