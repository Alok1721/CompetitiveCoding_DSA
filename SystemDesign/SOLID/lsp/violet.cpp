class Rectangle{
    public:
        int height;
        int width;
        virtual void setHeight(double height)=0;
        virtual void setWidth(double width)=0;
        virtual double area()=0;
        virtual ~Rectangle(){};
};
class Square:public Rectangle{
    public:
        void setHeight(double height) override{
            this->height=height;
            this->width=height; // maintain square property
        }
        void setWidth(double width) override{
            this->width=width;
            this->height=width; // maintain square property
        }
        double area() override{
            return height*width;
        }
};

//client code that break LSP
void resizeRectangle(Rectangle &rect,double newWidth,double newHeight){
    rect.setWidth(newWidth);
    rect.setHeight(newHeight);
    cout<<"Area: "<<rect.area()<<endl;
}