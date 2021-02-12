#include <iostream>

using namespace std;

struct subset_node
{
    int key;
    subset_node* left;
    subset_node* right;
    subset_node* parent;
    int level;
};

bool init(subset_node **sn)
{
    *sn = NULL;
}

bool insert(subset_node **sn, int k)
{
    subset_node* tmp = new subset_node;
    tmp->key = k;
    tmp->left = NULL;
    tmp->right = NULL;
    subset_node* predok = NULL;
    while (*sn != NULL)
    {
        if ( (k > (*sn)->key) && ((*sn)->right == NULL) ) predok = *sn;
        if ( (k < (*sn)->key) && ((*sn)->left == NULL) ) predok = *sn;
        if (k > (*sn)->key) {subset_node** t = sn; sn = &((*t)->right);}
        else if (k < (*sn)->key) {subset_node** t1 = sn; sn = &((*t1)->left);}
        else if (k == (*sn)->key) {delete tmp; return false;};
    }
    *sn = tmp;
    (*sn)->parent = predok;
    if((*sn)->parent) (*sn)->level = (*sn)->parent->level + 1;
    else (*sn)->level = 1;
    return true;
}

unsigned int size_of_tree(subset_node *sn)
{
    int zero = 0;
    unsigned int sb = 0, sm = 0;
    if (sn == NULL) return zero;
    if (sn != NULL)
    {
        sb = size_of_tree(sn->left);
        sm = 1 + size_of_tree(sn->right);
    }
    return (sm+sb);
}


void set_level (subset_node **sn)
{
    if (!(*sn)) return;
    if((*sn)->parent) (*sn)->level = (*sn)->parent->level + 1;
    else (*sn)->level = 1;
    set_level(&(*sn)->left);
    set_level(&(*sn)->right);
}

unsigned int vg (subset_node *sn, int* keys, unsigned int nomer)///////////////////////////////// вглубину начало
{
    unsigned int num = nomer;
    if (sn != NULL)
    {
        nomer = vshir((sn->left),keys,nomer);
        keys[nomer] = sn->key;
        nomer = nomer + 1;
        nomer = vshir((sn->right),keys,nomer);
    }
    else
    {
        return nomer;
    }
    return nomer;
}

int* DFS (subset_node *sn)
{   unsigned int n = size_of_tree(sn);
    if (n>0)
    {
        int* keys = new int [n];
        vg (sn,keys,0);
        return keys;
    }
    else return NULL;
} //////////////////////////////////////////////////////////////////////////в ширину конец

subset_node* find(subset_node *sn, int k)
{
    if (size_of_tree(sn)==0) return NULL;
    while (sn != NULL)
    {
        if (k > sn->key) sn = sn->right;
            else if (k < sn->key) sn = sn->left;
                else if (k == sn->key) {return sn;};
    }

    return NULL;
}

void pottyagivay_k_bate (bool right, subset_node *batya, subset_node *pott)
{
    if (right)
    {
        batya->right = pott;
        batya->right->parent = batya;
    }
    else
    {
        batya->left = pott;
        batya->left->parent = batya;
    }
}

bool delete_root (subset_node **root)
{
    subset_node* predok;
    subset_node** tmp;
    if ((*root)->right)
    {
        tmp = &((*root)->right);
        while (*tmp!= NULL)
        {
            if  ((*tmp)->left == NULL)  predok = *tmp;
            tmp = &((*tmp)->left);
        }
        *tmp = (*root)->left;
        if (*tmp) {(*tmp) ->parent = predok;};
        subset_node* newroot = (*root)->right;
        newroot->parent = NULL;
        delete *(root);
        *root = newroot;

        return true;
    }
    else if ((*root)->left)
    {
        subset_node* newroot = (*root)->left;
        delete (*root);
        newroot->parent = NULL;
        *root = newroot;

        return true;
    }
    else
    {
        delete (*root);
        *root = NULL;

        return true;
    }
}

bool remove(subset_node **sn, int k)
{
    if (size_of_tree(*sn)==0) return false;
    subset_node* rem_e = (find (*sn, k));
    if (!rem_e) return false;
    if (k == (*sn)->key) {delete_root(sn); set_level(sn); return true;};
    bool right = (rem_e->parent->right == rem_e);
    subset_node** tmp;
    subset_node* predok;
    if (!rem_e) return false;
    if (rem_e ->right)
    {
        tmp = &(rem_e ->right);
        pottyagivay_k_bate(right,rem_e->parent,*tmp);
        while (*tmp!= NULL)
        {
            if  ((*tmp)->left == NULL)  predok = *tmp;
            tmp = &((*tmp)->left);//////////////////////////// tmp - указатель на элемент, куда нужно вставить rem_e->left
        }
        *tmp = rem_e->left;
        if (*tmp) { (*tmp)->parent = predok;};
        delete rem_e;

        set_level(sn);
        return true;
    }
    else if (rem_e->left)
    {
        pottyagivay_k_bate(right,rem_e->parent,rem_e->left);
        delete rem_e;

        set_level(sn);
        return true;
    }
    else
    {
        if (right) rem_e->parent->right = NULL;
        else rem_e->parent->left = NULL;
        delete rem_e;

        set_level(sn);
        return true;
    }

}

void h(subset_node *sn, unsigned int* i)
{
    if (!sn) return;
    if (sn -> level > *i) *i = sn->level;
    h(sn->left, i);
    h(sn->right, i);
    return;
}

unsigned int height(subset_node *sn)
{
    unsigned int* i = new unsigned int;
    *i = 0;
    h(sn,i);
    unsigned int hei = *i;
    delete i;
    return (hei);
}

void destructor(subset_node **sn)
{
    if (!*sn) return;
    destructor(&((*sn)->left));
    destructor(&((*sn)->right));
    delete *sn;
    *sn = NULL;
    return;
}
