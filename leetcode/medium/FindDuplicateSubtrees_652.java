import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import leetcode.TreeNode;

public class FindDuplicateSubtrees_652 {

    static List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        List<TreeNode> duplicates = new LinkedList<>();
        traversal(root, new HashMap<>(), duplicates);
        return duplicates;
    }

    static String traversal(TreeNode current, Map<String, Integer> map, List<TreeNode> duplicates) {
        if(current == null)
            return ".";
        
        String left = traversal(current.left, map, duplicates);
        String right = traversal(current.right, map, duplicates);

        String serial = current.val + "^" + left + "^" + right;
        
        map.put(serial, map.getOrDefault(serial, 0) + 1);

        if(map.get(serial) == 2)
            duplicates.add(current);

        return serial;
    }

    public static void main(String[] args) {
        TreeNode root = buildExemple03Tree();

        List<TreeNode> duplicates = findDuplicateSubtrees(root);

        duplicates.forEach(node -> {
            System.out.println(node.val);
        });
    }

    static TreeNode buildExemple01Tree() {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(4);
        root.right = new TreeNode(3);
        root.right.left = new TreeNode(2);
        root.right.left.left = new TreeNode(4);
        root.right.right = new TreeNode(4);
        return root;
    }

    static TreeNode buildExemple02Tree() {
        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(1);
        return root;
    }

    static TreeNode buildExemple03Tree() {
        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.right = new TreeNode(1);
        root.right.left = new TreeNode(3);
        return root;
    }
}

 
