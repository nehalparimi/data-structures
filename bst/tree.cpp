#include <iostream>

class TreeNode {
    
    public:
        int value;
        TreeNode *parent;
        TreeNode *left;
        TreeNode *right;

        TreeNode() {
            value = 0;
            parent = NULL;
            left = right = NULL;
        }

        TreeNode(int value, TreeNode *parent=NULL, TreeNode *left=NULL, TreeNode *right=NULL) {
            this->value = value;
            this->parent = parent;
            this->left = left;
            this->right = right;
        }

        TreeNode* search_tree_rec(TreeNode *root, int s_value) {
            // if (root == NULL) return NULL;

            if (root->value == s_value) return root;

            if (root->left && root->value > s_value) {
                return(search_tree_rec(root->left, s_value));
            }
            else if (root->right && root->value < s_value) {
                return(search_tree_rec(root->right, s_value));
            }
            else {
                std::cout << "The node of value " << root->value << " has no kids to match the value you gave it." <<
                    "This is the last stop on the bus" << std::endl;
                return root;
            }
        }

        TreeNode* search_tree_it(TreeNode* root, int s_value) {
            while(root->value != s_value) {
                if (root == NULL) return NULL;

                if (root->value > s_value) {
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
            return root;
        }

        TreeNode* minimum(TreeNode *root) {
            // extra check for the child nodes
            // but a necessary one for the main root
            if (root == NULL) return NULL;

            // this should work though
            if (root->left == NULL) return root;
            return(minimum(root->left));
        }

        TreeNode* maximum(TreeNode *root) {
            if (root == NULL) return NULL;

            // what's the point of this variable?
            // so we don't remove the reference to the root of the tree?
            TreeNode *max;
            max = root;
            while(max->right) {
                max = max->right;
            }
            return max;
        }

        void traverse(TreeNode *root) {
            // can this be implemented using a loop?
            // creating a new variable here creates space inefficiency?
            // is it unnecessary?


            // essentially the process for a single node with 2 kids too
            // get the left value (because it's always lesser)
            // get its own value (becasue its in the middle)
            // get the right value (because it's always greater)
            // micro level = macro level when recursion is involved because BSTs are recursive
            if (root != NULL) {
                traverse(root->left);
                std::cout << root->value << std::endl;
                traverse(root->right);
            }
        }

        // considering that for a given set of values there can be only one arrangement
        // of a binary search tree, insertion can be done by querying and inserting when it becomes null
        // because that's the position the item would've been in had it existed in the table

        static void insert(TreeNode **t, int value, TreeNode *parent) {

            TreeNode *root;
            if (*t == NULL) {
                root = (TreeNode*) malloc(sizeof(TreeNode));
                root->value = value;
                root->left = root->right = NULL;
                root->parent = parent;
                *t = root;
                return;
            }

            if ((*t)->value > value) {
                insert(&((*t)->left), value, *t);
            } 
            else {
                insert(&((*t)->right), value, *t);
            }
        }

        void delete_node(TreeNode* root, int d_value) {

            // first, find the node
            while (root->value != d_value) {
                if (root->value > d_value) {
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }

            if (root == NULL) return;

            // if root has no children

            TreeNode *parent = root->parent;

            // Check to see if root has one child or two
            // if one, then if the greater one is null, we can just add
            // could arrange the two grandchildren in either way
            if (root == parent->right) {
                parent->right = root->right == NULL ? root->left : root->right;
                parent->right->left = root->left;
            }
            else {
                parent->left = root->left == NULL ? root->right : root->left;
                parent->left->right = root->right;
            }
            free(root);

        }   

        static void traverse_tree(TreeNode *root) {
            if (root != NULL) {
                traverse_tree(root->left);
                std::cout << root->value << std::endl;
                traverse_tree(root->right);
                
            }
        }

        void delete_node_rec(TreeNode *root, int d_value, TreeNode *parent) {
            if (root == NULL) return;

            if (root->value == d_value) {
                // the core logic for the arrangement of the child nodes
                if (root == parent->right) {
                    parent->right = root->right == NULL ? root->left : root->right;
                    parent->right->left = root->left;
                }
                else {
                    parent->left = root->left == NULL ? root->right : root->left;
                    parent->left->right = root->right;
                }
                return;
            }

            if (root->value > d_value) {
                delete_node_rec(root->left, d_value, root);
            }
            else {
                delete_node_rec(root->right, d_value, root);
            }

        }
};


bool checkBST(TreeNode *root, TreeNode *parent=NULL) {
    if (root == NULL) return 1;

    if (root != NULL) {
        checkBST(root->left, root);
        checkBST(root->right, root);

        if (root == parent->left) {
            if (root->value > parent->value) return 0;
            else return 1;
        }
        else {
            if (root->value < parent->value) return 0;
            else return 1;
        }
    }
    return 0;
}

int main() {

    
    TreeNode tree(4);


    TreeNode *rt = &tree;
    TreeNode **l = &rt;
    
    TreeNode::insert(l, 1, NULL);
    TreeNode::insert(l, 2, NULL);
    TreeNode::insert(l, 3, NULL);
    // TreeNode::insert(rt, 1, NULL);
    // TreeNode::traverse_tree(rt);
    bool x = checkBST(rt);

    std::cout << x << std::endl;

}