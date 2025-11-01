#include<bits/stdc++.h>
using namespace std;
class Product
{
    public:
    string name;
    int price;
    Product(string name,int price)
    {
        this->name=name;
        this->price=price;
    }
};

//*single responsiblity for price and product calculation
class ShoppingCart
{
    public:
    vector<Product*> products;//refernce of products
    void addProduct(Product *product)
    {
        products.push_back(product);
    }
    int getTotalPrice()
    {
        int total=0;
        for(auto product:products)
        {
            total+=product->price;
        }
        return total;
    }
};

class ShoppingCartPrinter
{
    ShoppingCart *cart;
    public:
    ShoppingCartPrinter(ShoppingCart *cart)
    {
        this->cart=cart;
    }
    void printInvoice()
    {
        cout<<"Invoice:"<<endl;
        cout<<"Total Price: "<<cart->getTotalPrice()<<endl;
    }
};

class ShoppingCartStorage
{
    ShoppingCart *cart;
    public:
    ShoppingCartStorage(ShoppingCart *cart)
    {
        this->cart=cart;
    }
    void saveToDatabase()
    {
        cout<<"Saving to database..."<<endl;
    }
};


int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Mobile",300));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage *db=new ShoppingCartStorage(cart);
    db->saveToDatabase();
    return 0;

}