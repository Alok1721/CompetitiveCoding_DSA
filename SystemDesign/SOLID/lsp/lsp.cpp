class Shape{
public:
  virtual double area() = 0;
    virtual ~Shape(){};
};

class Rectangle : public Shape {
private:
  double width;
  double height;
public:
    Rectangle(double width, double height):width(width),height(height){}
    double area() override {
        return width * height;
    }
};
class Circle : public Shape {
private:
  double radius;
public:
    Circle(double radius):radius(radius){}
    double area() override {
        return 3.14 * radius * radius;
    }
};
int main()
{
    Shape* rect = new Rectangle(10, 5);
    Shape* circle = new Circle(7);

    std::cout << "Rectangle Area: " << rect->area() << std::endl;
    std::cout << "Circle Area: " << circle->area() << std::endl;

    delete rect;
    delete circle;

    return 0;
}