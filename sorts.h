#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/* invisible character */
/* (ㅤ) Unicode value <U+3164> */

/*----------------------------------------------------------------------------*/

/* universal replacements */
#define class union
#define null NULL
#define final
#define public
#define protected }; void
#define private
#define new

typedef struct {
  void (*println)(int, ...);
  void (*print)(int, ...);
} stdOut;

typedef struct {
  void (*println)(int, ...);
  void (*print)(int, ...);
} stdErr;

typedef struct {
  stdOut out;
  stdErr err;
} mainStruct;

#define dataType(var) _Generic((var),\
  char:     'c',\
  int:      'i',\
  char*:    's',\
  float:    'f',\
  double:   'd',\
  default:  'e')

static mainStruct System;

#define println(args, ...) println(dataType(args), args, ##__VA_ARGS__)
#define print(args, ...) print(dataType(args), args, ##__VA_ARGS__)

void printlnStd(int typeCode, ...) {
  va_list args;
  va_start(args, typeCode);
  switch(typeCode) {
    case 'c': fprintf(stdout, "%c", (char) va_arg(args, int));
              break;
    case 'i': fprintf(stdout, "%d", va_arg(args, int));
              break;
    case 's': vfprintf(stdout, va_arg(args, char*), args);
              break;
    case 'f': fprintf(stdout, "%f", va_arg(args, double));
              break;
    case 'd': fprintf(stdout, "%lf", va_arg(args, double));
              break;
  }
  va_end(args);
  fprintf(stdout, "\n");
}

void printStd(int typeCode, ...) {
  va_list args;
  va_start(args, typeCode);
  switch(typeCode) {
    case 'c': fprintf(stdout, "%c", (char) va_arg(args, int));
              break;
    case 'i': fprintf(stdout, "%d", va_arg(args, int));
              break;
    case 's': vfprintf(stdout, va_arg(args, char*), args);
              break;
    case 'f': fprintf(stdout, "%f", va_arg(args, double));
              break;
    case 'd': fprintf(stdout, "%lf", va_arg(args, double));
              break;
  }
  va_end(args);
  fprintf(stdout, " ");
}

void printlnErr(int typeCode, ...) {
  va_list args;
  va_start(args, typeCode);
  switch(typeCode) {
    case 'c': fprintf(stderr, "%c", (char) va_arg(args, int));
              break;
    case 'i': fprintf(stderr, "%d", va_arg(args, int));
              break;
    case 's': vfprintf(stderr, va_arg(args, char*), args);
              break;
    case 'f': fprintf(stderr, "%f", va_arg(args, double));
              break;
    case 'd': fprintf(stderr, "%lf", va_arg(args, double));
              break;
  }
  va_end(args);
  fprintf(stderr, "\n");
}

void printErr(int typeCode, ...) {
  va_list args;
  va_start(args, typeCode);
  switch(typeCode) {
    case 'c': fprintf(stderr, "%c", (char) va_arg(args, int));
              break;
    case 'i': fprintf(stderr, "%d", va_arg(args, int));
              break;
    case 's': vfprintf(stderr, va_arg(args, char*), args);
              break;
    case 'f': fprintf(stderr, "%f", va_arg(args, double));
              break;
    case 'd': fprintf(stderr, "%lf", va_arg(args, double));
              break;
  }
  va_end(args);
  fprintf(stderr, " ");
}

/*----------------------------------------------------------------------------*/

/* TreeNode replacements */
typedef struct _TreeNode {
  int key;
  struct _TreeNode* left;
  struct _TreeNode* right;
  void (*setKey)(int);
  void (*setLeft)(struct _TreeNode*);
  void (*setRight)(struct _TreeNode*);
  int (*getKey)();
  struct _TreeNode* (*getLeft)();
  struct _TreeNode* (*getRight)();

} TreeNode;

void setTreeNode(int _key);
TreeNode* getLeft();
TreeNode* getRight();
int getKey();
void setLeft(TreeNode* _left);
void setRight(TreeNode* _right);
void setKey(int _key);

static TreeNode* root;
static TreeNode* saver;
static TreeNode* left;
static TreeNode* right;
static int key;

#define TreeNode(arg)  setTreeNode(arg)
#define TreeNodeㅤgetLeft() TreeNode* getLeft()
#define returnㅤleft return root->left
#define TreeNodeㅤgetRight() TreeNode* getRight()
#define returnㅤright return root->right
#define returnㅤkey return root->key
#define voidㅤsetLeft(TreeNodeㅤ_left) void setLeft(TreeNode* _left)
#define ㅤ_left \
        _left; \
        if (root->left == NULL && root->right == NULL) \
          saver->left = root
#define voidㅤsetRight(TreeNodeㅤ_right) void setRight(TreeNode* _right)
#define rightㅤ \
        if(1) { \
          right
#define ㅤ_right \
        _right; \
        if (root->left == NULL && root->right == NULL) \
          saver->right = root

TreeNode* setNode(int key) {
  TreeNode* node = malloc(sizeof(*node));

  *node = (TreeNode) {.left = NULL, .right = NULL, .key = key, .getKey = getKey,
                      .getLeft = getLeft, .getRight = getRight,
                      .setLeft = setLeft, .setRight = setRight};
  return node;
}

/*----------------------------------------------------------------------------*/

/* BST replacements */
typedef struct _BST {
  TreeNode* root;
  TreeNode* (*insertNode_BST)(TreeNode*, int);
  struct _BST* (*create_bst)(int*);
  void (*saveArrInOrder)(int*);
  TreeNode* (*getRoot)();
} BST;

void setBST();
TreeNode* insertNode_BST(TreeNode* root, int key);
void _saveArrInOrder(int array[], TreeNode* root);
BST* create_bst(int array[]);
void saveArrInOrder(int array[]);
TreeNode* getRoot();

static BST* this;
static int saver_ind;
static int size;

#define BST() setBST()
#define try \
        root = rootHold; \
        if (root != NULL) { \
          saver = root; \
        } \
        if (root != NULL)
#define TreeNodeㅤinsertNode_BST(TreeNodeㅤroot,ㅤintㅤkey) \
        TreeNode* insertNode_BST(TreeNode* rootHold, int key)
#define ㅤroot (*root)
#define keyㅤ key
#define catch \
        if (root != NULL) { \
          root = rootHold; \
        } \
        else if
#define NullPointerExceptionㅤe 1
#define newㅤTreeNode( key ) setNode(key)
#define returnㅤroot return root
#define ㅤint int array
#define ㅤarray
#define TreeNodeㅤrootㅤ TreeNode* rootHold
#define BSTㅤcreate_bst BST* create_bst
#define rootㅤ \
        root = this->root; \
        if (this->root == NULL) { \
          this->root = insertNode_BST(this->root, array[i]); \
        } \
        else \
          root
#define ㅤthis (*this)
#define ㅤrootㅤ (root = rootHold)
#define ㅤ_saveArrInOrder(array,ㅤdirection) \
        _saveArrInOrder(array,ㅤdirection); \
        root = rootHold
#define BSTㅤbinaryTree BST* binaryTree
#define TreeNodeㅤgetRoot TreeNode* getRoot
#define ㅤreturnㅤroot \
        return this->root; \
        if (1) {

/*----------------------------------------------------------------------------*/

/* Sorter replacement */
typedef struct {
  void (*tree_sort_array)(int*);
} Sorter;


void tree_sort_array(int array[]);
static void printArr(int array[]);
void freeNodes(BST* BSTNode);
Sorter makeSorter();

#define publicㅤSorter }; void sortHold
#define newㅤBST() createBST()
#define ㅤbinaryTree (*(*binaryTree)
#define ㅤㅤbinaryTree (*binaryTree)
#define ㅤarrayㅤ array)
#define nullㅤ NULL
#define ㅤㅤ freeNodes(binaryTree);
#define intㅤidx int i = 1 ? 0
#define arrayㅤ 1; i < size; i += 1
#define ㅤidxㅤ array[i]
#define idx array[i]
#define publicㅤstaticㅤvoid int
#define String int argc, char* argv
#define args
#define main(arg) \
        main(arg) { \
          System.out.println = printlnStd; \
          System.out.print = printStd; \
          System.err.println = printlnErr; \
          System.err.print = printErr; \
          if(1)
#define ㅤSystem System
#define ㅤprintArr \
        size = sizeof(array)/sizeof(*array); \
        printArr
#define ㅤSorter Sorter
#define newㅤSorter makeSorter
#define ㅤsorter sorter
#define array٫ㅤarray array, *sizeHold

BST* createBST() {
  BST* newBST = malloc(sizeof(*newBST));
  *newBST = (BST) {.root = NULL, .insertNode_BST = insertNode_BST, .create_bst = create_bst,
                  .saveArrInOrder = saveArrInOrder, .getRoot = getRoot};
  this = newBST;
  return newBST;
}

void freeTreeNodes(TreeNode* head) {
  if (head != NULL) {
    freeTreeNodes(head->left);
    freeTreeNodes(head->right);
    free(head);
  }
}
void freeNodes(BST* BSTNode) {
  freeTreeNodes(BSTNode->root);
  free(BSTNode);
  return;
}

Sorter makeSorter() {
  return (Sorter) {.tree_sort_array = tree_sort_array};
}
