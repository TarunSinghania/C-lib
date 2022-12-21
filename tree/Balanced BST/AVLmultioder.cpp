//not checked 
//following https://www.youtube.com/watch?v=q4fnJZr8ztY&t=289s
//https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/datastructures/balancedtree/AVLTreeRecursive.java 
//multiset will have count variable at each node
//ordere statistic will have size variable at each node
//size[x] = size[left[x]] + size[right[x]] + 1, to get rank and kth largwest
#include <bits/stdc++.h> 
using namespace std;


class node{
public:
    //balance factor
    int bf;
    int cnt;
    //value
    int v;

    //height
    int h;
    int sz;
    node* l;
    node* r;

    node(int val){
        v = val;
        l = NULL;
        r = NULL;
        h = 0;
        bf = 0;
        cnt = 1;
        sz = 1;
    }
};

class AVL{

public:
    node* root;
    int tsz;

    int size(){
        return tsz;
    }

    int height(){
        if(root == NULL){
            return 0;
        }
        return root->h;
    }

    bool contains(int v){
        return contains(root, v);
    }
    bool contains(node *n, int v){
    if (n == NULL) return false;
    if (v < n->v) return contains(n-> l, v);
    if (v > n->v) return contains(n->r, v);
    return true;
    }

    void insert(int val) {
          root = insert(root, val);
          tsz++;
    }

    node* insert(node* n, int v){
        if (n == NULL) return new node(v);
        if (n->v == v){
         n->cnt++;
         n->sz++;
        }
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
    int lsz = (n->l == NULL) ? 0 : n->l->sz;
    int rsz = (n->r == NULL) ? 0 : n->r->sz;
    n->h = 1 + max(lh, rh);
    n->sz = n->cnt + lsz + rsz; 
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

    int _end (){
        if(root == NULL)return -1;
       return rightleaf(root);
    }

    int rightleaf(node* n){
        if(n->r != NULL) return rightleaf(n->r);
        return n->v;
    }

    int secondlargest(){
        vector<int> z;
        preorder(root, z);
        return z[1];
    }
    void preorder(node *n, vector<int> &z){
        if(n->l != NULL)preorder(n->l,z);
        z.push_back(n->v);
        if(n->r != NULL)preorder(n->r,z);
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

    int kthlargest(int k){
        if(tsz < k)return -1;
        return find_by_order(root, k);
    }
    int find_by_order(node* n, int k){
        int lsz = ( (n->l == NULL) ? 0 : n->l->sz);  
        int rsz = ( (n->r == NULL) ? 0 : n->r->sz); 
        if(k <= lsz) return find_by_order(n->l, k); 
        if(k > lsz && k <= lsz + n->cnt){
            return n->v;
        }
        return find_by_order(n->r, k - lsz - n->cnt);
    }

    AVL(){
        root = NULL;
        tsz = 0;
    }


};


int32_t main()
{
    AVL tree;
    int n;
    cin>>n;
    for(int i = 1 ; i <=n; i++){
        int x;cin>>x;
        tree.insert(x);
        //tree.print();
    }

    if(tree.size() < 2){
        cout<<"NO";
    }else{
        cout<<tree.kthlargest(4)<<endl;
    }
    

 
}