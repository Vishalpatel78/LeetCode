/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root == null){
            return ans;
        }
        boolean check = true;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(! q.isEmpty()){
            int n = q.size();
            List<Integer> level = new ArrayList<>();
            for(int i=0; i<n; i++){
                TreeNode curnt = q.poll();
                if(check == true){
                    level.add(curnt.val);
                    if(curnt.left != null)q.offer(curnt.left);
                    if(curnt.right != null)q.offer(curnt.right);

                }
                else{
                    level.add(0,curnt.val);
                    if(curnt.left != null)q.offer(curnt.left);
                    if(curnt.right != null)q.offer(curnt.right);
                }
                   
                
            }
            check = !check; 
            ans.add(level);
        }
        return ans;
    }
}