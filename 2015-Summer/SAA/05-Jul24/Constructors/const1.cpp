#include <iostream>
#include <cstring>
using namespace std;


class Base{
   int _data;
public:
   Base():_data(0){
      cout << "Base Def" << endl;
   }
   Base(int data) :_data(data){ 
      cout << "Crt Base: " << _data << endl;
   }
   Base(const Base& B):_data(B._data){
      cout << "Cpy Base: " << _data << endl;
   }
   void data(int value){
      _data = value;
   }
   int data()const{
      return _data;
   }
   void act(){
      cout << "Base acting with " << data() << endl;
   }
   virtual ostream& display(ostream& os)const{
      return os << "Base is holding " << data();
   }
   ~Base(){
      cout << "Dst Base: " << _data << endl;
   }
};

ostream& operator<<(ostream& os, const Base& B){
   return B.display(os);
}
class Derived :public Base{
   char _title[81];
public:
   Derived(){
      strcpy(_title, "No name");
      cout << "Def Derived: " << _title << endl;
   }
   Derived(const char* title, int data) :Base(data){ // intialized Base with data
      strncpy(_title, title, 40);
      _title[40] = (char)0;
      cout << "Crt Derived: " << _title << endl;
   }
   Derived(const Derived& D){
      strcpy(_title, "Copy of ");
      strcat(_title, D._title);
      cout << "Cpy Derived: " << D._title <<"->" << _title << endl;
   }
   Derived& operator=(const Derived& RO){
      cout << "Set Derived: <" << _title << "," << data() << "> to <" << RO._title << "," << RO.data() <<">" << endl;
      strcpy(_title, RO._title);
      data(RO.data());
      return *this;
   }
   ostream& display(ostream& os)const{
      return os << _title << " has the value " << data();
   }
   ~Derived(){
      cout << "Dst Derived: " << _title << endl;
   }
};


void Act(Base b){
  b.act();
}
Base MakeBase(int a){
  Base x(a);
  return x;
}
int main(){
  Base Z = Base(10);
  Base B(1000);
//  Base B1 = B;
//  Base A = 100;
  Base B1 (B);
  Base A(100);
  Act(A);
  A = MakeBase(200);
  Act(MakeBase(300));
  return 0;
}