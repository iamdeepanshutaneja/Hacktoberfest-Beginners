package queue;

public class CircularQueue {

    private int maxSize;
    private int [] queueArray; 
    private int front;
    private int rear;
    private int nItems;
    
    public  CircularQueue(int s){
        maxSize = s;
        queueArray = new int [maxSize];
        front = 0;
        rear = -1;
        nItems = 0;
    }

    public void insert(int j){
        if(nItems == maxSize)
            System.out.println("Queue is full");
        else{
            if(rear == (maxSize -1))
                rear = -1;
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
            int temp = queueArray[front++];
            if(front == maxSize)
                front = 0;
            nItems--;
            return temp;
        }
    }


    
}
