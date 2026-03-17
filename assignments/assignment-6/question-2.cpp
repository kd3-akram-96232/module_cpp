#include <iostream>
using namespace std;

class Employee{
    int id;
    double salary;

    public:
        Employee(){}
        Employee(int id, double salary){
            this->id = id;
            this->salary = salary;
        }

        void setId(int id){
            this->id = id;
        }
        int getId(){
            return id;
        }

        void setSalary(double salary){
            this->salary = salary;
        }
        double getSalary(){
            return this->salary;
        }

        virtual void accept(){
            cout << "Enter emp id: ";
            cin >> this->id;
            cout << "Enter emp salary: ";
            cin >> this->salary;
        }
        virtual void display(){
            cout << "emp id: " << this->id << endl;
            cout << "emp salary: " << this->salary << endl;
        }
};

class Manager: virtual public Employee{
    double bonus;
    public:
        Manager(){}
        Manager(int id, double salary, double bonus){
            this->setId(id);
            this->setSalary(salary);
            this->bonus = bonus;
        }
        void setBonus(double bonus){
            this->bonus = bonus;
        }
        double getBonus(){
            return this->bonus;
        }
        void accept() override{
            Employee::accept();
            this->acceptManager();
        }
        void display() override{
            Employee::display();
            displayManager();
        }
    
        void acceptManager(){
            cout << "Enter bonus: ";
            cin >> bonus;
        }
        void displayManager(){
            cout << "bonus: " << endl;
        }

};

class Salesman: virtual public Employee{
    double commission;

    public:
        Salesman(){}
        Salesman(int id, double salary, double commission){
            this->setId(id);
            this->setSalary(salary);
            this->commission = commission;
        }
        void setCommission(double commission){
            this->setCommission(commission);
        }
        double getCommission(){
            return this->commission;
        }
        void accept(){
            Employee::accept();
            this->acceptSalesman();
        }
        void display(){
            Employee::display();
            this->displaySalesman();
        }
    protected:
        void acceptSalesman(){
            cout << "Enter commission: ";
            cin >> this->commission;
        }
        void displaySalesman(){
            cout << "commision: " << this->commission;
        }
};

class SalesManager: public Manager, public Salesman{
    public:
    SalesManager(){}
    SalesManager(int id, double salary, double bonus, double commission){
        this->setId(id);
        this->setSalary(salary);
        this->setBonus(bonus);
        this->setCommission(commission);
    }

    void accept(){
        Employee::accept();
        Salesman::acceptSalesman();
        Manager::acceptManager();
    }
    void display(){
        Salesman::display();
        Manager::display();
    }
};



int main(){

    SalesManager sm;

    sm.accept();
    sm.display();


    return 0;
}


/*
*akram@ubuntu:~/Desktop/module_cpp$ g++ ./assignments/assignment-6/question-2.cpp && ./a.out
*Enter emp id: 1001
*Enter emp salary: 100
*Enter commission: 10
*Enter bonus: 5
*emp id: 1001
*emp salary: 100
*commision: 10emp id: 1001
*emp salary: 100
*bonus: 
* akram@ubuntu:~/Desktop/module_cpp$ 
*/