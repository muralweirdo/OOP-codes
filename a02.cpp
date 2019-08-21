#include <iostream>
#include <string>
using namespace std;

// Address class here
class Address {
public:
  int house_no;
  int street;
  string city;
  string country;
  string get_full_address ();
};

string Address::get_full_address (){
  string result = "";
  result = "H. No. " + to_string(house_no) + ", Street " + to_string(street) + ", " + city + ", " + country;
  return result;
}
// Employee class here
class Employee {
public:
  string name;
  Address current_address;
  Address permanent_address;
  void set_current_address(int house_no, int street, string city, string country);
  void set_permanent_address(int house_no, int street, string city, string country);
  void print_addresses();
};

void Employee::set_current_address(int house_no, int street, string city, string country){
  current_address.house_no = house_no;
  current_address.street = street;
  current_address.city = city;
  current_address.country = country;
}

void Employee::set_permanent_address(int house_no, int street, string city, string country){
  permanent_address.house_no = house_no;
  permanent_address.street = street;
  permanent_address.city = city;
  permanent_address.country = country;
}

void Employee::print_addresses(){
  cout << current_address.get_full_address() << endl;;
  cout << permanent_address.get_full_address() << endl;
}

// Wheel class here
class Wheel {
  string state;
public:
  void set_wheel_state(string s);
  string get_wheel_state();
};

void Wheel::set_wheel_state(string s) {
  state = s;
}

string Wheel::get_wheel_state() {
  return state;
}
// Car class here
class Car {
  Wheel array_of_wheels[4];
public:
  void set_car_to_moving() {
    for (int i = 0; i < 4; i++) {
      array_of_wheels[i].set_wheel_state("Turning");
    }
  }
  void set_car_to_stopped() {
    for (int j = 0; j < 4; j++) {
      array_of_wheels[j].set_wheel_state("Stopped");
    }
  }
  void print_car_wheels_state() {
    cout << "Car state:" << endl;
    for (int k = 0; k < 4; k++) {
      cout << "- Wheel " << k << " is " << array_of_wheels[k].get_wheel_state() << endl;
    }
  }
};

int main() {

    // Start of PART - 1  -----------------------
    Address a;

    a.house_no = 4;
    a.street = 25;
    a.city = "Peshawar";
    a.country = "Pakistan";

    cout << a.get_full_address() << endl;

    // End of Part - 1    -----------------------




    // Start of PART - 2  -----------------------

    Employee e1;

    e1.set_current_address(4, 25, "Peshawar", "Pakistan");
    e1.set_permanent_address(14, 9, "Lahore", "Pakistan");
    e1.print_addresses();

    // End of Part - 2     -----------------------




    // Start of PART - 3   -----------------------

    Wheel w1;

    w1.set_wheel_state("Turning");
    cout << w1.get_wheel_state() << endl;

    // End of Part - 3     -----------------------




    // Start of PART - 4   -----------------------

    Car c;

    c.set_car_to_moving();
    c.print_car_wheels_state();

    c.set_car_to_stopped();
    c.print_car_wheels_state();

    // End of Part - 4     -----------------------


    return 0;
}
