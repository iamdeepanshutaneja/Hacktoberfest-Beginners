package queue;

public class LinearQueue {
    private int maxSize;
    private int [] queueArray;
    private int front;
    private int rear;
    private int nItems;

    public  LinearQueue(int s){
        maxSize = s;
        queueArray = new int [maxSize];
        front = 0;
        rear = -1;
        nItems = 0;

    }

    public void insert(int j){
        if(rear == (maxSize - 1))
            System.out.println("Queue is full");

        else{
            queueArray[++rear] = j;
            nItems++;
        }
    }

    public int remove(){
        if(nItems == 0){
            System.out.println("Queue is empty");
            return -99;
        }

        else{
            nItems--;
            return queueArray[front++];
        }
    }

    public int peekFront(){
        if(nItems == 0){
            System.out.println("Queue is empty");
            return -99;
        }
        else{
            return queueArray[front];
        }
    }
}
