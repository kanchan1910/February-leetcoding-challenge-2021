
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0 ; i < n ; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                if(i == n - 1)
                {
                    ans.push_back(front->val);
                }
                if(front->left != NULL)
                {
                    q.push(front->left);
                }
                if(front->right != NULL)
                {
                    q.push(front->right);
                }
            }
        }
        return ans;
    }
};
            
           // tc o(n)
           // sc o(n)
