#include<iostream>
#include<vector>
#include<bitset>
#include<map>
#include<algorithm>
using namespace std;


//Exponentiation via repeated squaring trick O(N^3)
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

long int compute( int A, int B, int C, int R, vector< long int>&M, int K, int N){
  
  for(int i = 1; i < K; i++ ){
    M.push_back((exponentiation(A,i+1,R)*B + C)%R);
  }
  
  //Finding the minimum integer not contained in the previous K elements
  //Is there a formula here, for the following? 
    
  vector<pair<long int,long int> > P; 
  int result,max = 0;

  for(int i = 0; i < M.size(); i++){
    P.push_back(make_pair(M[i],i));
  }
  sort(P.begin(),P.end());
  max = P[P.size()-1].first; 

  //Retrieve the Missing values upto K+size(new_values) <= N
  for(int i = 0; i < P.size() - 1; i++){
    for(int j = P[i].first+1; j < P[i+1].first && M.size() <= N;  j++){
      M.push_back(j); //Append new_values
    }
    if(M.size() == N)
      result = M[M.size() - 1];
  }
  
  //We have an array of size K+size(new_values) < N 
  result = max + N - M.size();
  
  return result; 
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
    else  result = compute(A,B,C,R,M,K,N);
    case_num++;
    cout<<"Case #"<<case_num<<": "<<result<<endl;
  }

}
