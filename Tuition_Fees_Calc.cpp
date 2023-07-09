#include <iostream>

void repeated(int &x , double &y){
        
        std::cout<< "How many modules are you repeating?"<< std::endl;
        std::cin>>x;
        std::cout<<"What are the fees for the repeated modules?"<< std::endl;
        std::cin>> y;
};

void first_Time(int &x , double &y){
        std::cout<<"How many first time modules do you have?"<< std::endl;
        std::cin>> x;
        std::cout<<"What are the fees for the first time modules?"<< std::endl;
        std::cin>>y;
};

//Calculate according to repeated or not 

double calcFees(int x,double y){
    double totalFees = x*y;
    std::cout<< "Your total is R"<<totalFees<< std::endl;
    return totalFees;
};

double calcFees(int x, double y , int a , double b){
    double totalFees = (x*y)+(a*b);
    std::cout<< "Your total is R"<<totalFees<< std::endl;
    return totalFees;
}

int main(){
    int repeat_mods, first_mods ;
    double repeated_fees, first_fees;
    
    char repeat;
    int i = 0;
    while(i==0){
         std::cout<< "Are you repeating any modules?  Y/N: "<< std::endl;
         std::cin>> repeat; 
        if(repeat=='Y' || repeat== 'y'){                       //check whether modules are being repeated or not
            repeated(repeat_mods, repeated_fees);
            first_Time(first_mods, first_fees);
            calcFees(first_mods,first_fees,repeat_mods,repeated_fees);
            i=1;
        }else if(repeat=='N' || repeat =='n'){
            first_Time(first_mods, first_fees);
            calcFees(first_mods,first_fees);
            i=1;
        }else{
           std::cout<<"Invalid answer given"<< std::endl;
        };
    };
   
    return 0;
};