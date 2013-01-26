#include<iostream>
#include<vector>
#include<bitset>
#include<map>

using namespace std;


//Exponentiation via repeated squaring
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
    if(b[k] == '1'){ //kth bit set
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
  
  for(int i = 1; i < K; i++ ){
    M.push_back((exponentiation(A,i+1,R)*B + C)%R);
  }
  
  //Finding the minimum integer not contained in the previous K elements
  //Is there a formula here? 
  //Missing values

}

int main(){
  int N,K,A,B,C,R,T; 
  vector<long int> M;
  long int result;
  int case_num = 0;
  cin>>T;
    
  while(T--){
    cin>>N>>K; //N : size of the array whose first K values are known
    cin>>A>>B>>C>>R;
    M.push_back(A); 
    if(N < K) result = exponentiation(A,N,R);
    else  result = compute(A,B,C,R,K,N);
    case_num++;
    cout<<"Case #"<<case_num<<": "<<result<<endl;
    
    
  }

}
