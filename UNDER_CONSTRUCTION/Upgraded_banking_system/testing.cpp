#include <iostream>
#include <cmath>
#include<vector>
#include <fstream>
#include <cstdlib>

//FUNCTIONS FOR ENCRYPT/DECRYPT 1st
    char decrypt(char &x){
        int y = int(x);
        if(y>=48 && y<=57){
            y+=17;
            x=char(y);
        }else if(y>=91 && y<=96){
            y-=16;
            x=char(y);
        }else if(y>=33 && y<=42){
            y+=48;
            x=char(y);
        }else if(y>=43 && y<=47){
            y+=54;
            x=char(y);
        }else if(y>=58 && y<=64){
            y+=44;
            x=char(y);
        }else if(y>=65 && y<=78){
            y+=44;
            x=char(y);
        }else if(y>=108 && y<=117){
            y-= 60;
            x=char(y);
        }else if(y=118){
            y=42;
            x=char(y);
        }else{
           x=char(y);
        }
        return x;
    }

    char encrypt(char &x){
        int y = int(x);
        if(y>=65 && y<=74){
            y-=17;
            x=char(y);
        }else if(y>=75 && y<=80){
            y+=16;
            x=char(y);
        }else if(y>=81 && y<=90){
            y-=48;
            x=char(y);
        }else if(y>=97 && y<=101){
            y-=54;
            x=char(y);
        }else if(y>=102 && y<108){
            y-=44;
            x=char(y);
        }else if(y>=109 && y<=122){
            y-=44;
            x=char(y);
        }else if(y>=48 && y<=57){
            y+= 60;
            x=char(y);
        }else if(y=42){
            y=118;
            x=char(y);
        }else{
           x=char(y);
        }
        return x;
    }

    void crypt(std::ifstream &in_file,std::ofstream &out_file,int z){
         std::vector<char> data_items;
         char data;
         while(in_file>>std::noskipws>>data){
               data_items.push_back(data);
         }
        for(int i=0;i<data_items.size();i++){
            char x=data_items[i];
            if(z==1){
                decrypt(x);
                out_file<<x;
            }else{
                encrypt(x);
                out_file<<x;
            }
         }
    }


//FUNCTION FOR LOGO

    void asteriks_line(){
         for(int i=0;i<50;i++){
            std::cout<<"*";
        }
    }

//FUNCTION FOR SIGNIN AND SIGNUP

    void signIn_files(){
        std::ifstream in_encrypted_info("account_info/secret_file.dat",std::ios::binary);
        std::ofstream out_account_info("account_info/account_file.dat",std::ios::binary);
        if(in_encrypted_info.is_open()){
            crypt(in_encrypted_info, out_account_info,1);
          //    crypt(in_account_info,out_encrypted_info,0) ;
        }else{
            std::cout<<"ERROR: System offline,contact support and retry in a few minutes.";
            exit(1);
        }
    }

    std::string signIn(std::string x,std::string y){
         std::cout<<"\nPlease enter your Username: ";
         getline (std::cin,x);
         std::cout<<"Enter your password: ";
         getline (std::cin,y);
         std::cout<<std::endl;
         asteriks_line();
         std::cout<<std::endl<<"\n \tSign In successful! \n"<<std::endl;
         asteriks_line();
     return x,y;
    }

    std::string signUp(std::string a,std::string b,std::string c,std::string d,std::string e,std::string f,std::string g){
        int x=1;
         std::cout<<"\nPlease enter your Username: ";
         getline (std::cin,a);
         while(x==1){
         std::cout<<"\nEnter your password: ";
         getline (std::cin,b);
         std::cout<<"Please confirm your password: ";
         getline (std::cin,c);
            if(c==b){
                std::cout<<"\nWhat is your name? ";
                getline (std::cin,d);
                std::cout<<"What is your Last name? ";
                getline (std::cin,e);
                std::cout<<"Enter your email: ";
                getline (std::cin,f);
                std::cout<<"Enter your phone number: ";
                getline (std::cin,g);
                x=0;
            }else{
                std::cout<<"\nPasswords do not match.\n";
            }
         }
     return a,b,c,d,e,f,g;
    }

//SIGNIN OR SIGNUP

 void signing_process(){
    int signupVerify=0;
    int signing=1;
    std::string signtype,username,password,new_username,new_password,confirm_password,name,surname,email,number,signup_verify;
     while(signing==1){
        std::cout<<std::endl <<std::endl<<"Sign In or Sign Up? ";
        getline (std::cin,signtype);

        if(signtype=="Sign In" || signtype=="sign in" || signtype=="signin" || signtype=="Signin" || signtype=="signIn" || signtype=="SignIn" || signtype=="Sign in" || signtype=="sign In" || signtype=="In"  || signtype=="in"){
             signIn_files();
             signIn(username,password);
             signing=0;
        }else if(signtype=="Sign Up" || signtype=="sign up" || signtype=="signup" || signtype=="Signup" || signtype=="signUp" || signtype=="SignUp" || signtype=="Sign up" || signtype=="sign Up" || signtype=="Up"  || signtype=="up"){
             signIn_files();

             while(signupVerify==0){
              signUp(new_username,new_password,confirm_password,name,surname,email,number);
               std::cout<<"\nIs all the info given correct? (Y/N)";
               getline (std::cin,signup_verify);
       
                if(signup_verify =="Y" || signup_verify =="y"|| signup_verify=="Yes"||signup_verify=="yes"){
                    std::cout<<std::endl;
                    asteriks_line();
                    std::cout<<std::endl<<"\n \tSign up complete!\n"<<std::endl;
                    asteriks_line();
                    signIn(new_username,new_password);
                    signupVerify=1;
                }else if(signup_verify == "N"|| signup_verify=="n"||signup_verify=="No" || signup_verify=="no"){
                    std::cout<<std::endl<<"Please re-enter your info.\n";
                }else{
                    std::cout<<std::endl<<"Invalid input given";
                }
             }
             signing=0;
        }else{
          std::cout<<"Invalid input given.";
        }
    }
 }

 
int main(){
//DECLARE VARIABLES

   

//PRINT LOGO and SIGNING

   asteriks_line(); 
   std::cout<<std::endl<<" \n \t WELCOME TO TREE ONLINE BANKING"<<std::endl<<"\n";
   asteriks_line();
   signing_process();




    
   // std::ifstream in_encrypted_info("secret_file.dat",std::ios::binary);
  //  std::ofstream out_encrypted_info("secret_file.dat",std::ios::binary);
 //   std::ofstream out_account_info("account_file.dat",std::ios::binary);
   // std::ifstream in_account_info("account_file.dat",std::ios::binary);

  /*  if(in_encrypted_info.is_open()){
        crypt(in_encrypted_info, out_account_info,1);
      //    crypt(in_account_info,out_encrypted_info,0) ;

    }else{
        std::cout<<"ERROR: System offline,contact support and retry in a few minutes.";
        exit(1);
    }*/
    return 0;
}