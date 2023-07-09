#include <iostream>

int main(){
    int twenty_four_time,hours,minutes;
    int i,a = 0;
    while(i==0){
     std::cout<<"Enter time in 24-hour notation (ex.1425)"<<std::endl;
     std::cin>>twenty_four_time;
        hours = (twenty_four_time/100);    //find the hours
        minutes=(twenty_four_time%100);   //find the minutes
        std::cout<<minutes<<std::endl;
     //tests length of time entered
        int test = twenty_four_time;
        while(test>0){ 
               test/=10;
               a++;
        }
     //Checks time and executes appropriate functions
        if(a<=4 && minutes<60){                           //checks that only four digits have been entered and appropriate minutes
          if(hours>=1 && hours<=12){                     //check whether hours is already in 12
             std::cout<<"The time in 12 hour notation is "<<hours <<":"<<minutes<<std::endl;
             i++;
          }else if(hours>12 && hours<=24){
             hours -=12;                                  //convert hours to 12-hour notation
             std::cout<<"The time in 12 hour notation is "<<hours <<":"<<minutes<<std::endl;
             i++;
          }else{                                          //check for invalid characters
             std::cout<<"Invalid time given"<<std::endl;
          }
        }else{
            std::cout<<"Invalid Time Given"<<std::endl;
            a=0;
        }
    }
return 0;
}