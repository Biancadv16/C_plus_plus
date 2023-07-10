#include <iostream>
#include <fstream>
#include <vector>

int main(){
    
   char data;
   std::vector<char> data_items;
   std::ifstream file("activity.dat", std::ios::in);
   std::ofstream outfile("competition.txt",std::ios::out);
   if(file.is_open()){
     while (file>> std::noskipws >>data){   
         data_items.push_back(data);
      }  
      std::cout<<data_items.size();
    for(int i=0;i<data_items.size();i++){
       char x = data_items[i];
       switch (x){
        case '0':
           outfile<<"s";
           break;
        case '1':
            outfile<<"g";
            break;
        case '2':
            outfile<<"o";
            break;
        case '3':
            outfile<<"y";
            break;
        case '4':
            outfile<<"v";
            break;
        case '5':
            outfile<<"n";
            break;
        case '6':
            outfile<<"f";
            break;
        case '7':
            outfile<<"j";
            break;
        default:
            outfile<<data_items[i];
            break;
       }
    }


     }else{
         std::cout<<"Invalid File!";
     }
     file.close();
     outfile.close();
 return 0;
}
