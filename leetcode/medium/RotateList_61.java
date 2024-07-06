class ListNode {
    int val;
    ListNode next;

    public ListNode(int val) {
        this.val = val;
    }
}

public class RotateList_61 {

    static ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) 
            return head;

        ListNode oldTail = head;
        int length = 1;
        while (oldTail.next != null) {
            oldTail = oldTail.next;
            length++;
        }

        oldTail.next = head;

        int newTailIndex = (length - 1) - k % length;
        ListNode newTail = head;
        for (int i = 0; i < newTailIndex; i++) 
            newTail = newTail.next;
        
        ListNode newHead = newTail.next;

        newTail.next = null;

        return newHead;
    }

    static ListNode findTheSecondToLastNode(ListNode head) {
        if(head == null)
            return null;
        while (head.next.next != null) 
            head = head.next;
        return head;
    }


    static ListNode generateList(int m) {
        if (m <= 0) {
            return null;
        }

        ListNode head = new ListNode(0);
        ListNode j = head;
        for (int i = 1; i < m; i++) {
            j.next = new ListNode(i);
            j = j.next;
        }

        return head;
    }

    static void print(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListNode head = generateList(3);
        ListNode newHead = rotateRight(head, 4);
        print(newHead);
    }
}