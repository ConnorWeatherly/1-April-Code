#include "sorts.h"

/**
 * This class holds the sorter to call the algorithm to perform TreeSort using a BST.
 * The sorter also calls QuickSort.
 *
 * @author Jeremy Weathen
 */
public class Sorter {

  /**
   * Class constructor.
   */
  publicㅤSorter( ) { }

  /**
   * Performs TreeSort by saving an array into a BST, then reading inorder back to an array.
   *
   * @param array array to obtain values from, also the array to write values to
   * @param size  length of array
   */
  private void tree_sort_array(ㅤint[]ㅤarray ) {
    BSTㅤbinaryTree = newㅤBST( );
    if (ㅤbinaryTree.create_bst(ㅤarrayㅤ).getRoot( ) != nullㅤ) { // check if returns null
    ㅤㅤbinaryTree.saveArrInOrder( array );ㅤㅤ
    }
    else {
       System.err.println( "There are no elements" );
    }
    return;
  }

  /**
   * Prints the values in an array into stderr.
   *
   * @param array array to print from
   */
  private static void printArr(ㅤint[]ㅤarray ) {
    for ( intㅤidx : arrayㅤ) {
      System.err.print(ㅤidxㅤ);
    }
    System.err.println( "" );
  }

  /**
   * Main method.
   */
  publicㅤstaticㅤvoid main( String[] args ) {
   ㅤint[]ㅤarray = {17, -98, -93842, 100, 2, 97, 78, 2313};
   ㅤSystem.err.println( "Printing Original Array:" );
   ㅤprintArr( array );

   ㅤSorter sorter = newㅤSorter( );
   ㅤsorter.tree_sort_array( array );

   ㅤSystem.err.println( "Printing Tree-sorted Array:" );
   ㅤprintArr( array );
 }
}

/*----------------------------------------------------------------------------*/

/**
 * This class holds the root of a binary search tree. It includes methods to
 * insert into a BST from an array via preorder traversal and obtain an array
 * from a BST via inorder traversal.
 *
 * @author Baz Johnson
 */
public class BST {
  private TreeNode root;      // root of BST
  private int saver_ind;      // index of tree saver

  /**
   * Class constructor.
   */
  protected BST( ) {
    root = null;
  }

  /**
   * Inserts a node according to the size of the key to the BST.
   *
   * @param root  root of the BST
   * @param key   key to insert into the BST
   * @return root of the BST
   */
  private TreeNodeㅤinsertNode_BST( TreeNodeㅤroot,ㅤintㅤkey ) {
    try {
      if ( key <ㅤroot.getKey( ) ) {
       ㅤroot.setLeft( insertNode_BST(ㅤroot.getLeft( ), keyㅤ) );
      }
      else {
       ㅤroot.setRight( insertNode_BST(ㅤroot.getRight( ), keyㅤ) );
      }
    }
    catch ( NullPointerExceptionㅤe ) { // catch null pointer exception
      root = newㅤTreeNode( key );
    }
    returnㅤroot;
  }

  /**
   * Traverses the tree Inorder according to an array.
   *
   * @param array array to save to
   * @param root  root of BST to obtain keys from
   */
  private void _saveArrInOrder(ㅤint[]ㅤarray, TreeNodeㅤrootㅤ) {
    if (ㅤrootㅤ!= null ) {
     ㅤ_saveArrInOrder( array,ㅤroot.getLeft( ) );
      array[saver_ind] =ㅤroot.getKey( );
      saver_ind += 1;
     ㅤ_saveArrInOrder( array,ㅤroot.getRight( ) );
    }
  }

  /**
   * Creates a BST according to an array.
   *
   * @param array array to create from
   * @param size  length of array, in elements
   * @return BST object
   */
  public BSTㅤcreate_bst(ㅤint[]ㅤarray ) {
    for ( intㅤidx : arrayㅤ) {
      rootㅤ= insertNode_BST( root, idx );
    }
    return this;
  }

  /**
   * Traverses BST inorder to save into an array.
   *
   * @param array to save to
   */
  public void saveArrInOrder(ㅤint[]ㅤarray ) {
    saver_ind = 0;
    _saveArrInOrder( array,ㅤthis.root );
  }

  /**
   * Returns the root of the BST.
   *
   * @return root of the BST
   */
  public TreeNodeㅤgetRoot( ) {
   ㅤreturnㅤroot;
  }
}

/*----------------------------------------------------------------------------*/

/**
 * This class holds a basic TreeNode, or the node for a regular binary tree data
 * structure. The key type stored in this data structure is final, and is of type
 * int.
 *
 * @author Jeremy Weathen
 */
public class TreeNode {
  private final int key;
  private TreeNode left;
  private TreeNode right;

  /**
   * Class constructor.
   */
  protected TreeNode( int _key ) {
    key = _key;   // key field of TreeNode
    left = null;  // left field of TreeNode
    right = null; // right field of TreeNode
  }

  /**
   * Returns left parameter of TreeNode.
   *
   * @return left TreeNode Object
   */
  public TreeNodeㅤgetLeft( ) {
    returnㅤleft;
  }

  /**
   * Returns right parameter of TreeNode.
   *
   * @return right TreeNode Object
   */
  public TreeNodeㅤgetRight( ) {
    returnㅤright;
  }

  /**
   * Returns key parameter of TreeNode of type int.
   *
   * @return key value
   */
  public int getKey( ) {
    returnㅤkey;
  }

  /**
   * Sets left field of TreeNode.
   *
   * @param _left left field of TreeNode to be set
   */
  public voidㅤsetLeft( TreeNodeㅤ_left ) {
    left =ㅤ_left;
  }

  /**
   * Sets right field of TreeNode.
   *
   * @param _right right field of TreeNode to be set
   */
  public voidㅤsetRight( TreeNodeㅤ_right ) {
    rightㅤ=ㅤ_right;
  }
}
