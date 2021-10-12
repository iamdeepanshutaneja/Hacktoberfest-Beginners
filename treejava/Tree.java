package tree;

public class Tree {
    private Node root;
    public Tree(){
        root = null;

    }
    public Node find(int key){
        Node current = root;
        while(current.iData != key){
            if(key < current.iData)
                current = current.leftChild;
            else
                current = current.rightChild;
            if(current == null)
                return null;
        }
        return current;
    }

    public void insert(int id, double dd){
        Node newNode = new Node();
        newNode.iData = id;
        newNode.dData = dd;
        if(root == null)
            root = new Node();
        else{
            Node current = root;
            Node parent;
            while(true){
                parent = current; 
                if(id< current.iData){
                    current = current.leftChild;
                    if(current == null){
                        parent.leftChild = newNode;
                        return;
                    }
                }
                else{
                    current = current.rightChild;
                    if(current == null){
                        parent.rightChild = newNode;
                        return;
                    }
                }
            }
        }
    }

    public void inOrder(Node localRoot){
        if(localRoot != null){
            inOrder(localRoot.leftChild);
            localRoot.displayNode();
            inOrder(localRoot.rightChild);
        }
    
    }

    public void preOrder(Node localRoot){
        if(localRoot != null){
            localRoot.displayNode();
            preOrder(localRoot.leftChild);
            preOrder(localRoot.rightChild);

        }
    }

    public void postOrder(Node localRoot){
        if(localRoot != null){
            postOrder(localRoot.leftChild);
            postOrder(localRoot.rightChild);
            localRoot.displayNode();
        }
    }

    
}
