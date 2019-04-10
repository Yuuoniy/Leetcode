//大数据会 RE ,还不清楚是怎么回事:因为 nodes 的数组开小了！线段树不止叶子节点！
#include <stdio.h>
#include <iostream>
using namespace std;

int mod;
struct node
{
  int l,r;
  long long value,addTag,multiTag;
}Nodes[100005*4];

long long num[100005];

void spread(int p){
    Nodes[p*2].value = (Nodes[p*2].value*Nodes[p].multiTag+ Nodes[p].addTag*(Nodes[p*2].r-Nodes[p*2].l+1))%mod;
    Nodes[p*2+1].value = (Nodes[p*2+1].value*Nodes[p].multiTag+ Nodes[p].addTag*(Nodes[p*2+1].r-Nodes[p*2+1].l+1))%mod;

    Nodes[p*2].multiTag = (Nodes[p*2].multiTag*Nodes[p].multiTag)%p;
    Nodes[p*2+1].multiTag = (Nodes[p*2+1].multiTag*Nodes[p].multiTag)%p;

    Nodes[p*2].value = (Nodes[p*2].addTag*Nodes[p].multiTag+Nodes[p].addTag)%p;
    Nodes[p*2+1].value = (Nodes[p*2+1].addTag*Nodes[p].multiTag+Nodes[p].addTag)%p;
   
    Nodes[p].multiTag = 1;
    Nodes[p].addTag = 0;

}

void update(int p,int left,int right,int k){
  if(left<=Nodes[p].l&&right>=Nodes[p].r){
    Nodes[p].value =(long long)(Nodes[p].value +k*(Nodes[p].r-Nodes[p].l+1))%mod;
    Nodes[p].addTag=(Nodes[p].addTag+k)%p;
    return;
  }
  spread(p);
  int mid = (Nodes[p].l+Nodes[p].r)>>1;
  if(left<=mid) update(p*2,left,right,k);
  if(right>mid) update(p*2+1,left,right,k);
  Nodes[p].value =(Nodes[p*2].value+Nodes[p*2+1].value)%mod;
}

void multi(int p,int left,int right,int k){
  if(left<=Nodes[p].l&&right>=Nodes[p].r){
    Nodes[p].value=(long long)(Nodes[p].value*k)%mod;
    Nodes[p].multiTag=(Nodes[p].multiTag*k)%mod;
    Nodes[p].addTag = (Nodes[p].addTag*k)%mod;
    return;
  }
  spread(p);
  int mid = (Nodes[p].l+Nodes[p].r)>>1;
  if(left<=mid) update(p*2,left,right,k);
  if(right>mid) update(p*2+1,left,right,k);
  Nodes[p].value = (Nodes[p*2].value+Nodes[p*2+1].value)%mod;
  return;
}


long long getsum(int p,int left,int right){
  if(left<=Nodes[p].l&&right>=Nodes[p].r) 
  {
    cout << "get sum "<< Nodes[p].value << endl;
    return Nodes[p].value;
  }
  spread(p);
  int mid = (Nodes[p].l+Nodes[p].r)>>1;
  long long ans = 0;
  cout << "left " << left << " right " << right << " mid " << mid << endl;
  if(left<=mid) ans=(ans+getsum(p*2,left,right))%mod;
  if(right>mid) ans=(ans+getsum(p*2+1,left,right))%mod;
  return ans;
}

void build(int p,int left,int right){
  if(left>right) return;
  Nodes[p].multiTag = 1;
  Nodes[p].addTag = 0;
  Nodes[p].l = left;
  Nodes[p].r = right;
  if(left==right){
    Nodes[p].value = num[left];
    cout << " Nodes[p].value " << Nodes[p].value << endl;
    return;
  }
  int mid = (left+right)>>1;
  int chl = p*2;
  int chr = p*2+1;
  build(chl,left,mid);
  build(chr,mid+1,right);
  Nodes[p].value = Nodes[chl].value+Nodes[chr].value;
  cout << " Nodes[p].value " << Nodes[p].value << " " << Nodes[chl].value << " " << Nodes[chl].value<< endl;
}


int main(){
  int n,m;
  scanf("%d%d%d",&n,&m,&mod);
  int tmp;
  for(int i = 1; i <= n; i++)
  {
    scanf("%lld",&num[i]);
  }
  build(1,1,n);
  int left,right,k;
  for(int i = 1; i <= m; i++)
  {
    scanf("%d",&tmp);
    if(tmp==1){
      scanf("%d%d%d",&left,&right,&k);
      update(1,left,right,k);
    }else if(tmp==2){
      scanf("%d%d%d",&left,&right,&k);
      multi(1,left,right,k);
    }else{
      scanf("%d%d",&left,&right);
      printf("%lld\n",getsum(1,left,right));
    }
  }

  return 0;
}
