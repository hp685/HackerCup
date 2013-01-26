#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
#include<fstream>
#include<cstring>
using namespace std;

void parse(const string s, stack<char> cs, bool& isgood, int i){

  
  if(i == s.length()){ //BASE
    int count = 0;
    while(!cs.empty()){
      if(cs.top() == ')' && count >= 0 ) count++;
      else if(cs.top() =='(') count--;
      cs.pop();
    }
    if(count ==  0)  isgood = true;
    return;
  }
  else{
    // 3 CASES
    
    
    if (( s[i] == '(' || s[i] ==')') && i+1 >= s.length() && s[i+1] == ':'){
      parse(s,cs,isgood,i+1);
    }
    if( (s[i] == '(' || s[i] == ')') && i-1 >= 0 && s[i-1] == ':'){
      parse(s,cs,isgood,i+1);
    }
    
    if(s[i] == '(' || s[i] == ')'){
      cs.push(s[i]);
      parse(s,cs,isgood,i+1);
    }
    parse(s,cs,isgood,i+1);
    
  }
}

int main(){
  //  freopen("balanced_smileystxt.txt","r",stdin);
  //freopen("smileys.out","w",stdout);  
  int m; 
  string s;
  stack<char> cs;

  string ret;
  int case_num = 0;
  cin>>m;
  cin.ignore();
  
  while(m--){
    
    getline(cin,s);

    //start at pos 0
    bool isgood = false;    
    parse(s,cs,isgood,0); 
    
    if (isgood == true) ret = "YES";
    else ret = "NO"; 
    case_num++;
    cout<<"Case #"<<case_num<<": "<<ret<<endl; 

  }

}
