public class BubbleSort {
	public static void main(String[] args) {
BubbleSort b = new BubbleSort();
		int arrs[] = {64, 34, 25, 12, 22, 11, 90};
b.bubbleSort(arrs);
		System.out.println("Sorted Array ");
		System.out.println(Arrays.toString(arrs));
	}
    public static void bubbleSort(int[] arr){
		int size = array.length;

		for (int i = 0; i < size -1; i++){
			boolean swipped = false;
			System.out.println("Firsr swiped" + swipped);
			for (int j = 0; j < size - i -1; j++){
				if (array[j] > array[j+1]){
					int temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
					swipped = true;
					System.out.println(swipped);
				}
			}

			if (!swipped){
				break;
			}
		}
    }

}
