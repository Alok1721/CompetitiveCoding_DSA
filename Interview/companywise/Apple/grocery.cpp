#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;

enum Options {
    INVALID = 0,
    ADD_ITEM = 1,
    REMOVE_ITEM = 2,
    DISPLAY_LIST = 3,
    SAVE_LIST = 4,
    LOAD_LIST = 5,
    EXIT = 6
};

class Grocery {
private:
    string name;
    int quantity;
    double price;

public:
    Grocery(const string& n, int q, double p) : name(n), quantity(q), price(p) {}
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    string toFileString() const {
        return name + "," + to_string(quantity) + "," + to_string(price);
    }
};

class GroceryManager {
private:
    vector<Grocery> groceryList;
    const string filename = "grocery_list.txt";

    Grocery parseLine(const string& line) {
        string name, qty_str, price_str;
        int pos = 0, next;
        next = line.find(',', pos);
        name = line.substr(pos, next - pos);
        pos = next + 1;
        next = line.find(',', pos);
        qty_str = line.substr(pos, next - pos);
        price_str = line.substr(next + 1);
        int quantity = stoi(qty_str);
        double price = stod(price_str);
        return Grocery(name, quantity, price);
    }

public:
    void add_item(const string& name, int quantity, double price) {
        groceryList.emplace_back(name, quantity, price);
        cout << "Added: " << name << " (" << quantity << ", $" << fixed << setprecision(2) << price << ")\n";
    }

    void remove_item(const string& name) {
        auto it = find_if(groceryList.begin(), groceryList.end(),
                          [&name](const Grocery& g) { return g.getName() == name; });
        if (it != groceryList.end()) {
            groceryList.erase(it);
            cout << "Removed: " << name << "\n";
        } else {
            cout << "Item not found: " << name << "\n";
        }
    }

    void displayList() const {
        if (groceryList.empty()) {
            cout << "List is empty.\n";
            return;
        }
        cout << "\nGrocery List:\n";
        cout << left << setw(20) << "Name" << setw(10) << "Quantity" << setw(10) << "Price" << "\n";
        for (const auto& item : groceryList) {
            cout << setw(20) << item.getName() << setw(10) << item.getQuantity()
                 << setw(10) << fixed << setprecision(2) << item.getPrice() << "\n";
        }
    }

    void saveToFile() const {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error: Could not save file.\n";
            return;
        }
        for (const auto& item : groceryList) {
            outFile << item.toFileString() << "\n";
        }
        outFile.close();
        cout << "List saved to " << filename << "\n";
    }

    void loadFromFile() {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error: Could not load file.\n";
            return;
        }
        groceryList.clear();
        string line;
        while (getline(inFile, line)) {
            if (!line.empty()) {
                groceryList.push_back(parseLine(line));
            }
        }
        inFile.close();
        cout << "List loaded from " << filename << "\n";
    }

    void exit() const {
        cout << "Thank you for using the grocery manager.\n";
    }
};

int main() {
    GroceryManager groceryManager;
    while (true) {
        cout << "\nGrocery List App\n1. Add item\n2. Remove item\n3. Display list\n4. Save list\n5. Load list\n6. Exit\n";
        cout << "Enter choice (1-6): ";
        int choice;
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 6) {
            cout << "Invalid option. Please enter 1-6.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        Options option = static_cast<Options>(choice);
        cin.ignore(); // Clear newline

        switch (option) {
            case ADD_ITEM: {
                string name;
                int quantity;
                double price;
                cout << "Enter the name of the item: ";
                getline(cin, name);
                cout << "Enter the quantity of the item: ";
                cin >> quantity;
                if (cin.fail() || quantity <= 0) {
                    cout << "Invalid quantity. Must be positive.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cout << "Enter the price of the item: ";
                cin >> price;
                if (cin.fail() || price < 0) {
                    cout << "Invalid price. Must be non-negative.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                groceryManager.add_item(name, quantity, price);
                break;
            }
            case REMOVE_ITEM: {
                string name;
                cout << "Enter the name of the item: ";
                getline(cin, name);
                groceryManager.remove_item(name);
                break;
            }
            case DISPLAY_LIST:
                groceryManager.displayList();
                break;
            case SAVE_LIST:
                groceryManager.saveToFile();
                break;
            case LOAD_LIST:
                groceryManager.loadFromFile();
                break;
            case EXIT:
                groceryManager.exit();
                return 0;
        }
    }
}
