public class Sorts {

  public Sorts() {}
  public void tree_sort_array(int[] array, int size) {
    BST binaryTree = new BST();
    if (binaryTree.create_bst(array, size).root != null) { // check if returns null
      System.out.println("There are elements");
      binaryTree.saveInOrder(array);
    }
    return;
  }

  public static void main(String[] str) {
    int[] array = {};//{0, 1, 2, 4, 3};
    int size = 0;
    for (int i = 0; i < size; i += 1) {
      System.out.print(array[i]);
    }
    if (size != 0) System.out.println("");

    Sorts sorter = new Sorts();
    sorter.tree_sort_array(array, size);

    for (int i = 0; i < size; i += 1) {
      System.out.print(array[i]);
    }
    if (size != 0) System.out.println("");
  }
}

public class Node {
  int key;
  Node left;
  Node right;
  public Node (int data) {
    key = data;
    left = null;
    right = null;
  }
}

public class BST {
  Node root;
  int index;

  public BST() {
    root = null;
  }

  public BST create_bst(int[] array, int size) {
    for(int i = 0; i < size; i += 1) {
      root = insertPreOrder(root, array[i]);
    }
    return this;
  }

  private Node insertPreOrder(Node root, int key) {
    if (root == null) {
      root = new Node(key);
    }
    else if (key < root.key) {
      root.left = insertPreOrder(root.left, key);
    }
    else {
      root.right = insertPreOrder(root.right, key);
    }
    return root;
  }

  public void saveInOrder(int[] array) {
    index = 0;
    inOrderSave(array, this.root);
  }

  private void inOrderSave(int[] array, Node root) {
    if (root != null) {
      inOrderSave(array, root.left);
      array[index] = root.key;
      index += 1;
      inOrderSave(array, root.right);
    }
  }
}
