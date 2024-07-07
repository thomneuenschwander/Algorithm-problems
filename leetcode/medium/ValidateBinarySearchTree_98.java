import leetcode.TreeNode;

public class ValidateBinarySearchTree_98 {

    boolean isValidBST(TreeNode root) {
        return isValidBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    boolean isValidBST(TreeNode node, int minVal, int maxVal) {
        if (node == null)
            return true;
        
        if(node.val <= minVal || node.val >= maxVal)
            return false;
    
        return isValidBST(node.left, minVal, node.val) && isValidBST(node.right, node.val, maxVal);
    }
}
