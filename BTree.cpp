/*
 * Binary Tree - source file (functions implementation)
 */

#include "BTree.h"
#include <vector>
#include <queue>
#include <stack>
#include <vector>


// output operator - tree
ostream& operator<<(ostream& out, BTree& tree)
{
    // call the print_level_by_level function
    tree.print_level_by_level(out);
    return out;
}

// output operator - node
ostream& operator<<(ostream& out, Node& node)
{
    out << "( "
        << node.value
        << ", "
        << node.search_cost
        << " )";
    return out;
}

// input operator
istream& operator>>(istream& in, BTree& tree)
{
    /*
        take input from the in stream, and build your tree

        input will look like
        4 
        2 
        6 
        1 
        3 
        5 
        7
    */

    int val;

    // loop through each line of the input file
    while (!in.eof())
    {
        in >> val;
        tree.insert(val);   // insert each value into the BTree
    }

    return in;
}


// copy constructor
BTree::BTree(const BTree& other)
{
    
    //    complete this copy constructor
    //    make sure when copying nodes to copy
    //    - value
    //    - left and right children

    if (other.get_root() == nullptr) // if the old tree is empty
    { 
        size = 0;
        root = nullptr;
    }
    else // if the old tree is NOT empty
    { 
        // instantiate a queue of type Node* and push other.root onto it
        queue<Node*> q;
        q.push(other.get_root());

        // while the queue is NOT empty
        while (!(q.empty()))
        {
            // create temporary pointer 
            Node *temp = q.front();
            q.pop();

            // insert the value of the current node
            insert(temp->value);

            // if there is a child node to the left, push it onto the queue
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            // if there is a child node to the right, push it onto the queue
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
    }
    
}


// move constructor
BTree::BTree(BTree&& other)
{
    root = other.get_root();  // set the root pointer of the new BTree to point to the root of the old BTree
    size = other.get_size();  // update the size variable of the new BTree
    

    other.set_root(nullptr);  // reset the root pointer of the old BTree (i.e. remove nodes from old BTree)
    other.update_size();      // reset the size variable of the old BTree
}


// copy assignment operator
BTree& BTree::operator=(const BTree& other)
{
    if (this != &other) {
        
        //    complete this assignment operator
        //    make sure when copying nodes to copy
        //    - value
        //    - left and right children

        // if the old BTree is empty
        if (other.get_root() == nullptr) {
            size = 0;
            root = nullptr;
            return *this;
        }

        // instantiate a queue of type Node* and push other.root onto it
        queue<Node*> q;
        q.push(other.get_root());

        // while the queue is NOT empty
        while (!(q.empty()))
        {
            // create temporary pointer
            Node *temp = q.front();
            q.pop();

            // insert the value of the current node
            insert(temp->value);

            // if there is a child node to the left, push it onto the queue
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            // if there is a child node to the right, push it onto the queue
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
        
    }
    return *this;
}

// move assignment operator
BTree& BTree::operator=(BTree&& other)
{
    // if the BTree's are the same, no operation is to be performed
    if (this != &other) {
        size = other.get_size();  // set the root pointer of the new BTree to point to the root of the old BTree
        root = other.get_root();  // update the size variable of the new BTree

        other.set_root(nullptr);  // reset the root pointer of the old BTree (i.e. remove nodes from old BTree)
        other.update_size();      // reset the size variable of the old BTree
    }
    return *this;
}

// insert function
Node* BTree::insert(int obj)
{
    // update the size variable of the BTree. (just a precaution against bizarre errors)
    update_size();
  
    // instantiate node to be inserted
    Node *new_node = new Node(obj);

    // if the BTree is empty, insert the new node as the new root
    if (root == nullptr)
    {
        root = new_node;  // insert node at root
        size++;           // increment BTree size variable
        new_node->search_cost = 1;   // the search cost of the root of a BTree is always 1
        return new_node;
    }

    // declare temporary Node* variable
    Node *temp = root;


    // find where the new node should go and insert it
    while ( temp != nullptr ) 
    {
        // if 'obj' is less then the value of the current node, it must be inserted somewhere to the left of the current node
        if (obj < temp->value)
        {
            // if 'obj' must be inserted to the left of 'temp' and there are no elements to the left of temp, insert the new node at 'temp->left'
            if (temp->left == nullptr) {
                temp->left = new_node;
                size++;   // increment size variable of BTree
                new_node->search_cost = temp->search_cost + 1;
                return new_node;
            }
            temp = temp->left;  // if there are more nodes to the left of 'temp', repeat procedure (loop) for the next node to the left
        }
        // if 'obj' is greater then the value of the current node, it must be inserted somewhere to the right of the current node
        else if (obj > temp->value)
        {
            // if 'obj' must be inserted to the right of 'temp' and there are no elements to the right of temp, insert the new node at 'temp->right'
            if (temp->right == nullptr) {
                // insert node
                temp->right = new_node;
                size++;   // increment size variable of BTree
                new_node->search_cost = temp->search_cost + 1;
                return new_node;
            }
            temp = temp->right;  // if there are more nodes to the right of 'temp', repeat procedure (loop) for the next node to the right
        }
        else
        {
            // the value 'obj' is already in the BTree
            return nullptr;
        }
    }
}

// recursive search function - implemented by the search function
Node* recur_search(Node *n, int obj)
{
    if (n == nullptr) return nullptr;  // if the node is a nullptr, then the desired node was not found. Return 'nullptr'
    if (n->value == obj) return n;     // if the value of the node is equal to 'obj', it is the desired node. Return this node

    // Recursive step 1: recursively call this function using the same 'obj' value and the node to the left of the node in question
    Node *l = recur_search(n->left, obj);
    if (l != nullptr) return l;

    // Recursive step 2: recursively call this function using the same 'obj' value and the node to the right of the node in question
    Node *r = recur_search(n->right, obj);
    if (r != nullptr) return r;

    // if the desired node is not found in the current subtree, return nullptr
    return nullptr;
}

// search function
Node* BTree::search(int obj)
{
    // call the recur_search(Node *n, int obj) function which recursively performs the search operation
    return recur_search(root, obj);
}

// recursive update search cost function - implemented by update_search_cost function
void update_search_cost_recur(Node *n)
{
    // if the current node is a nullptr, terminate the current function call
    if (n == nullptr) return;

    // declare a temporary variable containing the search_cost value for the immediate children of the current node
    int new_search_cost = n->search_cost + 1;

    // if there is a node to the left of the current node
    if (n->left != nullptr) {
        n->left->search_cost = new_search_cost;   // update the search_cost of the new node
        update_search_cost_recur(n->left);        // recursively call this function using the new node
    }

    // if there is a node to the right of the current node
    if (n->right != nullptr) {
        n->right->search_cost = new_search_cost;   // update the search_cost of the new node
        update_search_cost_recur(n->right);        // recursively call this function using the new node
    }
}

// update_search_cost function
void BTree::update_search_cost()
{
    // call the update_search_cost_recur(Node *n) function which recursively updates the search_cost variable for each node in the BTree
    update_search_cost_recur(root);
}

// inorder function
void BTree::inorder(ostream& out, const Node& tree)
{
    /*
        print your nodes in infix order

        if our tree looks like 

        4
        2 6
        1 3 5 7

        we should get

        1 2 3 4 5 6 7 
    */

    // recursively call the inorder( ... ) function using the node to the left of the current node, if it exists
    if (!(tree.left == nullptr)) {
        inorder(out, *(tree.left));
    }

    // print the (value, search_cost) data pair for the current node
    out << tree.value << "[" << tree.search_cost << "] ";

    // recursively call the inorder( ... ) function using the node to the right of the current node, if it exists
    if (!(tree.right == nullptr)) {
        inorder(out, *(tree.right));
    }
}

// get_max_line_items function - utilized by the print_level_by_level function
int get_max_line_items(int power)
{  /* This function performs the exponential operation 2^n where n is the function parameter */
    if (power == 0) return 1;  // 2^0 = 1

    int out = 2;
    for (int i = 1; i < power; i++) 
        out = out * 2;  

    return out;
}

// print_level_by_level function
void BTree::print_level_by_level(ostream& out)
{
    /*
        print the tree using a BFS 

        output should look like this if we dont have a full tree

        4
        2 6
        1 X 5 7
        X X X X X X X 9

        it will be helpful to do this part iteratively, 
        so do the BFS with the std stack data structure.

        it may also be helpful to put the entire tree into a vector 
        (probably google this if you dont know how to do it)
    */

    // if the root is null, there is nothing to print
    if (root == nullptr) return;

    // ensure that each node has the proper search cost
    update_search_cost();

    // instantiate a queue of Node pointers
    queue<Node*> q;
    q.push(root);

    // define local control variables
    int num = 0;
    int depth = 1;
    int line_items = 0;
    int max_line_items = 1;

    // this loop will continue until the number of nodes printed is equal to the size of the BTree
    // (i.e. until every node is printed)
    while ( num < size )
    {
        // if the max number of elements for a given depth has been printed, go to next line
        if (line_items == max_line_items) {
            out << "\n";
            depth++;         // increment depth variable
            line_items = 0;  // reset line_items variable
            max_line_items = get_max_line_items(depth-1);  // calculate max_line_items variable
        }

        // create temporary Node* pointer
        Node *temp = q.front();
        q.pop();

        // null nodes i.e. 'X' nodes
        // the root node is used to represent NULL placeholders
        if ((temp == root) && (depth != 1)) {
            out << "X ";
            line_items++;   
            q.push(root);  // push NULL plaecholder
            q.push(root);  // push NULL placeholder
        }
        else
        { // i.e. the node is NOT null
            
            // print the value of the node
            out << temp->value << "[" << temp->search_cost << "] ";
            num++;
            line_items++;

            if (temp->left  != nullptr)  q.push(temp->left);
            else  q.push(root);
            
            if (temp->right != nullptr)  q.push(temp->right);
            else  q.push(root);
        }
    }

    while (line_items < max_line_items)
    {
        out << "X ";
        line_items++;
    }

    return;
}


int sum_search_cost_recur(Node *n)
{
    if (n == nullptr) 
        return 0;
    else
        // return the sum of the search_cost of the current node, of the node immediately to the left,
        // and of the node immediately to the right
        return n->search_cost + sum_search_cost_recur(n->left) + sum_search_cost_recur(n->right);
}

// returns the average search cost of a BTree
double BTree::avg_search_cost()
{
    update_search_cost();      // update the search_cost variable for every node in the BTree
    double sum = sum_search_cost_recur(root);  // find the sum of the search_cost variables for every node in the BTree
    return (sum / size);       // return the sum of all search costs divided by the size of the BTree
}

int update_size_recur(Node *n)
{
    if (n == nullptr)
        return 0;
    else
        return 1 + update_size_recur(n->left) + update_size_recur(n->right);
}

// update the size of the current BTree -> only used for the move assignment operator
void BTree::update_size()
{
    size = update_size_recur(root); // update the size variable of the current BTree
}