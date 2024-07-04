import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Nodle{
    private Nodle left, right;
    private int number;

    public Nodle(){
        left = right = null;
    }
    public Nodle(int x){
        left = right = null;
        number = x;
    }
    public Nodle getLeft() {
        return left;
    }
    public void setLeft(Nodle left) {
        this.left = left;
    }
    public Nodle getRight() {
        return right;
    }
    public void setRight(Nodle right) {
        this.right = right;
    }
    public int getNumber() {
        return number;
    }
    public void setNumber(int number) {
        this.number = number;
    }
}

class BST {
    private Nodle root;

    public BST(){
        root = null;
    }

    public void inOrder(){
        inOrder(root);
    }
    private void inOrder(Nodle i){
        if(i != null) {
            inOrder(i.getLeft());
            System.out.print(i.getNumber()+" ");
            inOrder(i.getRight());
        }
    }
    public void insert(int x){
        root = insert(root, x);
    }
    private Nodle insert(Nodle i, int x){
        if(i == null){
            i = new Nodle(x);
        }else if(x < i.getNumber()){
            i.setLeft(insert(i.getLeft(), x));
        }else if(x > i.getNumber()){
            i.setRight(insert(i.getRight(), x));
        }
        return i;
    }

    public void LevelOrderTreeTraversal(){
        if(root == null) return;

        Queue<Nodle> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) 
        {
            Nodle j = queue.poll();

            System.out.print(j.getNumber()+" ");

            if(j.getLeft() != null){
                queue.add(j.getLeft());
            }
            if(j.getRight() != null){
                queue.add(j.getRight());
            }
        }
        System.out.println();
    }
}

class LevelOrderTreeTraversal_1466 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int C = sc.nextInt();
        for(int c = 1; c <= C; c++)
        {
            BST bst = new BST();

            int N = sc.nextInt();

            for(int i = 0; i < N; i++){
                bst.insert(sc.nextInt());
            }
            System.out.println();
            bst.LevelOrderTreeTraversal();
        }
        sc.close();
    }
}
