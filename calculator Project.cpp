/*OPP Project-1*/
#include<bits/stdc++.h>
using namespace std ;
class Calculator {
private:
   enum enOperations {
      addition = 1,
      subtraction = 2,
      multiplication = 3,
      division = 4,
      cancelOperation = 5,
      getResults = 6,
      clearAll = 7,
      exitProgram = 8
   };

   float _result;
   float _previousResult;
   float _lastReceviedValue;
   string _lastDoneOperation;

   void _setLastValueAndOperation(float receviedValue){
      _lastReceviedValue = receviedValue;
   }
   void _setLastValueAndOperation(string lastOperation){
      _lastDoneOperation = lastOperation;
   }
   void _setLastValueAndOperation(float receviedValue , string lastOperation){
      _lastReceviedValue = receviedValue;
      _lastDoneOperation = lastOperation;
      _previousResult = _result;
   }

   void _clear() {
      _result = 0.0;
      _setLastValueAndOperation(0.0 , "Clearing");
   }
   void _add(float receivedValue){
      _setLastValueAndOperation(receivedValue , "Adding");
      _result += receivedValue;
   }
   void _subtract(float receivedValue){
      _setLastValueAndOperation(receivedValue,"Subtraction");
      _result -= receivedValue;
   }
   void _multiplication(float receivedValue){
      _setLastValueAndOperation(receivedValue , "Multiplying By");
      _result *= receivedValue ;
   }
   void _division(float receivedValue){
      if(!receivedValue){
         _setLastValueAndOperation(1,"Dividing By");
      }
      else {
         _setLastValueAndOperation(receivedValue , "Dividing By");
         _result /= receivedValue ;
      }
   }
   void _cancelLastOperation(){
      if(_lastDoneOperation.compare("") == 0 || _lastDoneOperation.compare("Clearing") == 0){
         _setLastValueAndOperation("");
      }
      else {
         _setLastValueAndOperation("Cancelling Lase Operation");
         _result = _previousResult;
      }
     _displayTheFinalResult();
     _setLastValueAndOperation("");
   }
   void _displayTheFinalResult(){   // rev this function
      cout << "\n==================================\n\n";
      if(_lastDoneOperation.compare("") == 0) {
         cout << "> No operation has done yet !" << endl ;
      }
      else if(_lastDoneOperation.compare("Clearing") == 0 || _lastDoneOperation.compare("Cancelling Lase Operation") ){
         cout << "> The final results after " << _lastDoneOperation << " is [" << _lastReceviedValue + _previousResult << "]\n\n";
      }
      else{
         cout << "> The final results after " << _lastDoneOperation << " is [" << _result << "]\n\n";
      }
      cout << "\n====================================\n\n";
   }
   void _getOperatorsMenu() {
      cout << "--! Enter operation number: !--" << endl ;
      cout << "[1] Addition" << endl;
      cout << "[2] Subtraction" << endl;
      cout << "[3] Multiplication" << endl;
      cout << "[4] Division" << endl;
      cout << "[5] Cancel last operation" << endl;
      cout << "[6] Get the final result" << endl;
      cout << "[7] Clear all" << endl;
      cout << "[8] Exit the program..." << endl;
   }

   float getFloatNumber() {
      float number;
      cout << "please enter a number: ";
      cin >> number;

      return number;
   }

   int getIntgerNumberInRange(int from,int to)
   {
      int choice;

      do{

         cout << "\n ->> Your choice ? ";
         cin >> choice;

         if(choice < from || choice > to )
         {
            cout << "!! Invalid choice [ " << choice << " ]" << endl;
            cout << "- Try again: \n" << endl;
         }

      }while(choice < from || choice > to);

      return choice ;
   }

public:
   Claculator()
   {
      _result = 0.0000;
      _previousResult = 0.0000;
      _lastReceviedValue = 0.0000;
      _lastDoneOperation = "";
   }

   void runCalculatorApp()
   {
      while(true)
      {
         cout << "\n---------------------------------------------------\n\n";
         _getOperatorsMenu();

         switch( (enOperations)getIntgerNumberInRange(1,8) ) {

            case enOperations::addition:
               _add(getFloatNumber());
               break;
            case enOperations::subtraction:
               _subtract(getFloatNumber());
               break;
            case enOperations::multiplication:
               _multiplication(getFloatNumber());
               break;
            case enOperations::division:
               _division(getFloatNumber());
               break;
            case enOperations::cancelOperation:
               _cancelLastOperation();
               break;
            case enOperations::getResults:
               _displayTheFinalResult();
               break;
            case enOperations::clearAll:
               _clear();
               break;
            case enOperations::exitProgram:
               return;
         }
      }
   }
};
int main() {
   Calculator ob ;
   ob.runCalculatorApp();
}
