//checked on problem https://codeforces.com/contest/22/problem/A
//following https://www.youtube.com/watch?v=q4fnJZr8ztY&t=289s
//https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/datastructures/balancedtree/AVLTreeRecursive.java 
//multiset will have count variable at each node
//ordere statistic will have size variable at each node
//size[x] = size[left[x]] + size[right[x]] + 1, to get rank and kth largwest
#include <bits/stdc++.h> 
using namespace std;



template <typename T>  class AVL{

public:
    

    class node{
    public:
    //balance factor
    int bf;
     
    //value
        T v;

        //height
        int h;

        node* l;
        node* r;

        node(T val){
            v = val;
            l = NULL;
            r = NULL;
            h = 0;
            bf = 0;
        }
    };

    node* root;
    int sz;

    int size(){
        return sz;
    }

    int height(){
        if(root == NULL){
            return 0;
        }
        return root->h;
    }

    bool contains(T v){
        return contains(root, v);
    }
    bool contains(node *n, int v){
    if (n == NULL) return false;
    if (v < n->v) return contains(n-> l, v);
    if (v > n->v) return contains(n->r, v);
    return true;
    }

    void insert(int val) {
        if (!contains(root, val)) {
          root = insert(root, val);
          sz++;
        }
    }

    node* insert(node* n, T v){
        if (n == NULL) return new node(v);
        if (v < n->v)
            n->l = insert(n->l, v);
        if (v > n->v)
            n->r = insert(n->r, v);        
        update(n);
        return balance(n);
    }

    void update(node *n) {
    // -1 as leaf should have height 0
    int lh = (n->l == NULL) ? -1 : n->l->h;
    int rh = (n->r == NULL) ? -1 : n->r->h;
    n->h = 1 + max(lh, rh);
    n->bf = rh - lh;
    }

    node* balance(node* n){
        //left heavy
        if(n->bf == -2){
            if(n->l->bf <= 0){
                return ll(n);
            }else{
                return lr(n);
            }

        }else if(n->bf == 2){
            if(n->r->bf >= 0){
                return rr(n);
            }else{
                return rl(n);
            }
        }
        return n;
    }

    node* ll(node *n){
        //left left case
            //-2A               B (either 0, 1)
           //  / \             / \
      //(-1,0)B  E   -->      C   A
         //  / \                 /
        //  C   d               D
       return rrt(n);
    }
    node* lr(node *n){
    //left right case
            //-2A             -2 A(either 0, 1)
           //  / \             / \
        //  1 B  E   -->    -1D   E   ->
         //  / \             / \  /
        //  C   d           B   g   
        //     / \         / \
        //     f g        c   f
        //h[b] = h[c] + 1  h[d] = h[c] + 1
        //h[c] = h[d] - 1
        n->l = lrt(n->l);        
        return rrt(n);      
    }
    node* rr(node* n){
       return lrt(n);
    }
    node* rl(node* n){
       n->r = rrt(n -> r);
       return lrt(n);
    }

    node* rrt(node* n){
            //  A              B (either 0, 1)
           //  /               \
          //  B      -->         A
         //   \                 /
        //     C               C
        node* newtop =  n->l;
        n->l = newtop->r;
        newtop->r = n;
        update(n);
        update(newtop);
        return newtop;
    }
    node* lrt(node* n){
             //  A              B (either 0, 1)
           //     \            / 
          //       B    -->   A   
         //       /             \
        //       C              C
        node *newtop = n->r;
        n->r = newtop->l;
        newtop->l = n;
        update(n);
        update(newtop);
        return newtop;
    }

    T _end (){
        if(root == NULL)return -1;
       return rightleaf(root);
    }

    T rightleaf(node* n){
        if(n->r != NULL) return rightleaf(n->r);
        return n->v;
    }


    void print(){
        p(root);
        cout<<endl;
    }
    void p(node *n){
        if(n == NULL)return;
        cout<<n->v<<"->l";
        if(n->l)cout<<n->l->v;
        cout<<"-r";
        if(n->r)cout<<n->r->v;
        cout<<endl;
        p(n->l);
        p(n->r);
    }

    AVL(){
        root = NULL;
        sz = 0;
    }


};


int32_t main()
{
    AVL<int> tree;
    int n;
    cin>>n;
    for(int i = 1 ; i <=n; i++){
        tree.insert(i);
    }
    cout<<tree.height()<<endl;
 
}