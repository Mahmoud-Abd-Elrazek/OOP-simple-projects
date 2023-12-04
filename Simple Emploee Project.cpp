// Simple Employee Project
// YouTube Video ==> " https://www.youtube.com/watch?v=xyIvVmDNS6w&list=PL1DUmTEdeA6KLEvIO0NyrkT91BVle8BOU&index=24 "
#include <iostream>
using namespace std;

class Employee {
   string name ;
   int Emp_id ;
   double salary ;

public:
   Employee():name("unknown"),Emp_id(0),salary(0.000){};
   Employee(string n , int id , double s) {
      name = n ;
      Emp_id = id ;
      salary = s ;
   }
   double getSalary(){return salary ;}
   virtual float get_Total_salary() = 0 ;
   virtual void print(){
      cout << "Name : " << name << "| Id : " << Emp_id << " | Basic Salary : " << salary ;
   }

};
class Sales : public Employee{
   float gross_sales , commission_rate ;
public:
   Sales(string n = "" , int id = 0 , double s = 0.00,float gr_sa = 0.0 ,float comm_rate = 0.0):Employee(n,id,s){
      gross_sales = gr_sa ;
      commission_rate = comm_rate ;
   }
   float get_Total_salary(){ // Override
      return getSalary() + (gross_sales*commission_rate);}
   void print(){
      Employee::print();
      cout << " | Gross Sales : " << gross_sales << " | Commission rate : " << commission_rate << " | Total Salary : " << get_Total_salary() << '\n' ;
   }
};

class Engineer : public Employee{
   string speciality;
   int experience , overtime_hours ;
   float overtime_hour_rate;
public:
   Engineer(string n = "" , int id = 0 , double s = 0.000,string sp = "" , int ex = 0 , int over_hr = 0 , float ovr = 0.00):Employee(n,id,s){
      speciality = sp ;
      experience = ex ;
      overtime_hours = over_hr ;
      overtime_hour_rate = ovr ;
   }
   float get_Total_salary(){
      return getSalary() + (overtime_hours * overtime_hour_rate);
   }

   void print(){
      Employee::print();
      cout << " | speciality : " << speciality << " | experience : " << experience << " | Total Salary : " << get_Total_salary();
   }
};
int main(){

   Employee *ptr ;
   Sales ob("Mahmoud",123,20000,50000,0.10);
   ptr = &ob ;
   ptr->print();

   cout << "\n\n\n\n" ;
   Engineer eng("Khaled",456,10000,"SW Engineer",3,10,50);
   ptr = &eng;
   ptr->print();

   cout << "\n\n\n\n\n" ;

   return 0 ;
}
