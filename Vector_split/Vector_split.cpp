#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string target, string delimiter) {
  vector<string> end;
  int x = 0;
  string data;
  while ((x = target.find(delimiter)) != string::npos) {
    data = target.substr(0, x);
    end.push_back(data); //add to split vector
    target.erase(0, x + delimiter.length());
  }
 end.push_back(target);
 return end;
}

int main() {
  string target = "do,re,me,fa,so,la,ti,do";
  string delimiter = ",";

  //Call function and assign to future split vector
  vector<string> end = split(target, delimiter);
  //Display the divided vector
  for (string temp : end) {
    cout << temp << endl;
  }
 return 0;
}
