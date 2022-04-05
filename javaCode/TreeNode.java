/**
 * This class holds a basic TreeNode, or the node for a regular binary tree data
 * structure. The key type stored in this data structure is final, and is of type
 * int.
 *
 * @author Baz Johnson
 */
public class TreeNode {
    private final int key;      // key field of TreeNode
    private TreeNode left;      // left field of TreeNode
    private TreeNode right;     // right field of TreeNode

    /**
     * Class constructor.
     */
    public TreeNode (int _key) {
        key = _key;
        left = null;
        right = null;
    }

    /**
     * Returns left parameter of TreeNode.
     *
     * @return left TreeNode Object
     */
    public TreeNode getLeft() {
        return left;
    }

    /**
     * Returns right parameter of TreeNode.
     *
     * @return right TreeNode Object
     */
    public TreeNode getRight() {
        return right;
    }

    /**
     * Returns key parameter of TreeNode of type int.
     *
     * @return key value
     */
    public int getKey() {
        return key;
    }

    /**
     * Sets left field of TreeNode.
     *
     * @param _left left field of TreeNode to be set
     */
    public void setLeft (TreeNode _left) {
        left = _left;
    }

    /**
     * Sets right field of TreeNode.
     *
     * @param _right right field of TreeNode to be set
     */
    public void setRight(TreeNode _right) {
        right = _right;
    }
}