#include<bits/stdc++.h>
using namespace std;


//interface
class Drawable{
    public:
        virtual void draw()=0;
        virtual ~Drawable(){};
};


class Circle:public Drawable{
    public:
        void draw() override{
            cout<<"code to draw circle"<<endl;
        }
};

class Square:public Drawable{
    public:
        void draw() override{
            cout<<"code to draw square"<<endl;
        }
};
class Triangle:public Drawable{
    public:
        void draw() override{
            cout<<"code to draw triangle"<<endl;
        }
};

class Renderer{
    public:
        void render(Drawable &shape){
            shape.draw();
        }
};

int main()
{
    Renderer renderer;
    Circle circle;
    Square square;
    Triangle triangle;

    renderer.render(circle);
    renderer.render(square);
    renderer.render(triangle);

    return 0;
}

/* 
class Shape {
public:
  virtual double area() = 0;
};

class Rectangle : public Shape {
private:
  double width;
  double height;
public:
  Rectangle(double width, double height);
  double area() override;
};

class Circle : public Shape {
private:
  double radius;
public:
  Circle(double radius);
  double area() override;
};

class Triangle : public Shape {
private:
  double base;
  double height;
public:
  Triangle(double base, double height);
  double area() override;
};

+ suppose that we want to add a new shape, such as a Square
-> we can extend the Shape class hierarchy by creating a new class that inherits from the Shape class and implements the area() method.
-> we do not need to modify any existing code in the Shape class or its derived classes.

class Square : public Shape {
private:
  double side;
public:
  Square(double side);
  double area() override;
};

*/