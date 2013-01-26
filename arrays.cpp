#include<iostream>
#include<vector>
#include<bitset>
#include<map>

using namespace std;

long int exponentiation(int A, int i, int R){
  int c = 0;
  int d = 1;
  string b;
  bitset<32> x (A); //32 suffice for the problem?
  b = x.to_string<char,char_traits<char>,allocator<char> >();
  //  cout<<b<<endl;
  for(int k = 0; k < b.length(); k++){
    c <<= 1 ;
    d = (d*d) % R;
    if(b[k] == '1'){
      c += 1;
      d = (d * A) % R;
    }
  }
  return d;
}

// void show(vector<long int> &M){
//   for(int i = 0; i < M.size(); i++)  cout<<M[i]<<" ";
//   cout<<endl;
// }

void compute( int A, int B, int C, int R, int K, int N){

  cout<< ((exponentiation(A,N+1,R)*B + C)%R)<<endl;

 }

int main(){
  int N,K,A,B,C,R,T; 
  vector<long int> M;
  cin>>T;
  //int i;
  // cin>>A>>i>>R;
  // cout<<exponentiation(A,i,R);
  
  while(T--){
    cin>>N>>K; //N : size of the array whose first K values are known
    cin>>A>>B>>C>>R;
    compute(A,B,C,R,K,N);
    cout<<exponentiation(A,N,R);
    
    
  }

}
