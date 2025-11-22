/* 
this follows SRP:
Employee, PayCalculator, EmployeeRepository, 
and EmployeeReportFormatter — each with a single responsibility 
and one reason to change. This makes the design easier to maintain,
 test, and extend.”
*/

#include<bit/stdc++.h>
using namespace std;

class Employee {
    public:
        string name;
        double salary;
        Employee(string name, double salary) : name(name), salary(salary) {}

        double calculatePay() {
            return salary;
        }
};
class EmployeeDatabase {
    public:
        void saveToDatabase(const Employee& emp) {
            // code to save employee details to database
        }
};
class EmployeeReport {
    public:
        void generateReport(const Employee& emp) {
            // code to generate employee report
        }
};

int main()
{
    Employee emp("John Doe", 50000);
    EmployeeDatabase db;
    EmployeeReport report;

    double pay = emp.calculatePay();
    db.saveToDatabase(emp);
    report.generateReport(emp);

    return 0;
}

/* 
class CustomerDetails {
private:
  string name;
  int id;
public:
  void setName(string name);
  string getName();
  void setId(int id);
  int getId();
};

class BillingCalculator {
private:
  vector<Item> items;
public:
  void addItem(Item item);
  void removeItem(Item item);
  float calculateTotalAmount();
};

class InvoiceGenerator {
public:
  string generateInvoice(CustomerDetails customerDetails, BillingCalculator billingCalculator);
};

By dividing the responsibilities of the Customer class into smaller, 
more focused classes, each class has only one responsibility, which makes the code more maintainable and scalable.

*/