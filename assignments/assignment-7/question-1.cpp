#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Employee
{
    int id;
    double salary;

public:
    Employee() {}
    Employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;
    }

    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return id;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }
    double getSalary()
    {
        return this->salary;
    }

    virtual void accept()
    {
        cout << "-----Enter emp id: ";
        cin >> this->id;
        cout << "-----Enter emp salary: ";
        cin >> this->salary;
    }
    virtual void display()
    {
        cout << "emp id: " << this->id << endl;
        cout << "emp salary: " << this->salary << endl;
    }
};

class Manager : virtual public Employee
{
    double bonus;

public:
    Manager() {}
    Manager(int id, double salary, double bonus)
    {
        this->setId(id);
        this->setSalary(salary);
        this->bonus = bonus;
    }
    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }
    double getBonus()
    {
        return this->bonus;
    }
    void accept()
    {
        Employee::accept();
        this->acceptManager();
    }
    void display()
    {
        Employee::display();
        displayManager();
    }

    void acceptManager()
    {
        cout << "-----Enter bonus: ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "bonus: " << endl;
    }
};

class Salesman : virtual public Employee
{
    double commission;

public:
    Salesman() {}
    Salesman(int id, double salary, double commission)
    {
        this->setId(id);
        this->setSalary(salary);
        this->commission = commission;
    }
    void setCommission(double commission)
    {
        this->setCommission(commission);
    }
    double getCommission()
    {
        return this->commission;
    }
    void accept()
    {
        Employee::accept();
        this->acceptSalesman();
    }
    void display()
    {
        Employee::display();
        this->displaySalesman();
    }

protected:
    void acceptSalesman()
    {
        cout << "-----Enter commission: ";
        cin >> this->commission;
    }
    void displaySalesman()
    {
        cout << "commision: " << this->commission;
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager() {}
    SalesManager(int id, double salary, double bonus, double commission)
    {
        this->setId(id);
        this->setSalary(salary);
        this->setBonus(bonus);
        this->setCommission(commission);
    }

    void accept()
    {
        Employee::accept();
        Salesman::acceptSalesman();
        Manager::acceptManager();
    }
    void display()
    {
        Salesman::display();
        Manager::display();
    }
};

//  (product[i] != nullptr) {
// if (typeid(*product[i]) == typeid(Book)) {
// bookCount++;
// } else if (typeid(*product[i]) == typeid(Tape)) {
// tapeCount++;
// }

void printActions(){
    cout << "1. Add Manager"<<endl;
    cout << "2. Add Salesman"<<endl;
    cout << "3. Add SalesManager"<<endl;
    cout << "4. Display count of emps with designation"<<endl;
    cout << "5. Display all managers"<<endl;
    cout << "6. Display all salesman"<<endl;
    cout << "7. Display all salesmanagers"<<endl;
}

void displayAllManagers(Employee *emps[], int currentEmp){
}

int menuList(Employee *emps[], int totalEmps, int &currentEmp)
{
    printActions();
    int action;
    cout << "Enter action: ";
    cin >> action;

    switch (action)
    {
        case 1:
            if(totalEmps <= currentEmp){
                cout << "Employees list is full."<<endl;
                break;
            }
            emps[currentEmp] = new Manager();
            emps[currentEmp]->accept();
            currentEmp++;
            break;
        case 2:
            if(totalEmps <= currentEmp){
                cout << "Employees list is full."<<endl;
                break;
            }
            emps[currentEmp] = new Salesman();
            emps[currentEmp]->accept();
            currentEmp++;
            break;
        case 3:
            if(totalEmps <= currentEmp){
                cout << "Employees list is full."<<endl;
                break;
            }
            emps[currentEmp] = new SalesManager();
            emps[currentEmp]->accept();
            currentEmp++;
            break;
        case 4:
        {

            int countManager = 0;
            int countSalesman = 0; 
            int countSalesManager = 0;
            
            for(int i=0; i<currentEmp; i++){
                
                if(typeid(*emps[i]) == typeid(Manager)){
                        countManager++;
                    }
                    if(typeid(*emps[i]) == typeid(Salesman)){
                        countSalesman++;
                    }
                    if(typeid(*emps[i]) == typeid(SalesManager)){
                        countSalesManager++;
                    }
                }
                
                cout << "--------------------"<<endl;
                cout << "Total manager: " << countManager <<endl;
                cout << "Total salesman: " << countSalesman <<endl;
                cout << "Total salesmanager: " << countSalesManager <<endl;
                cout << "--------------------"<<endl;
            }
            break;
            case 5:{
                // print all managers
                for(int i=0; i<currentEmp; i++){
                    if(typeid(*emps[i]) == typeid(Manager)){
                        emps[i]->display();
                    }
                }
            }
            break;
            case 6: {
                // print all salesman
                for(int i=0; i<currentEmp; i++){
                    if(typeid(*emps[i]) == typeid(Salesman)){
                        emps[i]->display();
                    }
                }
            }
            break;
            case 7:{
                // salesmanager
                for(int i=0; i<currentEmp; i++){
                    if(typeid(*emps[i]) == typeid(SalesManager)){
                        emps[i]->display();
                    }
                }
            }
            break;
    }

    return action;
}

int main()
{

    int totalEmps = 3;
    int currentEmp = 0;

    cout << "How much do you have employees: ";
    cin >> totalEmps;


    Employee *emps[totalEmps];

    while(menuList(emps, totalEmps, currentEmp) != 0){
        
    };

    return 0;
}