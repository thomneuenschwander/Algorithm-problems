import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

import leetcode.TreeNode;


class BinaryTreeRightSideView_199 {

    public static TreeNode insert(int val, TreeNode i) {
        if(i == null){
            i = new TreeNode(val);
        }else if(val < i.val) {
            i.left = insert(val, i.left);
        }else {
            i.right = insert(val, i.right);
        }
        return i;
    }
    public static void showTree(TreeNode i){
        if(i != null) {
            showTree(i.left);
            System.out.print(i.val+" ");
            showTree(i.right);
        }
    }

    public static List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while(!queue.isEmpty())
        {
            int size = queue.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode node = queue.poll();

                if(i==size-1)res.add(node.val); 
                
                if(node.left!=null) queue.add(node.left);
                if(node.right!=null)queue.add(node.right);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        TreeNode root = null;

        int num = sc.nextInt();
        while(num != 0)
        {   
            root = insert(num, root);
            num = sc.nextInt();
        }
        List<Integer> list = rightSideView(root);
        System.out.println();
        for(int val : list) {
            System.out.print(val+" ");
        }
        sc.close();
    }
}