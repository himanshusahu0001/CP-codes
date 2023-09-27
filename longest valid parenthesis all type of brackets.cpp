#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

map<char,char> m;

string isValid(string str) {
  set<char> left({ '{', '[','('  });
  set<char> right({ '}', ']', ')'  });
  m['}'] = '{';
  m[')'] = '(';
  m[']'] = '[';
  stack<char> s;   
  int i,j=0; tuple<int,int> ans ={0,0};
  for(i=0; i<str.size(); i++){
      auto c = str[i];
      if (left.find(c) != left.end()) s.push(c);
      else {
          if(!s.empty() and m[c] == s.top()) s.pop();
          else {
              auto [x,y] = ans;
              if(i-j > y-x)ans = {j,i};
              j=i+1;
              s=stack<char>();
          }
      }
  }
  
  // return s.size()==0;
  auto& [x,y] = ans;
  if(i-j > y-x)ans = {j,i};
  auto tmp = str.substr(x,y-x);
  reverse(all(tmp));
  while(tmp.size()%2!=0) tmp.pop_back();
  reverse(all(tmp));
  return tmp;
}


int main() 
{
 
  cout <<   isValid(" {([]))} ");
}