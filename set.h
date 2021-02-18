#include <iostream>
class sett
{
private:
    struct subset_node // structure == element of tree
    {
        int key;
        subset_node* left;
        subset_node* right;
        subset_node* parent;
        int level;

        subset_node(int k)
        {
            this->key = k;
            this->left = NULL;
            this->right = NULL;
        }
    };

    subset_node* root;  // root of the tree (pointer to the top element)


    struct subforwardlist // structure which can create a queue for BFS
    {
        subset_node* data;
        subforwardlist* next;
    };
    subforwardlist* start = NULL; //
    subforwardlist* End = NULL;   // pointer to start and end of the queue

    //-----------------------Private methods-------------------------//

    unsigned int size(subset_node* sn);

    unsigned int height(subset_node* sn);

    void destructor(subset_node **sn);

    unsigned int dfs (subset_node *sn, int* keys, unsigned int nomer);

    void pottyagivay_k_bate(bool right, subset_node *batya, subset_node *pott);

    bool delete_root(subset_node **root);

    subset_node* find__(int k);


    void nfs(subset_node* root, subforwardlist** start, subforwardlist** End, subset_node** a);

    //-----------Private methods (special to working with queue)-------//

    unsigned int size_of_list();

    bool push_back(subset_node* e_tree);

    int pop_forward();

    void print_queue();

    //-----------------------------------------------------------------//
public:
    sett();

    bool insert(int k); // adds an element (k) to the tree

    bool remove(int k); // remove an element (k) from the tree

    unsigned int size_of_tree(); // checks size of tree (amount of elements)

    unsigned int height_of_tree(); // checks height of tree

    bool find(int k); // checks if there is an element in the tree (if it is function returns true, in other way function returns false

    void DFS(bool vim_type_of_search); // depth-first search (displays order of elements keys after depth-first search)

    void set_tree(); // set standart tree

    void NFS(bool vim_type_of_search); // breadth-first search (displays order of elements keys after breadth-first search)

    ~sett();

};
