#include <bits/stdc++.h> 
using namespace std;


//evry node we have to maintain the right value associated with it 
//and subtree max right value
//not checked 

template <typename T> class intervaltree{
public:
        class node{
            public:
                T v;
                node *l;
                node *r;
                T rv;
                T srv;
                int h;
                int bf;

                node(T val, T R){
                    v = val;
                    bf = 0;
                    h = 0;
                    rv = R;
                    srv = R;
                    l = NULL;
                    r = NULL;
                } 
        };

        node * root;
        int sz;
        T T_min;


        intervaltree(T mn){
            root = NULL;
            sz  = 0;
            T_min = mn;
        }
        int size(){
            return sz;
        }
        int height(){
            if(root == NULL){
                return 0;
            }
            return root->h;
        }


        void insert(T L, T R){
            root = insert(root, L, R);
            sz++;
        }

        node* insert(node *n, T L, T R){
            if(n == NULL)return new node(L, R);
            if(n->v == L){
                n->rv = max(R,n->rv);
                n->srv = max(n->srv,R);
            }
            if(L < n->v )
                n->l = insert(n->l, L, R);
            if(L > n->v)
                n->r = insert(n->r, L, R);
            update(n);
            return balance(n);
        }


        void update(node *n){
            int lh = (n->l == NULL) ? -1 : n->l->h;
            int rh = (n->r == NULL) ? -1 : n->r->h;
            T lsrv = (n->l == NULL) ? T_min : n->l->srv;
            T rsrv = (n->r == NULL) ? T_min : n->r->srv;
            n->srv = max(n->rv,max(lsrv, rsrv));
            n->h = 1 + max(lh, rh);
            n->bf = rh - lh;
        }

        node* balance(node *n){
            // left heavy
            if(n->bf ==  -2){
                if(n->l->bf <= 0){
                    return ll(n);
                }else{
                    return lr(n);
                } 
            }else if(n->bf == 2){
            //right heavy
                if(n->r->bf >= 0){
                    return rr(n);
                }else{
                    return rl(n);
                }
            }
            return n;
        }

        node* ll(node *n){
                return rrt(n);
        }
        node* lr(node *n){
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
        node* lrt(node *n){

            node* newtop = n->r;
            n->r = newtop->l;
            newtop->l = n;
            update(n);
            update(newtop);
            return newtop;
        }
        
        node* rrt(node* n){
        
        node* newtop =  n->l;
        n->l = newtop->r;
        newtop->r = n;
        update(n);
        update(newtop);
        return newtop;
        }

        bool point_exists( T p){
            if(root == NULL)return false;
           return check(root, p);
        }
        bool check(node *n, T p){
            
            if(n->v <= p){
                if(n->rv >= p)return true;
                if(n->l != NULL)
                if(n->l->srv >= p) return true;
                if(n->r == NULL)return false;
                return check(n->r, p);
            }else{
                if(n->l == NULL)return false;

                return check(n->l, p);
            }

        }

        bool range_overlap(T L, T R){
           if(root == NULL)return false;
           return check(root, L, R);
        }

        bool check(node *n, T L, T R){
            if(n->v <= L && n->rv >= R)
                return true;
            if(n->rv >= R){
                if(n->l){
                    return check(n->l, L, R);
                }else{
                    return false;
                }
            }else{
               if(n->r){
                return check(n->r, L, R); 
               }else{
               return false;
                }
            }
        }
};

int32_t main(){
    intervaltree<float> tree(-1e18);
    tree.insert(1,10);
    tree.insert(20,30);
    tree.insert(33,40);
    cout<<tree.range_overlap(1,11);
    return 0;
}
