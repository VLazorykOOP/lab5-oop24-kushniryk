#include <iostream>
#include <string>

using namespace std;

class Point {
protected:
    double x;
    double y;

public:
    // Конструктор за замовчуванням
    Point() : x(0.0), y(0.0) {}

    // Конструктор з параметрами
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    // Деструктор
    ~Point() {
        cout << "Point object destroyed" << endl;
    }

    // Функція друку
    virtual void print() const {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }

    // Функції перепризначення координат точки
    void setCoordinates(double newX, double newY) {
        x = newX;
        y = newY;
    }

    // Функція виведення координат точки
    void getCoordinates() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

class ColorPoint : public Point {
private:
    string color;

public:
    // Конструктор за замовчуванням
    ColorPoint() : Point(), color("black") {}

    // Конструктор з параметрами
    ColorPoint(double xCoord, double yCoord, const string& clr) : Point(xCoord, yCoord), color(clr) {}

    // Деструктор
    ~ColorPoint() {
        cout << "ColorPoint object destroyed" << endl;
    }

    // Функція друку
    void print() const override {
        cout << "Color Point: (" << x << ", " << y << "), Color: " << color << endl;
    }

    // Функція перепризначення кольору
    void setColor(const string& clr) {
        color = clr;
    }
};

class Processor {
private:
    int powerMHz; // Потужність в МГц

public:
    // Конструктор за замовчуванням
    Processor() : powerMHz(0) {}

    // Конструктор з параметрами
    Processor(int power) : powerMHz(power) {}

    // Метод доступу до потужності
    int getPower() const {
        return powerMHz;
    }
};

class Computer {
private:
    Processor cpu; // Композиція - клас Processor в складі класу Computer
    string brand;
    double price;

public:
    // Конструктор за замовчуванням
    Computer() : brand(""), price(0.0) {}

    // Конструктор з параметрами
    Computer(int power, const string& b, double p) : cpu(power), brand(b), price(p) {}

    // Деструктор
    ~Computer() {
        cout << "Computer object destroyed" << endl;
    }

    // Функція друку
    void print() const {
        cout << "Brand: " << brand << ", Price: " << price << ", Processor Power: " << cpu.getPower() << " MHz" << endl;
    }
};

class Desktop : public Computer {
private:
    double screenSize; // Розмір монітора

public:
    // Конструктор за замовчуванням
    Desktop() : Computer(), screenSize(0.0) {}

    // Конструктор з параметрами
    Desktop(int power, const string& b, double p, double size) : Computer(power, b, p), screenSize(size) {}

    // Деструктор
    ~Desktop() {
        cout << "Desktop object destroyed" << endl;
    }

    // Функція друку
    void print() const {
        cout << "Desktop - ";
        Computer::print();
        cout << "Monitor Size: " << screenSize << " inches" << endl;
    }
};

class Person {
protected:
    string name;
    int age;

public:
    // Конструктор за замовчуванням
    Person() : name(""), age(0) {}

    // Конструктор з параметрами
    Person(const string& n, int a) : name(n), age(a) {}

    // Конструктор копіювання
    Person(const Person& other) : name(other.name), age(other.age) {}

    // Оператор присвоювання
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    // Функція виводу у потік
    friend ostream& operator<<(ostream& out, const Person& person) {
        out << "Name: " << person.name << ", Age: " << person.age;
        return out;
    }

    // Функція введення з потоку
    friend istream& operator>>(istream& in, Person& person) {
        cout << "Enter name: ";
        in >> person.name;
        cout << "Enter age: ";
        in >> person.age;
        return in;
    }
};

class Employee : public Person {
private:
    string position;

public:
    // Конструктор за замовчуванням
    Employee() : Person(), position("") {}

    // Конструктор з параметрами
    Employee(const string& n, int a, const string& pos) : Person(n, a), position(pos) {}

    // Конструктор копіювання
    Employee(const Employee& other) : Person(other), position(other.position) {}

    // Оператор присвоювання
    Employee& operator=(const Employee& other) {
        if (this != &other) {
            Person::operator=(other);
            position = other.position;
        }
        return *this;
    }

    // Функція виводу у потік
    friend ostream& operator<<(ostream& out, const Employee& employee) {
        out << static_cast<const Person&>(employee) << ", Position: " << employee.position;
        return out;
    }

    // Функція введення з потоку
    friend istream& operator>>(istream& in, Employee& employee) {
        in >> static_cast<Person&>(employee);
        cout << "Enter position: ";
        in >> employee.position;
        return in;
    }
};


int main() {
    cout << " Lab #5  !" << endl;
    int task;
    cout << "Enter task: ";
    cin >> task;
    switch (task) {
    case 1: {
        // Тестування класу Point
        Point point1(2.5, 3.0);
        cout << "Testing Point class:" << endl;
        point1.print();
        cout << "Coordinates: ";
        point1.getCoordinates();
        point1.setCoordinates(5.0, 7.0);
        cout << "New coordinates: ";
        point1.getCoordinates();
        cout << endl;

        // Тестування класу ColorPoint
        ColorPoint colorPoint1(1.0, 1.0, "red");
        cout << "Testing ColorPoint class:" << endl;
        colorPoint1.print();
        cout << "Coordinates: ";
        colorPoint1.getCoordinates();
        colorPoint1.setColor("blue");
        colorPoint1.setCoordinates(3.0, 4.0);
        cout << "New coordinates and color: ";
        colorPoint1.print();
        break;
    }
    case 2: {

        Computer computer(3000, "Dell", 1200.0);
        computer.print();

        // Тестування класу Desktop
        cout << "\nTesting Desktop class:" << endl;
        Desktop desktop(4000, "HP", 1500.0, 24.0);
        desktop.print();
        break;
    }
    case 3: {
        // Введення даних для об'єкта класу Person
        Person person1;
        cout << "Enter person details:" << endl;
        cin >> person1;
        cout << "Person details: " << person1 << endl;

        // Введення даних для об'єкта класу Employee
        Employee employee1;
        cout << "Enter employee details:" << endl;
        cin >> employee1;
        cout << "Employee details: " << employee1 << endl;
    break;
    }
    }

    return 0;
}
