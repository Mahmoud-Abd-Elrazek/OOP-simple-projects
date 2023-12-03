#include <iostream>
#include <string>
#include<vector>

using namespace std;

class User{ // This is a user Model
private:
   string username , password ;
public:
   User(string name , string pass){
      username = name ;
      password = pass ;
   }
   string getUserName(){return username;}
   string getPassword(){return password;}
};
class UserManager {
private:
   vector<User> users ; // vector of User
public:
   // Register Function
   void registerUser() {
      string username , password ;
      cout << "\t\tEnter User Name : ";
      cin >> username ;
      cout << "\t\tEnter Password : ";
      cin >> password ;

      User newUser(username,password);
      users.push_back(newUser) ;

      cout << "\t\t User Register Successfully...\n" ;
   }

   // Login Function
   void LoginUser(string name , string pass) {

      for(int i=0 ; i< (int)users.size() ; i++){
         if(users[i].getUserName() == name && users[i].getPassword() == pass) {
            cout << "\t\tLogin Successfully....\n";
            return ;
         }
      }
      cout << "\t\t Invalid" ;
      return ;

   }

   // Search Function
   bool SearchUser(string name , string pass) {
      for(int i=0 ; i< (int)users.size() ; i++){
         if(users[i].getUserName() == name && users[i].getPassword() == pass) {
            cout << "\t\tFound....\n";
            return 1;
         }
      }
      cout << "\t\t NotFound" ;
      return 0 ;
   }

   // Display All User account in your List
   void showUsers(){
      if(!(users.size())){
         cout << "\t\t*EMPTY LIST"<<endl;
         return ;
      }
      cout << "\t\t---users List---" << endl ;
      cout << "\t\tNAEMES | PASSWORDS"<<endl;
      for(auto i=0 ; i<users.size();i++){
         cout << "\t\t"<<users[i].getUserName() << " | " << users[i].getPassword() << endl ;
      }
      cout << endl ;
   }

   // Delete User from your List
   void deleteUser(string name , string pass){
      for(int i=0 ; i<users.size();i++){
         if(users[i].getUserName() == name && users[i].getPassword() == pass) {
            // now delete this user
            users.erase(users.begin()+i);
            cout << "\t\tUser deleted Successfully..." << endl ;
            return ;
         }
      }
      cout << "\t\*Tthis user account is not found to delete"<<endl;
   }
};

// This is a stat menu function
void StartMenue(){
      cout << "\n\n\t\t1. Register User\n";
      cout << "\t\t2. Login \n";
      cout << "\t\t3. Show User List \n";
      cout << "\t\t4. Search User \n";
      cout << "\t\t5. Delete User \n";
      cout << "\t\t6. Exit \n";
      cout << "\t\t:";
}
int main(){

   UserManager usermanage ;
   string cont = "" ;
   int option;
   do {
      StartMenue();
      cin >> option ;
      switch(option){
         case 1:{
            usermanage.registerUser();
            break ;
         }
         case 2:{
            string username,password;
            cout << "\t\tEnter user name:";
            cin >> username ;
            cout << "\t\tEnter password:";
            cin >> password ;
            usermanage.LoginUser(username,password);
            break ;
         }
         case 3:{
            usermanage.showUsers();
            break;
         }
         case 4:{
            cout << "\t\tEnter Name and Password (in this oreder) to search this user account" << endl ;
            string name = ""  , password ;
            cout << "\t\t: " ;
            cin >> name >> password ;
            usermanage.SearchUser(name , password);
            break ;
         }
         case 5:{
            cout << "\t\tEnter Name and Password (in this oreder) to delete this user account" << endl ;
            string name = ""  , password ;
            cout << "\t\t: " ;
            cin >> name >> password ;
            usermanage.deleteUser(name,password);
            break ;
         }
         case 6:{
            exit(1);
         }
      }
      cout << "\t\tDo you want to continue [Yes/No] ? : ";
      cin >> cont ;
      for(auto&i : cont){ // This to convert any style of 'yeS||YES||Yes||YEs..' to 'yes'
         i = tolower(i) ;
      }
   }while(cont == "yes");
}
