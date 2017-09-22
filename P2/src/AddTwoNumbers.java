public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(0);
        ListNode p = result, q = result;
        int digit = 0;
        while (l1 != null && l2 != null) {
            p = q;
            p.val = (digit + l1.val + l2.val) % 10;
            digit = (digit + l1.val + l2.val) / 10;
            q = new ListNode(0);
            p.next = q;
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null) {
            p = q;
            p.val = (digit + l1.val) % 10;
            digit = (digit + l1.val) / 10;
            q = new ListNode(0);
            p.next = q;
            l1 = l1.next;
        }
        while (l2 != null) {
            p = q;
            p.val = (digit + l2.val) % 10;
            digit = (digit + l2.val) / 10;
            q = new ListNode(0);
            p.next = q;
            l2 = l2.next;
        }
        if (l1 != null) digit += l1.val;
        if (l2 != null) digit += l2.val;
        while (digit > 0) {
            p = q;
            p.val = digit % 10;
            digit /= 10;
            q = new ListNode(0);
            p.next = q;
        }
        p.next = null;
        return result;
    }
}