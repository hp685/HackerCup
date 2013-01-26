#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<algorithm>
#include<fstream>
#include<cstring>
using namespace std;


bool comp(pair<char,int> a, pair<char,int> b){
  return a.second < b.second;
}

string normalize(string s, map<char,int> &M){

  for(int i = 0; i < s.length(); i++){
    if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ){ 
      s[i] = tolower(s[i]);
      M[s[i]]++; 
    }
   }
  return s;
}

void Histogram(map<char,int>& M, vector<pair<char,int> >& V){
  map<char,int>::iterator mit;
  for(mit = M.begin(); mit != M.end(); mit++){
    V.push_back(make_pair(mit->first, mit->second));
  }
  
  sort(V.begin(), V.end(),comp);
  
}

int compute(vector<pair<char,int> >&V, map<char, int> &M ){
  int start = 26;
  int score = 0;
  for(int i = V.size() - 1; i >= 0 && start >=1; i--){
    score += (start * M[V[i].first]);
    start -= 1;
    //    cout<<V[i].first<<" "<<V[i].second<<" "<<start+1<<" "<<score<<endl;
  }
  //  cout<<score<<endl;
  return score;
}
int main(){
  freopen("beautiful_stringstxt.txt","r",stdin);
  freopen("beauty.out","w",stdout);  
  int m; 
  string s;
  vector<pair<char,int> > V;
  map<char, int> M;

  int case_num = 0;
  cin>>m;
  cin.ignore();

  while(m--){
    
    getline(cin,s);
    s = normalize(s,M);
    Histogram(M,V);
    int score = compute(V,M);
  
    case_num++;
    cout<<"Case #"<<case_num<<": "<<score<<endl; 
    M.clear(); V.clear();
  }

}
