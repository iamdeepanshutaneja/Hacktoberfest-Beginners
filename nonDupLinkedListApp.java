
/**
 *
 * @author Lakshitha Samod
 */
public class nonDupLinkedListApp {

    public static void main(String[] args) {
        LinkList x = new LinkList();
        x.insert(5);
        x.insert(9);
        x.insert(3);
        x.insert(5);
        x.insert(7);

        x.display();

        x.delete(5);
        x.display();

        x.insert(5);
        x.display();
        x.reverse();
        x.display();

        System.out.println(x.find(0));
        System.out.println(x.find(5));

    }
}

class Node {

    long data;
    Node next;

    Node(long item) {
        this.data = item;
        this.next = null;
    }

    void displayNode() {
        System.out.print(this.data + " ");
    }
}

class LinkList {

    private Node head;

    public LinkList() {
        head = null;
    }

    public void insert(long i) {
        if (find(i)) {
            System.out.println("Value already exits. Insertion Terminated");
            return;
        }

        Node newNode = new Node(i);
        newNode.next = head;
        head = newNode;

    }

    public boolean find(long value) {
        Node current = head;
        while (current != null) {
            if (current.data == value) {
                return true;
            }
            current = current.next;
        }
        //System.out.println("item not found");
        return false;
    }

    public boolean delete(long value) {
        Node current = head;
        Node prev = head;
        int count = 1;
        while (current != null) {
            if (current.data == value) {
                if (count == 1) {
                    head = head.next;
                } else {
                    prev.next = current.next;
                }
                System.err.println("Item deleted");
                return true;
            }
            prev = current;
            current = current.next;
            count++;
        }
        System.out.println("item not found. Deletion terminated.");
        return false;
    }

    public void display() {
        System.out.println("Displaying the array list... ");
        Node current = head;
        while (current != null) {
            current.displayNode();
            current = current.next;
        }
        System.out.println();
    }

    public void reverse() {
        System.out.println("Reversing the array list... ");
        Node current = head;
        Node next = null;
        Node prev = null;        
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

}
