#include<bits/stdc++.h>
using namespace std;
class Product{    
public:
    string name;
    int price;
    Product(string name,int price){
        this->name=name;
        this->price=price;
    }
};

class ShoppingCart{
public:
    vector<Product*>products;
    void addProduct(Product*product){
        products.push_back(product);
    }
    int getTotal(){
        int total=0;
        for(Product*product:products){
            total+=product->price;
        }
        return total;
    }
};

class ShoppingCartPrinter{
    private:
    ShoppingCart*cart;
    public:
    ShoppingCartPrinter(ShoppingCart*cart){
        this->cart=cart;
    }
    void printInvoie(){
        cout<<"Shopping Cart Invoice"<<endl;
        for(Product*product:cart->products){
            cout<<product->name<<"-"<<product->price<<endl;
        }
        cout<<"Total: "<<cart->getTotal()<<endl;
    }
};

class Persistence{
    protected:
    ShoppingCart*cart;
    public:
    Persistence(ShoppingCart*cart){
        this->cart=cart;
    }
    virtual void save()=0;
};

class MongoPersistence:public Persistence{
    public:
    MongoPersistence(ShoppingCart*cart):Persistence(cart){
    }
    void save(){
        cout<<"Saving cart to MongoDB"<<endl;
    }
};

class FilePersistence:public Persistence{
    public:
    FilePersistence(ShoppingCart*cart):Persistence(cart){
    }
    void save(){
        cout<<"Saving cart to file"<<endl;
    }
};


int main(){
    ShoppingCart*cart=new ShoppingCart();
    cart->addProduct(new Product("Product1",100));
    cart->addProduct(new Product("Prod2",300));

    ShoppingCartPrinter*printer=new ShoppingCartPrinter(cart);
    printer->printInvoie();

    // Persistence*db=new Persistence(cart);
    Persistence*mongo=new MongoPersistence(cart);
    Persistence*file=new FilePersistence(cart);

    mongo->save();
    file->save();
    
    return 0;
}
