/* 
here, exployee class having 3 responsibilities
❌ Why it violates SRP?

+ Salary rules change → class changes
+ Database rules change → class changes
+ Report formatting changes → class changes

One class, three reasons to change → violates SRP.

*/



#include<bit/stdc++.h>
using namespace std;
class Employee{
    public:
        string name;
        double salary;
        Employee(string name,double salary):name(name),salary(salary){}

        double calculatPay(){
            return salary;
        }
        void saveToDatabase(){
            //code to save employee details to database
        }
        void generateReport(){
            //code to generate employee report
        }
};

/* 
Example :>

class Customer {
private:
  string name;
  int id;
  vector<Item> items;
  float totalAmount;
public:
  void setName(string name);
  string getName();
  void setId(int id);
  int getId();
  void addItem(Item item);
  void removeItem(Item item);
  float calculateTotalAmount();
  string generateInvoice();
};

Customer class is responsible for multiple tasks, such as maintaining customer details,
calculating the final bill, and generating an invoice. 
This violates the Single Responsibility Principle, as the class has multiple reasons to change.
*/