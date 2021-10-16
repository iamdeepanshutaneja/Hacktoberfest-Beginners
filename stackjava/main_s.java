package stackjava;

public class main_s {

    public static void main(String[] args){
        
        
        StackX testStack = new StackX(10);

        testStack.push(52);
        testStack.push(51);
        testStack.push(5);
        testStack.push(6);


        System.out.println(testStack.peek());
        


    }
   

    
}



