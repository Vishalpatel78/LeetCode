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
    int preorderIndex = 0;  // Pointer to the current element in preorder
    
    // Helper function to recursively build the tree
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int inorderLeft, int inorderRight, unordered_map<int, int>& inorderIndexMap) {
        if (inorderLeft > inorderRight) {
            return nullptr;  // Base case: No elements to process
        }
        
        // Get the root value from the preorder array
        int rootValue = preorder[preorderIndex++];
        
        // Create a new tree node with the root value
        TreeNode* root = new TreeNode(rootValue);
        
        // Find the index of the root in the inorder array
        int rootIndex = inorderIndexMap[rootValue];
        
        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(preorder, inorder, inorderLeft, rootIndex - 1, inorderIndexMap);
        root->right = buildTreeHelper(preorder, inorder, rootIndex + 1, inorderRight, inorderIndexMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a hashmap to store the index of each element in the inorder array
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }
        
        // Start the recursion with the full range of the inorder array
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1, inorderIndexMap);
    }
};