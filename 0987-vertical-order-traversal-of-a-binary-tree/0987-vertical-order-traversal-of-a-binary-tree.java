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

    class NodeInfo {
        int val;
        int row;
        int col;

        NodeInfo(int val, int row, int col) {
            this.val = val;
            this.row = row;
            this.col = col;
        }
    }

    List<NodeInfo> nodes = new ArrayList<>();

    public List<List<Integer>> verticalTraversal(TreeNode root) {

        DFS(root, 0, 0);

        // Sort by column, then row, then value
        nodes.sort((a, b) -> {

            if (a.col != b.col) {
                return Integer.compare(a.col, b.col);
            }

            if (a.row != b.row) {
                return Integer.compare(a.row, b.row);
            }

            return Integer.compare(a.val, b.val);
        });

        List<List<Integer>> result = new ArrayList<>();

        int currentCol = nodes.get(0).col;

        List<Integer> column = new ArrayList<>();

        for (NodeInfo node : nodes) {

            if (node.col != currentCol) {

                result.add(column);

                column = new ArrayList<>();

                currentCol = node.col;
            }

            column.add(node.val);
        }

        result.add(column);

        return result;
    }


    public void DFS(TreeNode root, int row, int col) {

        if (root == null) {
            return;
        }

        nodes.add(new NodeInfo(root.val, row, col));

        DFS(root.left, row + 1, col - 1);

        DFS(root.right, row + 1, col + 1);
    }
}