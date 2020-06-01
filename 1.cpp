/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

/*
 Appraoch:
 1. Add root node in queue.
 2. Remove front element
 3. Swap left and right of this node
 4. Push left and right nodes.
 Perform 2 3 4 while queue is not empty
 
*/

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root ||(!root->left && !root->right))
            return root;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* left=NULL,*right=NULL;
            TreeNode* curr = q.front();
            q.pop();
           
               //int size  = q.size();
          if(curr->left)
            {
                left = curr->left;
                q.push(left);
            }
            if(curr->right)
            {
                right = curr->right;
                q.push(right);
            }
            curr->left = right;
            curr->right = left;
                
        }
        return root;
    }
};
