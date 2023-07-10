#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

//CHeck whether the balance is less than 1000

void balance_check(double x, double &y,double &z){
    if(x<1000){
        y=25;
        z+=25;
    }else{
        y=0;
    }
}
//print to output the transaction types and amounts

void print_line(std::string x,double y,double a,double b){
 std::cout<<x<<"\t"<<std::setprecision(2) << std::fixed <<y<<"\t\t"<< a <<"\t   \t"<<b<<std::endl;
}

int main(){

    std::string data;
    std::vector<std::string> data_items;
    std::ifstream file(".dat", std::ios::in);
    //Check whether the file opened correctly
   if(file.is_open()){
     while (getline(file,data,' ')) {   //add strings to file
        data_items.push_back(data);
     }
     int account_num= stoi(data_items[0]);     //change strings to integers
     double balance=stod(data_items[1]);
     double extra_costs_total;
     std::cout<<"Account number: "<<account_num<<std::endl;
     std::cout<<"\nOpening Balance: R"<<std::setprecision(2) << std::fixed <<balance<<std::endl;
     std::cout<<"\nTransaction \t"<<"Amount \t \t"<<"Balance \t"<<"Bank Costs \t"<<std::endl;

     //CHeck whether values are withdraws,deposits or interests
     for(int i=2;i<data_items.size();i+=2){
        std::string x=data_items[i];
        double y=stod(data_items[i+1]);       //string to double 
        double bank_costs;
        if(x.find('W')!= std::string::npos){
            balance-=y;
            std::string type="Withdrawal";
            balance_check(balance,bank_costs,extra_costs_total);
            print_line(type,y,balance,bank_costs);
          
        }else if(x.find('D')!= std::string::npos){
            balance+=y;
            std::string type = "Deposit      ";
             balance_check(balance,bank_costs,extra_costs_total);
             print_line(type,y,balance,bank_costs);
            
        }else if(x.find('I')!= std::string::npos){
            balance-=y;
            std::string type = "Interest";
            balance_check(balance,bank_costs,extra_costs_total);
            print_line(type,y,balance,bank_costs);
            
        }
     }
     double total = balance-extra_costs_total ;
     std::cout<<"Banking costs \t"<<extra_costs_total<<"\t\t" <<total<<std::endl;
     std::cout<<"\nClosing Balance: R"<<total;
   }else{
        std::cout<<"File opening failed!";
    }
    file.close();
    return 0;
}