#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------------- Interface Segregation ----------------
class IVehicle {
public:
    virtual string getType() const = 0;
    virtual int getFee() const = 0;
    virtual string getOwner() const = 0;
    virtual ~IVehicle() {}
};

// ---------------- Concrete Vehicles ----------------
class Car : public IVehicle {
    string owner;
    int fee;
public:
    Car(string o, int f) : owner(o), fee(f) {}
    string getType() const override { return "Car"; }
    int getFee() const override { return fee; }
    string getOwner() const override { return owner; }
};

class Truck : public IVehicle {
    string owner;
    int fee;
public:
    Truck(string o, int f) : owner(o), fee(f) {}
    string getType() const override { return "Truck"; }
    int getFee() const override { return fee; }
    string getOwner() const override { return owner; }
};

// More vehicles can be added easily: Bike, Bus, Scooter...

// ---------------- Decorator Pattern ----------------
class VehicleDecorator : public IVehicle {
protected:
    IVehicle* vehicle;
public:
    VehicleDecorator(IVehicle* v) : vehicle(v) {}
    virtual string getType() const override { return vehicle->getType(); }
    virtual int getFee() const override { return vehicle->getFee(); }
    virtual string getOwner() const override { return vehicle->getOwner(); }
};

class GPSDecorator : public VehicleDecorator {
public:
    GPSDecorator(IVehicle* v) : VehicleDecorator(v) {}
    string getType() const override { return vehicle->getType() + " + GPS"; }
    int getFee() const override { return vehicle->getFee() + 50; } // extra fee for GPS
};

class InsuranceDecorator : public VehicleDecorator {
public:
    InsuranceDecorator(IVehicle* v) : VehicleDecorator(v) {}
    string getType() const override { return vehicle->getType() + " + Insurance"; }
    int getFee() const override { return vehicle->getFee() + 100; } // extra fee for insurance
};

// ---------------- Observer Pattern ----------------
class IObserver {
public:
    virtual void update(const string& msg) = 0;
    virtual ~IObserver() {}
};

class Member : public IObserver {
    string name;
public:
    Member(string n) : name(n) {}
    void update(const string& msg) override {
        cout << "Notification for " << name << ": " << msg << endl;
    }
    string getName() const { return name; }
};

class NotificationService {
    vector<IObserver*> observers;
public:
    void addObserver(IObserver* obs) { observers.push_back(obs); }
    void notifyAll(const string& msg) {
        for (auto obs : observers) {
            obs->update(msg);
        }
    }
};

// ---------------- Fee Calculator (SRP) ----------------
class FeeCalculator {
public:
    int calculateFee(const IVehicle& v) {
        return v.getFee();
    }
};

// ---------------- Main ----------------
int main() {
    // Create vehicles
    Car car1("Alice", 500);
    Truck truck1("Bob", 1000);

    // Apply decorators
    GPSDecorator carWithGPS(&car1);
    InsuranceDecorator truckWithInsurance(&truck1);

    // Members (observers)
    Member m1("Charlie");
    Member m2("Daisy");

    // Notification service
    NotificationService notifier;
    notifier.addObserver(&m1);
    notifier.addObserver(&m2);

    // Fee calculation
    FeeCalculator calc;
    cout << carWithGPS.getOwner() << " owns a " << carWithGPS.getType()
         << " with fee: " << calc.calculateFee(carWithGPS) << endl;

    cout << truckWithInsurance.getOwner() << " owns a " << truckWithInsurance.getType()
         << " with fee: " << calc.calculateFee(truckWithInsurance) << endl;

    // Notify members about fee changes
    notifier.notifyAll("Parking fee updated by +20%!");

    return 0;
}
