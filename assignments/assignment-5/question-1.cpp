#include <iostream>
using namespace std;


class Date{
    int day;
    int month;
    int year;

    public:
    Date(): day(0), month(0), year(0){}
    Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }

    string getDate(){
        // string s={"Date: " + day + "-" + month + "/" + year};
        return "Date: " + to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
};

class Person {
    string name;
    string address;
    Date birthDate; // person has date
    public:
    Person(){}
        Person(string name, string address, int day, int month, int year): birthDate(day, month, year){
        this->name = name;
        this->address = address;
    }
    Person(string name, string address, Date birthDate){
        this->name = name;
        this->address = address;
        this->birthDate = birthDate;
    }

    void printPerson(){
        cout << "------- Person: ------" << endl;
        cout << "Person Name: " << name << endl;
        cout << "Person address: " << address << endl;
        cout << "Person birthdate: " << birthDate.getDate() << endl;
    }

};

class Student {
    int id;
    int marks;
    string course;
    Date joiningDate;
    Date endDate;
    Person person; // student has person

    public:
    Student(){}
    Student(int id, int marks, string course, Date joiningDate, Date endDate, Person person){
        this->id = id;
        this->marks = marks;
        this->course = course;
        this->joiningDate = joiningDate;
        this->endDate = endDate;
        this->person = person;
    }

    void printStudent(){
        person.printPerson();
        cout << "---Student---"<<endl;
        cout << "id: " << id << endl;
        cout << "Marks: " << marks<<endl;
        cout << "course: " << course<<endl;
        cout << "Joining Date: " << joiningDate.getDate() << endl;
        cout << "End Date: " << endDate.getDate() << endl;
    }
};

int main(){

    Date birthDate(13, 12, 2026);
    Date joiningDate(14, 12, 2026);
    Date endDate(15, 12, 2026);

    Person person("Akash", "Telangna", birthDate);

    Student student(1001, 96, "PGCPAC", joiningDate, endDate, person);

    student.printStudent();

    return 0;
}
