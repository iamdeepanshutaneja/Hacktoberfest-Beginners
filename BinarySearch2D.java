package com.beastrun12j;

import java.util.Arrays;
import java.util.Scanner;

public class BinarySearch2D {
    public static void main(String[] args) {
        int[][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        System.out.println(Arrays.toString(RowColSearch(arr, n)));
        System.out.println(Arrays.toString(binarySearch2D(arr, n)));
    }

    /**
     * Algorithm for 2D Binary Search if the Matrix is Row and Column Wise Sorted
     * Time Complexity: O(M + N)
     */

    private static int[] RowColSearch(int[][] arr, int target) {
        int r = 0;
        int c = arr.length - 1;
        while(r < arr.length && c >= 0) {
            if(arr[r][c] == target) {
                return new int[] {r, c};
            } else if(arr[r][c] < target) {
                r++;
            } else{
                c--;
            }
        }
        return new int[] {-1, -1};
    }

    /**
     * Algorithm for 2D Binary Search if the Matrix is Strictly Sorted
     * Time Complexity: O(log(M + N))
     */

    private static int[] binarySearch2D(int[][] arr, int target) {
        int rows = arr.length;
        int cols = arr[0].length;
        int colStart = 0;
        int colEnd = cols - 1;
        int rowStart = 0;
        int rowEnd = rows - 1;
        int colMid = cols/2;

        if (cols == 0){
            return new int[] {-1,-1};
        }

        // Traverse through the matrix to reduce the size of matrix to 2 rows
        while(rowStart < rowEnd - 1) {
            int rowMid = rowStart + (rowEnd - rowStart)/2;
            if(arr[rowMid][colMid] == target) {
                return new int[] {rowMid, colMid};
            } else if(arr[rowMid][colMid] < target) {
                rowStart = rowMid;
            } else {
                rowEnd = rowMid;
            }
        }

        // Search for the target in the middle Column
        if(arr[rowStart][colMid] == target) {
            return new int[] {rowStart, colMid};
        } else if(arr[rowEnd][colMid] == target) {
            return new int[] {rowEnd, colMid};
        }

        // Search for the target in the four leftover sections of matrix
        if(target <= arr[rowStart][colMid - 1]) {
            return binarySearch(arr, colStart, colMid - 1, rowStart, target);
        } else if(target >= arr[rowStart][colMid + 1] && target <= arr[rowStart][colEnd]) {
            return binarySearch(arr, colMid + 1, colEnd, rowStart, target);
        } else if(target <= arr[rowEnd][colMid - 1]) {
            return binarySearch(arr, colStart, colMid - 1, rowEnd, target);
        } else{
            return binarySearch(arr, colMid + 1, colEnd, rowEnd, target);
        }
    }

    private static int[] binarySearch(int[][] arr, int colStart, int colEnd, int row,int target) {
        while(colStart <= colEnd) {
            int mid = colStart + (colEnd - colStart)/2;
            if(arr[row][mid] == target) {
                return new int[] {row, mid};
            } else if(arr[row][mid] < target) {
                colStart = mid + 1;
            } else {
                colEnd = mid - 1;
            }
        }
        return new int[] {-1, -1};
    }

}

