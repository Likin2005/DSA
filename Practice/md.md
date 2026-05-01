Table of Contents

Introduction to OOP in C++
Core OOP Concepts (Detailed Breakdown)
Comparison of Similar Concepts
Mind Map of OOP Concepts
Interview Rapid Revision Sheet
Top 50 OOP Interview Questions & Answers (C++ Focused)


1. Introduction to OOP in C++
C++ is a multi-paradigm language that strongly supports Object-Oriented Programming. The four main pillars are:

Encapsulation
Abstraction
Inheritance
Polymorphism

OOP promotes code reusability, maintainability, scalability, and modeling of real-world entities.

2. Core OOP Concepts
Class & Object
Definition

Textbook: A class is a user-defined blueprint that binds data and functions. An object is an instance of a class.
Interview-winning: Class is the blueprint; Object is the actual instance with its own state in memory.

Concept Explanation
Classes support data hiding and modularity. Objects can be created on stack or heap. Internally, each object holds its data members + a hidden this pointer (and vptr if virtual functions exist). Empty class size is 1 byte.
Real-Life Analogy
Class = Car design document; Object = Actual manufactured car.
Code Implementation (C++)
C++class Car {
public:
    std::string color;
    int speed = 0;
    void accelerate() {
        speed += 10;
        std::cout << "Speed: " << speed << std::endl;
    }
};

int main() {
    Car myCar;                    // Object on stack
    myCar.color = "Red";
    myCar.accelerate();
}
Key Points

class defaults to private; struct to public.
Common mistake: Treating classes as plain data bags.

Access Specifiers (public, private, protected)
Definition
Keywords controlling visibility of class members.
Explanation

public: Accessible everywhere.
private: Only inside class (and friends).
protected: Inside class + derived classes.

Why it exists: Enforces encapsulation.
Code
C++class BankAccount {
private:
    double balance = 0.0;
public:
    void deposit(double amt) {
        if (amt > 0) balance += amt;
    }
    double getBalance() const { return balance; }
};
Encapsulation
Definition
Bundling data and methods that operate on it, while restricting direct access.
Interview-winning: "Capsule that protects internal data and exposes only safe interface."
Real-Life Analogy
Medicine capsule — active ingredient hidden, only outer shell visible.
Best Practice: Make data members private by default.
Constructor
Definition
Special member function called automatically on object creation to initialize state.
Types: Default, Parameterized, Copy Constructor.
Code
C++class Employee {
    int id;
    std::string name;
public:
    Employee(int i, std::string n) : id(i), name(std::move(n)) {}  // Member initializer list
};
Key Point: Use initializer list for efficiency and const/reference members.
this Pointer
Definition
Implicit pointer to the current object in non-static member functions.
Use cases: Disambiguate names, return *this for chaining, pass current object.
Copy Constructor & Shallow vs Deep Copy
Copy Constructor: Creates new object as copy of existing one.
Signature: Class(const Class& other)
Shallow Copy (default): Copies pointers → shared memory (dangerous).
Deep Copy: Allocates new memory and copies content (safe for resources).
Rule of Five: If you define destructor, copy ctor, copy assignment → also consider move ctor and move assignment.
Destructor
Definition
Special function (~Class()) called when object is destroyed for resource cleanup.
Critical Point: Make destructor virtual in base classes for polymorphic deletion.
C++virtual ~Base() = default;
Inheritance
Definition
Mechanism allowing a derived class to inherit properties from a base class (is-a relationship).
Modes of Inheritance:

public: Most common (is-a)
protected
private: Implementation inheritance

Types: Single, Multilevel, Multiple, Hierarchical, Hybrid.
Diamond Problem: Occurs in multiple inheritance when two paths lead to same base class. Solved by virtual inheritance.
Polymorphism
Definition
"One interface, multiple implementations."
Types:

Compile-time: Function Overloading, Operator Overloading
Run-time: Virtual functions + Overriding

Function Overloading
Same name, different parameters → resolved at compile time.
Function Overriding
Derived class redefines base class virtual function with same signature.
Virtual Function
Definition
Function declared virtual in base class for dynamic dispatch.
Internally: Uses vtable (virtual table — array of function pointers) and vptr (virtual pointer) in each object.
C++class Shape {
public:
    virtual void draw() { std::cout << "Shape\n"; }
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "Circle\n"; }
};
Key: Use override keyword (C++11) for safety.
Abstraction
Definition
Hiding complex implementation details and showing only necessary features.
Achieved using Abstract Classes (with pure virtual functions).
Abstract Class
Class containing at least one pure virtual function (virtual void func() = 0;). Cannot be instantiated.
Static Keyword (OOP Context)

static data member: Shared across all objects, one copy per class.
static member function: No this pointer, can be called without object.

C++class Counter {
public:
    static int count;
    static void increment() { count++; }
};
int Counter::count = 0;

3. Comparison Section
Encapsulation vs Abstraction

Encapsulation → Bundling + Data Protection (how)
Abstraction → Hiding complexity, exposing interface (what)

Overloading vs Overriding

Overloading: Same scope, different parameters, compile-time
Overriding: Inheritance + virtual, same signature, run-time

Shallow vs Deep Copy

Shallow: Fast, pointer sharing → risk of double-delete
Deep: Safe, independent memory

Virtual Function vs Pure Virtual

Virtual: Can have default implementation
Pure Virtual: Makes class abstract (= 0)

Class vs Struct
Only difference is default access specifier (private vs public).

4. Mind Map (Text-based)
textOOP in C++
├── Pillars
│   ├── Encapsulation (Access Specifiers + Getters/Setters)
│   ├── Abstraction (Abstract Classes, Pure Virtual)
│   ├── Inheritance (is-a, Modes, Types, Virtual Inheritance for Diamond)
│   └── Polymorphism
│       ├── Compile-time (Overloading)
│       └── Run-time (Virtual + Overriding + vtable/vptr)
├── Building Blocks
│   ├── Class & Object
│   ├── Constructor (incl. Copy) + this pointer
│   ├── Destructor (must be virtual in base)
│   ├── Shallow vs Deep Copy (Rule of Five)
│   └── Static members/functions
└── Advanced
    ├── Friend functions
    ├── Multiple Inheritance + Diamond Problem
    └── RAII Principle

5. Interview Rapid Revision

4 Pillars of OOP and their C++ implementation.
Difference between class and struct.
Access specifiers and their effect in inheritance.
Why make destructor virtual in base class?
vtable and vptr mechanism for virtual functions.
Shallow vs Deep copy — when each is dangerous.
Rule of Five in modern C++.
Diamond problem and solution using virtual inheritance.
override and final keywords.
When to prefer composition over inheritance.
Difference between abstraction and encapsulation.
Can constructor be virtual? (No)


6. Top 50 OOP Interview Questions & Answers (C++ Focused)
Here is a curated list of the most frequently asked OOP questions in C++ interviews (2025–2026):

What is OOP? Why do we need it?
Answer: Paradigm based on objects. Benefits: reusability, maintainability, real-world modeling.
What are the 4 pillars of OOP?
Encapsulation, Abstraction, Inheritance, Polymorphism.
Difference between class and object?
Class = blueprint; Object = instance.
Difference between class and struct in C++?
Default access: private vs public.
What is encapsulation? How is it achieved in C++?
Bundling + data hiding using access specifiers.
What is abstraction? How is it different from encapsulation?
Explain constructors in C++. Can they be virtual?
No, constructors cannot be virtual.
What is a copy constructor? When is it called?
Explain shallow copy vs deep copy with example.
(Mention risks with raw pointers)
What is 'this' pointer? Where is it not available?
Not in static member functions.
What is a destructor? Why should it be virtual?
To ensure correct cleanup when deleting derived object via base pointer.
Explain inheritance. What are different modes of inheritance?
What is the diamond problem in C++? How do you solve it?
Solved using virtual inheritance.
What is polymorphism? Types in C++?
Difference between function overloading and overriding?
What is a virtual function? Explain vtable and vptr.
(Very high-frequency question)
What is pure virtual function? What is an abstract class?
Can we create object of abstract class?
What are static members in a class?
Difference between static and non-static member functions.
Explain friend function and friend class.
What is operator overloading?
Can we overload main() function?
What is RAII? How is it related to constructors/destructors?
Explain Rule of Three / Rule of Five.
What happens if we delete a derived object using base pointer without virtual destructor?
Undefined behavior.
What is multiple inheritance? Pros and cons.
What is virtual inheritance?
Difference between private and protected inheritance.
Can constructor call virtual function? What happens?
(Calls base version — avoid it)
What is final keyword (C++11)?
What is override keyword? Why use it?
Explain const correctness in member functions.
What is mutable keyword?
Can static function be virtual?
No.
Difference between early binding and late binding.
How does dynamic dispatch work in C++?
What is composition? When to prefer it over inheritance?
"Favor composition over inheritance."
Explain has-a vs is-a relationship.
What are pure virtual destructors? Are they allowed?
Can we have virtual constructors?
What is slicing problem in C++?
How to prevent object copying?
(Delete copy ctor and copy assignment)
What is Singleton pattern? How to implement in C++?
Explain Factory design pattern (OOP context).
What is the difference between interface and abstract class in C++?
(C++ has no interface keyword — use abstract class with only pure virtuals)
Explain upcasting and downcasting.
What are the disadvantages of deep inheritance hierarchies?
How does C++ achieve runtime polymorphism?
Give a real project example where you used OOP principles effectively.