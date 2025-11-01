#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <functional>  // For std::function

using namespace std;

// ============ Shape Interface ============
class Shape {
public:
    virtual void draw() const = 0;
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

// ============ Concrete Shape Classes ============
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() const override { cout << "Drawing Circle with radius: " << radius << endl; }
    double getArea() const override { return 3.14159 * radius * radius; }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    void draw() const override { cout << "Drawing Square with side: " << side << endl; }
    double getArea() const override { return side * side; }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void draw() const override {
        cout << "Drawing Rectangle with width: " << width << " and height: " << height << endl;
    }
    double getArea() const override { return width * height; }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    void draw() const override {
        cout << "Drawing Triangle with base: " << base << " and height: " << height << endl;
    }
    double getArea() const override { return 0.5 * base * height; }
};

// ============ Simple Shape Factory ============
class ShapeFactory {
private:
    map<string, function<Shape*()>> creators;  // Key: type, Value: creator lambda

public:
    ShapeFactory() {
        // Register shapes here (simple, no auto-magic)
        creators["circle"] = []() {
            double r; cout << "Enter radius: "; cin >> r; return new Circle(r);
        };
        creators["square"] = []() {
            double s; cout << "Enter side: "; cin >> s; return new Square(s);
        };
        creators["rectangle"] = []() {
            double w, h; cout << "Enter width: "; cin >> w; cout << "Enter height: "; cin >> h;
            return new Rectangle(w, h);
        };
        creators["triangle"] = []() {
            double b, h; cout << "Enter base: "; cin >> b; cout << "Enter height: "; cin >> h;
            return new Triangle(b, h);
        };
    }

    Shape* createShape(const string& type) {
        auto it = creators.find(type);
        if (it != creators.end()) {
            return it->second();  // Call creator
        }
        cout << "Error: Unknown shape '" << type << "'!" << endl;
        return nullptr;
    }

    void listShapes() const {
        cout << "Available: circle, square, rectangle, triangle" << endl;
    }
};

// ============ Simple Client ============
int main() {
    ShapeFactory factory;
    vector<Shape*> shapes;

    cout << "=== Simple Shape App ===\n";
    factory.listShapes();

    // Create a few shapes interactively (simple loop)
    for (int i = 0; i < 2; ++i) {  // Limit to 2 for demo
        string type;
        cout << "Enter shape type: ";
        cin >> type;
        Shape* shape = factory.createShape(type);
        if (shape) {
            shapes.push_back(shape);
        }
    }

    // Draw all
    cout << "\n=== Drawing All ===\n";
    for (Shape* shape : shapes) {
        shape->draw();
        cout << "Area: " << shape->getArea() << endl << "---" << endl;
        delete shape;  // Clean up
    }

    cout << "Done!" << endl;
    return 0;
}