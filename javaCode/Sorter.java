/**
 * This class holds the sorter to call the algorithm to perform TreeSort using a BST.
 * The sorter also calls QuickSort.
 *
 * @author Baz Johnson
 */
public class Sorter {

    /**
     * Class constructor.
     */
    public Sorter() {}

    /**
     * Performs TreeSort by saving an array into a BST, then reading inorder back to an array.
     *
     * @param array array to obtain values from, also the array to write values to
     * @param size  length of array=
     */
    private void tree_sort_array(int[] array, int size) {
        BST binaryTree = new BST();
        if (binaryTree.create_bst(array, size).getRoot() != null) { // check if returns null
            binaryTree.saveArrInOrder(array);
        }
        else {
            System.err.println("There are no elements");
        }
        return;
    }

    /**
     * Prints the values in an array into stderr.
     *
     * @param array array to print from
     */
    private static void printArr(int[] array) {
        for (int idx : array) {
            System.err.print(idx);
        }
        System.err.println();
    }

    /**
     * Main method.
     */
    public static void main(String[] args) {
        // test array
        int[] array = {0, 1, 2, 4, 3};
        System.err.println("Printing Original Array:");
        printArr(array);

        // use tree-sort
        Sorter sorter = new Sorter();
        sorter.tree_sort_array(array, array.length);

        // print final array
        System.err.println("Printing Tree-sorted Array:");
        printArr(array);
    }
}
