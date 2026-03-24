#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches %= 12;
        } else if (inches < 0) {
            int borrow = (-inches / 12) + 1;
            feet -= borrow;
            inches += borrow * 12;
        }
    }

public:
    Distance(int f = 0, int i = 0) {
        feet = f;
        inches = i;
        normalize(); 
    }

    Distance operator+(const Distance& d) {
        Distance temp;
        temp.feet = this->feet + d.feet;
        temp.inches = this->inches + d.inches;
        temp.normalize();
        return temp;
    }

    Distance& operator++() {
        inches++;
        normalize();
        return *this;
    }

    friend Distance& operator--(Distance& d);

    friend istream& operator>>(istream& in, Distance& d) {
        cout << "  Feet: ";
        in >> d.feet;
        cout << "  Inches: ";
        in >> d.inches;
        d.normalize();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Distance& d) {
        out << d.feet << " feet, " << d.inches << " inches";
        return out;
    }
};

Distance& operator--(Distance& d) {
    d.inches--;
    d.normalize();
    return d;
}

int main() {
    Distance d1, d2, d3;

    cout << "Enter the first distance (d1):\n";
    cin >> d1;

    cout << "\nEnter the second distance (d2):\n";
    cin >> d2;

    cout << "\n--- Output Results ---\n";
    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;

    d3 = d1 + d2;
    cout << "\nAddition (d1 + d2) = " << d3 << endl;

    ++d1;
    cout << "After ++d1 (incrementing d1) = " << d1 << endl;

    --d2;
    cout << "After --d2 (decrementing d2) = " << d2 << endl;

    return 0;
}