#include <iostream>
using namespace std;

// that is base class
class Product {
    protected:
        int id;
        string title;
        double price;
        static double finalBill;
    public:
        Product(){}
        Product(int id, string title, double price){
            this->id = id;
            this->title = title;
            this->price = price;
        }

        virtual void acceptRecord() = 0;

        virtual void printRecord() = 0;

        int getPrice(){
            // cout << "Final Bill: " << this->finalBill << endl;
            return this->price;
        }

        static void printFinalBill(){
            cout << "----------------"<<endl;
            cout << "Final bill: " << Product::finalBill <<endl;
            cout << "----------------"<<endl;
        }
};

//  thaat is derived class
class Book : public Product {
    string author;
    public:
    const static float discount; // 10%
    Book(){}
    Book(string author, int id, string title, double price): author(author), Product(id, title, price){}

    void acceptRecord(){
        cout << "-----Enter Book Id: ";
        cin >> this->id;
        cout << "-----Enter Book title: ";
        cin >> this->title;
        cout << "-----Enter Book author: ";
        cin >> this->author;
        cout << "-----Enter Book price: ";
        cin >> this->price;
        this->applyDiscount();
    }
    
    void applyDiscount(){
        this->price = this->price - (this->price * Book::discount);
        this->finalBill = this->finalBill + this->price;
    }

    void printRecord(){
        cout << "-----Book Id: " << this->id << endl;
        cout << "-----Book title: " << this->title << endl;
        cout << "-----Book author: "<< this->author << endl;
        cout << "-----Book price: " << this->price << endl;
    }
};

// that is another derived class
class Tape : public Product {
    string artist;
    const static float discount; // 5%

    public:
    Tape(){}
    Tape(string artist, int id, string title, double price): artist(artist), Product(id, title, price){}

    void acceptRecord(){
        cout << "-----Enter Tape Id: ";
        cin >> this->id;
        cout << "-----Enter Tape title: ";
        cin >> this->title;
        cout << "-----Enter Tape artist: ";
        cin >> this->artist;
        cout << "-----Enter Tape price: ";
        cin >> this->price;
        this->applyDiscount();
    }

    void applyDiscount(){
        this->price = this->price - (this->price * Tape::discount);
        this->finalBill = this->finalBill + this->price;
    }

    void printRecord(){
        cout << "-----Tape Id: " << this->id << endl;
        cout << "-----Tape title: " << this->title << endl;
        cout << "-----Tape artist: "<< this->artist << endl;
        cout << "-----Tape price: " << this->price << endl;
    }

};

const float Book::discount = 0.10; 
const float Tape::discount = 0.5; 
double Product::finalBill = 0;


void printActions(){
    cout << "1. Add Book: "<<endl;
    cout << "2. Add Tape : "<<endl;
    cout << "3. Final Bill: "<<endl;
    cout << "0. Exit." << endl;
}

int MenuList(Product *product[], int totalProduct, int &producIndex){
    printActions();
    int action;
    cout << "Enter action: ";
    cin >> action;

    switch (action)
    {
    case 1:
        if(!(producIndex < totalProduct)){
            cout << "Product list is full..." << endl;
            break;
        }
        product[producIndex] = new Book();
        product[producIndex]->acceptRecord();
        producIndex++;
        break;
    case 2:
        if(!(producIndex < totalProduct)){
            cout << "Product list is full...";
            break;
        }
        product[producIndex] = new Tape();
        product[producIndex]->acceptRecord();
        producIndex++;
        break;
    case 3:
        Product::printFinalBill();
        break;
    }

    return action;
}


int main(){

    
    int totalProduct = 3;
    int productIndex = 0;

    Product *product[totalProduct];

    while (MenuList(product, totalProduct, productIndex) != 0 )

    return 0;
}


/*
akram@ubuntu:~/Desktop/module_cpp$ g++ ./assignments/assignment-6/question-1.cpp && ./a.out

1. Add Book: 
2. Add Tape : 
3. Final Bill: 
0. Exit.
Enter action: 1
-----Enter Book Id: 1001
-----Enter Book title: cpp-programming
-----Enter Book author: who-was-created
-----Enter Book price: 100
1. Add Book: 
2. Add Tape : 
3. Final Bill: 
0. Exit.
Enter action: 2
-----Enter Tape Id: 1002
-----Enter Tape title: i-dont-know
-----Enter Tape artist: i-dont-know
-----Enter Tape price: 200
1. Add Book: 
2. Add Tape : 
3. Final Bill: 
0. Exit.
Enter action: 1
-----Enter Book Id: 1003
-----Enter Book title: javascript-prog
-----Enter Book author: i-dont-know
-----Enter Book price: 300
1. Add Book: 
2. Add Tape : 
3. Final Bill: 
0. Exit.
Enter action: 1
Product list is full...
1. Add Book: 
2. Add Tape : 
3. Final Bill: 
0. Exit.
Enter action: 3
----------------
Final bill: 460
----------------
1. Add Book: 
2. Add Tape : 
3. Final Bill: 
0. Exit.
Enter action: 0
Program Finished.

*/