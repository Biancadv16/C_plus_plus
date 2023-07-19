#include <iostream>
#include <cmath>
#include<vector>
#include <fstream>

std::string signUp(std::string a,std::string b,std::string c,std::string d,std::string e,std::string f,std::string g){
     std::cout<<"\nPlease enter your Username: ";
        std::cin>>a;
        std::cout<<"\nEnter your password: ";
        std::cin>>b;
        std::cout<<"\nPlease confirm your password: ";
        std::cin>>c;
        if(c==b){
            std::cout<<"What is your name? ";
            std::cin.getline>>d;
            std::cout<<"What is your Last name? ";
            std::cin>>e;
            std::cout<<"Enter your email: ";
            std::cin>>f;
            std::cout<<"Enter your phone number: ";
            std::cin>>g;
        }
return a,b,c,d,e,f,g;
}

std::string signIn(std::string x,std::string y){
     std::cout<<"\nPlease enter your Username: ";
     std::cin>>x;
     std::cout<<"\nEnter your password: ";
     std::cin>>y;
 return x,y;
}


int main(){
    std::string signtype ,signup_verify,username,password,new_password,new_username,confirm_password,name,surname,email,number;
    std::cout<<"Sign In or Sign Up: ";
    std::cin>>signtype;

    if(signtype=="Sign In" || signtype=="sign in" || signtype=="signin" || signtype=="Signin" || signtype=="signIn" || signtype=="SignIn" || signtype=="Sign in" || signtype=="sign In" || signtype=="In"  || signtype=="in"){
      signIn(username,password);
    }else if(signtype=="Sign Up" || signtype=="sign up" || signtype=="signup" || signtype=="Signup" || signtype=="signUp" || signtype=="SignUp" || signtype=="Sign up" || signtype=="sign Up" || signtype=="Up"  || signtype=="up"){
       signUp(new_username,new_password,confirm_password,name,surname,email,number);
       std::cout<<"Is all the info given correct? Y/N?";
       std::cin>> signup_verify;
       if(signup_verify =="Y" || signup_verify =="y"|| signup_verify=="Yes"||signup_verify=="yes"){
           signIn(new_username,new_password);
       }else if(signup_verify == "N"|| signup_verify=="n"||signup_verify=="No" || signup_verify=="no"){
        signUp(new_username,new_password,confirm_password,name,surname,email,number);
       }

    }
    
    return 0;
}