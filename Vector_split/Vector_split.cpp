#include <iostream>
#include <vector>


void split( std::string x, char y,std::string &z){
    int temp=0;
   for(int i=0;i<x.length();i++){
    if(x.find(y)!= std::string::npos){
        int b=i;
        for(int i = temp; i<b;i++){
          z+=x[i];
          std::cout<<z;
        };
    };
   }
}

int main(){
    std::vector<std::string> start = {"do,re,me,fa,so,la,ti,do"};
    std::vector<std::string> end;
    for(int i=0;i<start.size();i++){
      std::string x= start[i] ; 
      char y = ',';
      std::string z;
      split(x,y,z);
      end.push_back(z);
      z="";
    }
    for(int i = 0;i<end.size();i++){
        std::cout<<end[i];
    }
    return 0;
}