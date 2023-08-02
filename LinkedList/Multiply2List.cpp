long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  if(l1->data==0 || l2->data==0) return 0;
  int mod=1e9+7;
  long long no1=0,no2=0;
  while(l1 && l2){
      no1 = (no1*10)%mod;
      no2 = (no2*10)%mod;
      no1 = (no1 + l1->data)%mod;
      no2 = (no2 + l2->data)%mod;
      l1 = l1->next;
      l2 = l2->next;
  }
  while(l1){
      no1 = (no1*10)%mod;
      no1 = (no1 + l1->data)%mod;
      l1 = l1->next;
  }
  while(l2){
      no2 = (no2*10)%mod;
      no2 = (no2 + l2->data)%mod;
      l2 = l2->next;
  }
  return ((no1%mod)*(no2%mod))%mod;
}