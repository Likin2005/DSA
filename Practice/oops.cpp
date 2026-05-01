#include <iostream>
#include <string>
using namespace std;

// 1. BASE CLASS (Encapsulation + Abstraction)
class Vehicle {
private:
    string brand;
    int speed;

public:
    // Constructor
    Vehicle(const string& b = "Unknown", int s = 0) : brand(b), speed(s) {}

    // Public interface (Abstraction)
    void start() {
        cout << brand << " vehicle started.\n";
    }

    // Getters / setters (Encapsulation)
    void setSpeed(int s) {
        if (s >= 0) speed = s;
    }
    int getSpeed() const { return speed; }

    string getBrand() const { return brand; }

    // Virtual function for runtime polymorphism
    virtual void honk() const {
        cout << "Vehicle honks!\n";
    }

    // Destructor
    virtual ~Vehicle() {
        cout << "Vehicle " << brand << " destroyed.\n";
    }
};

// 2. INHERITANCE (Derived class)
class Car : public Vehicle {
private:
    string model;

public:
    Car(const string& b, const string& m, int s) : Vehicle(b, s), model(m) {}

    // Function overloading (Compile‑time polymorphism)
    void honk() const override {
        cout << getBrand() << " Car (" << model << ") says: Beep Beep!\n";
    }

    // Overloaded method (same name, different parameters)
    void honk(int times) const {
        for (int i = 0; i < times; ++i) {
            cout << getBrand() << " Car honks once.\n";
        }
    }

    // Destructor
    ~Car() {
        cout << "Car " << getBrand() << " destroyed.\n";
    }
};

// 3. ANOTHER CLASS (for Friend + Operator overloading)
class Garage {
private:
    string location;

public:
    Garage(const string& loc = "Unknown") : location(loc) {}

    // Friend function (can access private members of Vehicle)
    friend void park(const Vehicle& v, const Garage& g);

    // Operator overloading (for Garage)
    Garage operator+(const Garage& g) const {
        Garage combined("Combined Garage: " + location + " & " + g.location);
        return combined;
    }

    const string& getLocation() const { return location; }
};

// Friend function definition
void park(const Vehicle& v, const Garage& g) {
    cout << v.getBrand() << " is parked at " << g.getLocation() << ".\n";
}

// 4. POLYMORPHISM EXAMPLE (using pointers)
void sound(const Vehicle* v) {
    v->honk();
}

// 5. RUNNABLE EXAMPLE IN MAIN
int main() {
    cout << "--- OOPs Concepts in C++ Demo ---\n\n";

    // 1. Objects and Constructors
    Vehicle v1("Generic Vehicle", 60);
    Car c1("Toyota", "Camry", 120);

    // 2. Encapsulation (setting data via public methods)
    v1.setSpeed(80);

    // 3. Abstraction (using public interface)
    v1.start();
    c1.start();

    // 4. Compile‑time polymorphism (function overloading)
    c1.honk();
    c1.honk(3);

    // 5. Runtime polymorphism (base class pointer)
    Vehicle* ptr = &c1;
    sound(ptr);  // calls Car::honk()

    // 6. Friend function
    Garage g1("Central Garage");
    Garage g2("South Garage");
    Garage g3 = g1 + g2;  // Operator overloading

    cout << "\n--- Using friend and operator overloading ---\n";
    park(v1, g1);
    park(c1, g2);
    cout << "Combined garage: " << g3.getLocation() << "\n";

    // 7. Destructors will be called automatically
    cout << "\n--- Destructors ---\n";

    return 0;
}