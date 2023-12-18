#include <bits/stdc++.h>
using namespace std ;

class PersonInterface {
   string name , nationalId , password , gmail ;
   protected:
      PersonInterface(){
         name = gmail = password = gmail = "" ;
      };
      PersonInterface(const string&name , const string&nationalId ,
      const string&password , const string&gmail){
         this->name = name;
         this->nationalId = nationalId;
         this->gmail = gmail ;
         this->password = password;
      }
      void setName(const string&name){this->name = name;}
      string getName()const{return name;}

      void setPassword(const string&password){this->password = password;}
      string getPassword()const{return password;}

      void setGmail(const string&gmail){this->gmail = gmail;}
      string getGmail()const{return gmail;}

      void setNationalId(const string&gmail){this->nationalId = nationalId;}
      string getNationalId()const{return nationalId;}

      friend class CS_StudentManger ;
};
class Student : public PersonInterface { // abstract class 
      float _GPA  ;
      int hours;
      double totalDigree ;
   public:
      Student(const string&name = "", const string&nationalId = "" ,
      const string&password = "", const string&gmail=""):PersonInterface(name,nationalId,password,gmail){
         _GPA = 0.0 ;
         totalDigree = 0.0;
      }
      void setGpa(float _GPA = 0.0 ){this->_GPA = _GPA;}
      float getGpa(){return this->_GPA;}

      void setTotalDigree(double totalDigree) { this->totalDigree = totalDigree ;}
      double getTotalDigree() {return  totalDigree ;}

      virtual void displaySujects() = 0 ;
};
// Function to display all Student if you have a vector
template<class vectorType>
ostream& operator<<(ostream&out, const vector<vectorType>& students){
   out << "Display All Student\n";
   for(int i = 0 ; i < students.size() ; i++ )out << students[i] << endl ;
   return out ;
}

// class for coumputer scinence students
class CS_Student : public Student {
   vector<string>subjectsName={"Operation Research","Project Management","Object Oriented Programming (OOP)","Login Design","Statistics"};
   struct subjectsDigrees{
      double OR , OPP , Network ,PM , Statistcis , LogicDesign ;
   }digrees;
public:
   CS_Student(){
      digrees = {0.0,0.0,0.0,0.0,0.0,0.0} ;
   }
   CS_Student(const string&name = "", const string&nationalId = "" ,const string&password = "", const string&gmail=""):Student(name,nationalId,password,gmail){
      digrees = {0.0,0.0,0.0,0.0,0.0,0.0} ;
   }
   void displaySujects() {
      cout << "Here all collage subjects for computer students(II) term(1)" << endl ;
      cout << subjectsName << endl ;
   }
   friend ostream&operator<<(ostream&,const CS_Student&);
   friend class CS_StudentManger ;
};
// print CS_Student object 
ostream&operator<<(ostream&out,const CS_Student&student){
      out << "======== "<< student.getName() << " Information ======"<<endl ;
      out << "Name: "<<student.getName() << " | Gmail: "<<student.getGmail() << " | ID: "<<student.getNationalId() << endl ;
      out << "======================================\n" ;
      return out ;
}
// class for control Cs Students
class CS_StudentManger {
   private:
      vector<CS_Student> students;
   public:
   void signUp() { // create a new CS student
      string temporaryInput[4] ;
      cout << "\nEnter Name | National_ID | password | gmail (in this order):\n";
      cin >> temporaryInput[0] >> temporaryInput[1] >> temporaryInput[2] >> temporaryInput[3] ;
      CS_Student student(temporaryInput[0],temporaryInput[1],temporaryInput[2],temporaryInput[3]);
      students.push_back(student);
      cout << "Created Successfully..." << endl ;
   }

   void logIn() { // log in cs student
      cout << "Enter your gmail | password (in this order)"<<endl;
      string temporaryInput[2] ;
      cin >> temporaryInput[0] >> temporaryInput[1] ;

      if(searchStudent(temporaryInput[0])) cout << "Log in Successfully"<<endl;
      else cout << "This gmail is not found" << endl ;
   }

   bool searchStudent(const string&gmail) { // seach student
      for(int i=0;i<students.size();i++)
         if(students[i].getGmail() == gmail )
            return 1 ;
      return 0 ;
   }

   void deleteStudent(const string&gmail) { // delete user
      for(int i=0;i<students.size();i++)
         if(students[i].getGmail() == gmail ) {
            // delete
            students.erase(students.begin()+i);
            return ;
         }
         cout << "This Student dosen't exist for deleting..\n" ;
   }

   void ShowAllStudens() {
      for(int i=0 ; i<students.size();i++)
         cout << students << endl ;
   }
};
// M_Abrazeg

int main(){
   // you can creat students from any collage & other persons like Doctors or Assistant...ans so on 
   //  finally compleate functions like gpa & subjects..
   // finally create main , so i'll sleep .. 
}
// try and try and then try ^-^
