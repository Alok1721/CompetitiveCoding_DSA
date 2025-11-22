class InputDevice {
public:
    virtual ~InputDevice() = default;
    virtual void read() = 0;
};

class Computer {
    std::vector<std::unique_ptr<InputDevice>> devices;  // depends on abstraction
public:
    void addDevice(std::unique_ptr<InputDevice> dev) { devices.push_back(std::move(dev)); }
};