
https://codeforces.com/blog/entry/15296

https://loj.ac/p/121

#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int MAXN=5010,MAXM=500010,Inf=0x3f3f3f3f;
struct node
{
	int id,rev,t,mint,mine;
	node *lson,*rson,*pa;
	inline bool isroot()
	{
		return (!pa)||!(pa->lson==this||pa->rson==this);
	}
	inline void ud()
	{
		mine=id,mint=t;
		if(lson&&lson->mint<mint)mint=lson->mint,mine=lson->mine;
		if(rson&&rson->mint<mint)mint=rson->mint,mine=rson->mine;
	}
	inline void fa_lazy()
	{
		if(rev)
		{
			swap(lson,rson);
			if(lson)lson->rev^=1;
			if(rson)rson->rev^=1;
			rev=0;
		}
	}
	inline void fa_all()
	{
		if(!isroot())pa->fa_all();
		fa_lazy();
	}
}pool[MAXN+MAXM],*nd[MAXN+MAXM];
//LCT!!
inline void rot(node *x)
{
	node *p=x->pa;
	if(x==p->lson)
	{
		p->lson=x->rson;
		if(p->lson)p->lson->pa=p;
		x->pa=p->pa;
		if(!p->isroot()&&p->pa->lson==p)p->pa->lson=x;
		else if(!p->isroot()&&p->pa->rson==p)p->pa->rson=x;
		p->pa=x;
		x->rson=p;
	}
	else
	{
		p->rson=x->lson;
		if(p->rson)p->rson->pa=p;
		x->pa=p->pa;
		if(!p->isroot()&&p->pa->lson==p)p->pa->lson=x;
		else if(!p->isroot()&&p->pa->rson==p)p->pa->rson=x;
		p->pa=x;
		x->lson=p;
	}
	p->ud();
	x->ud();
}
inline void spaly(node *x)
{
	while(!x->isroot())
	{
		//cout<<"spaly "<<x->id<<endl;
		node *p=x->pa;
		if(p->isroot())rot(x);
		else if((p->pa->lson==p)^(p->lson==x))rot(x),rot(x);
		else rot(p),rot(x);
	}
}
inline void access(node *x)
{
	//cout<<"access "<<x->id<<endl;
	x->fa_all();
	spaly(x);
	if(x->pa)
	{
		access(x->pa);
		x->pa->rson=x;
		x->pa->ud();
		spaly(x);
	}
	x->rson=0;
}
inline void mkr(node *x)
{
	access(x);
	x->rev^=1;
}
inline void link(node *x,node *y)
{
	mkr(x);
	x->pa=y;
}
inline void cut(node *x,node *y)
{
	//cout<<"cut "<<x->id<<' '<<y->id<<endl;
	mkr(x);
	access(y);
	x->pa=0;
}
inline int query(node *x,node *y)
{
	mkr(x);
	access(y);
	if(x->isroot())return -1;
	spaly(x);
	if(y->pa!=x)rot(y);
	if(x->rson==y)return y->lson->mine;
	else return y->rson->mine;
}
int n,m;
struct qu
{
	int t,u,v,d;
}q[MAXM];
map<pair<int,int>,int> mmp;//edge->addtime
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		nd[i]=&pool[i];
		nd[i]->id=i;
		nd[i]->t=Inf;
		nd[i]->ud();
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&q[i].t,&q[i].u,&q[i].v);
		if(q[i].u>q[i].v)swap(q[i].u,q[i].v);
		if(q[i].t==0)mmp[make_pair(q[i].u,q[i].v)]=i;
		else if(q[i].t==1)q[mmp[make_pair(q[i].u,q[i].v)]].d=i;
	}
	for(int i=1;i<=m;i++)if(q[i].d==0)q[i].d=Inf;
	for(int i=1;i<=m;i++)
	{
		//cout<<"q"<<i<<' '<<q[i].t<<' '<<q[i].u<<' '<<q[i].v<<' '<<q[i].d<<endl;
		int res=query(nd[q[i].u],nd[q[i].v]);
		/*cout<<"a"<<i<<' ';
		if(res==-1)cout<<res<<endl;
		else cout<<(res-n)<<' '<<q[res-n].d<<endl;*/
		if(q[i].t==0)
		{
			if(res!=-1&&nd[res]->t<q[i].d)
			{
				//cout<<"case1\n";
				cut(nd[q[res-n].u],nd[res]);
				cut(nd[q[res-n].v],nd[res]);
				nd[i+n]=&pool[i+n];
				nd[i+n]->id=i+n;
				nd[i+n]->t=q[i].d;
				nd[i+n]->ud();
				link(nd[q[i].u],nd[i+n]);
				link(nd[q[i].v],nd[i+n]);
			}
			else if(res==-1)
			{
				//cout<<"case2\n";
				nd[i+n]=&pool[i+n];
				nd[i+n]->id=i+n;
				nd[i+n]->t=q[i].d;
				nd[i+n]->ud();
				link(nd[q[i].u],nd[i+n]);
				link(nd[q[i].v],nd[i+n]);
			}
		}
		else if(q[i].t==1)
		{
			if(res!=-1&&nd[res]->t==i)
			{
				//cout<<"slj!\n";
				cut(nd[q[res-n].u],nd[res]);
				cut(nd[q[res-n].v],nd[res]);
			}
		}
		else
		{
			if(res!=-1)printf("Y\n");
			else printf("N\n");
		}
		/*for(int ii=1;ii<=n;ii++)
		{
			cout<<ii<<' '<<(nd[ii]->pa?nd[ii]->pa->id:-1)<<' '<<(nd[ii]->lson?nd[ii]->lson->id:-1)<<' '<<(nd[ii]->rson?nd[ii]->rson->id:-1)<<' '<<nd[ii]->rev<<' '<<nd[ii]->t<<endl;
		}
		for(int ii=1;ii<=i;ii++)
		{
			if(nd[ii+n])cout<<ii+n<<' '<<(nd[ii+n]->pa?nd[ii+n]->pa->id:-1)<<' '<<(nd[ii+n]->lson?nd[ii+n]->lson->id:-1)<<' '<<(nd[ii+n]->rson?nd[ii+n]->rson->id:-1)<<' '<<nd[ii+n]->rev<<' '<<nd[ii+n]->t<<endl;
		}*/
	}
	return 0;
}