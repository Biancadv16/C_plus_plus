#include <iostream>


void check_case(std::string &x){
    int y = int(x[0]);
   
    if(y>=97 && y<=122){
       y-=32;
       x[0] = char(y);
    }
    for(int i=1;i<x.length();i++){
        int y = int(x[i]);
        if(y>=65 && y<=90){
            y+=32;
            x[i]=char(y);
        }
    }
}

int main(){
    std::string first_name,middle_name,last_name;
    std::cout<<"Enter your First name: "<<std::endl;
    std::cin>> first_name;
    std::cout<<"Enter your Middle name(if none type 0): "<<std::endl;
    std::cin>> middle_name;
    std::cout<<"Enter your Last name: "<<std::endl;
    std::cin>> last_name;
    check_case(first_name);
    check_case(middle_name);
    check_case(last_name);
    if(middle_name=="0"){
        std::cout<<last_name<<" , "<<first_name<<".";
    }else{
     std::cout<<last_name<<" , "<<first_name<< " "<<middle_name[0]<<".";
    }
    return 0;
}