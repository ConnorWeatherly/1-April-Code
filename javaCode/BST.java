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
    public BST() {
        root = null;
    }

    /**
     * Inserts a node according to the size of the key to the BST.
     *
     * @param root  root of the BST
     * @param key   key to insert into the BST
     * @return root of the BST
     */
    private TreeNode insertNode_BST(TreeNode root, int key) {
        if (root == null) {
            root = new TreeNode(key);
        }
        else if (key < root.getKey()) {
            root.setLeft(insertNode_BST(root.getLeft(), key));
        }
        else {
            root.setRight(insertNode_BST(root.getRight(), key));
        }
        return root;
    }

    /**
     * Traverses the tree Inorder according to an array.
     *
     * @param array array to save to
     * @param root  root of BST to obtain keys from
     */
    private void _saveArrInOrder(int[] array, TreeNode root) {
        if (root != null) {
            _saveArrInOrder(array, root.getLeft());
            array[saver_ind] = root.getKey();
            saver_ind += 1;
            _saveArrInOrder(array, root.getRight());
        }
    }

    /**
     * Creates a BST according to an array.
     *
     * @param array array to create from
     * @param size  length of array, in elements
     * @return BST object
     */
    public BST create_bst(int[] array, int size) {
        for(int i = 0; i < size; i += 1) {
            root = insertNode_BST(root, array[i]);
        }
        return this;
    }

    /**
     * Traverses BST inorder to save into an array.
     *
     * @param array to save to
     */
    public void saveArrInOrder(int[] array) {
        saver_ind = 0;
        _saveArrInOrder(array, this.root);
    }

    /**
     * Returns the root of the BST.
     *
     * @return root of the BST
     */
    public TreeNode getRoot() {
        return root;
    }
}