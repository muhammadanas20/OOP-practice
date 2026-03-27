// Design a Smart Device Ecosystem. All smart devices share a common base, but each device type has unique behaviour.

// The abstract base class SmartDevice enforces that every device can turnOn(), turnOff(), and displayStatus() — all pure virtual. Two derived types: SmartLight (has brightness level 0–100 and colour temperature) and SmartSpeaker (has volume 0–100 and a currently playing track name).

// You must demonstrate runtime polymorphism via a vector/array of base class pointers, implement a move constructor in SmartSpeaker, and overload operator<< for both derived types.
// Abstract Base: SmartDevice
// Attributes: const int deviceID (auto-incremented), const string deviceName, bool isOn (default false).
// Static total device count.
// Pure virtual: turnOn(), turnOff(), displayStatus().
// Non-virtual method getID() — returns deviceID.
// Virtual destructor with a comment explaining why it is mandatory.
// Derived: SmartLight
// Attributes: int brightness (0–100), string colourTemp (e.g., "Warm", "Cool").
// turnOn(): sets isOn = true, prints "[LIGHT] {name} turned ON at {brightness}% brightness."
// turnOff(): sets isOn = false, prints turn-off message.
// displayStatus(): shows all attributes.
// Friend operator<< for single-line formatted output.
// Derived: SmartSpeaker
// Attributes: int volume, string currentTrack.
// turnOn(), turnOff(), displayStatus() with appropriate messages.
// Friend operator<< for formatted output.
// Polymorphism Demo
// Create an array of SmartDevice* holding a mix of SmartLight and SmartSpeaker objects.
// Loop through: call turnOn() then displayStatus() on each — show dynamic dispatch working.
// Delete all via base pointers — confirm virtual destructor prevents leaks.
#include <iostream>
#include <string>

using namespace std;

class SmartDevice {
private:
    const int deviceID;

protected:
    static int nextID;
    static int totalDevices;
    const string deviceName;
    bool isOn;

public:
    SmartDevice(const string& name) : deviceID(nextID++), deviceName(name), isOn(false) {
        ++totalDevices;
    }

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void displayStatus() const = 0;

    int getID() const {
        return deviceID;
    }

    static int getTotalDevices() {
        return totalDevices;
    }

    // Mandatory so deleting derived objects via SmartDevice* calls derived destructors correctly.
    virtual ~SmartDevice() {
        --totalDevices;
    }
};

class SmartLight : public SmartDevice {
private:
    int brightness;
    string colourTemp;

public:
    SmartLight(const string& name, int brightness, const string& colourTemp)
        : SmartDevice(name), brightness(brightness), colourTemp(colourTemp) {
        if (this->brightness < 0) {
            this->brightness = 0;
        } else if (this->brightness > 100) {
            this->brightness = 100;
        }
    }

    void turnOn() override {
        isOn = true;
        cout << "[LIGHT] " << deviceName << " turned ON at " << brightness << "% brightness." << endl;
    }

    void turnOff() override {
        isOn = false;
        cout << "[LIGHT] " << deviceName << " turned OFF." << endl;
    }

    void displayStatus() const override {
        cout << "SmartLight Status -> ID: " << getID()
             << ", Name: " << deviceName
             << ", Power: " << (isOn ? "ON" : "OFF")
             << ", Brightness: " << brightness << "%"
             << ", Colour Temp: " << colourTemp << endl;
    }

    friend ostream& operator<<(ostream& out, const SmartLight& light) {
        out << "SmartLight[ID=" << light.getID()
            << ", Name=" << light.deviceName
            << ", Power=" << (light.isOn ? "ON" : "OFF")
            << ", Brightness=" << light.brightness << "%"
            << ", ColourTemp=" << light.colourTemp << "]";
        return out;
    }
};

class SmartSpeaker : public SmartDevice {
private:
    int volume;
    string currentTrack;

public:
    SmartSpeaker(const string& name, int volume, const string& currentTrack)
        : SmartDevice(name), volume(volume), currentTrack(currentTrack) {
        if (this->volume < 0) {
            this->volume = 0;
        } else if (this->volume > 100) {
            this->volume = 100;
        }
    }

    void turnOn() override {
        isOn = true;
        cout << "[SPEAKER] " << deviceName << " turned ON at volume " << volume << "." << endl;
    }

    void turnOff() override {
        isOn = false;
        cout << "[SPEAKER] " << deviceName << " turned OFF." << endl;
    }

    void displayStatus() const override {
        cout << "SmartSpeaker Status -> ID: " << getID()
             << ", Name: " << deviceName
             << ", Power: " << (isOn ? "ON" : "OFF")
             << ", Volume: " << volume
             << ", Track: " << currentTrack << endl;
    }

    friend ostream& operator<<(ostream& out, const SmartSpeaker& speaker) {
        out << "SmartSpeaker[ID=" << speaker.getID()
            << ", Name=" << speaker.deviceName
            << ", Power=" << (speaker.isOn ? "ON" : "OFF")
            << ", Volume=" << speaker.volume
            << ", Track=" << speaker.currentTrack << "]";
        return out;
    }
};

int SmartDevice::nextID = 1;
int SmartDevice::totalDevices = 0;

int main() {
    const int deviceCount = 4;
    SmartDevice* devices[deviceCount] = {
        new SmartLight("Living Room Light", 75, "Warm"),
        new SmartSpeaker("Kitchen Speaker", 60, "Focus Playlist"),
        new SmartLight("Bedroom Light", 45, "Cool"),
        new SmartSpeaker("Office Speaker", 35, "Lo-fi Mix")
    };

    cout << "--- Runtime Polymorphism Demo ---" << endl;
    for (int i = 0; i < deviceCount; ++i) {
        devices[i]->turnOn();
        devices[i]->displayStatus();
    }

    cout << "\n--- Deleting via Base Pointers ---" << endl;
    for (int i = 0; i < deviceCount; ++i) {
        delete devices[i];
    }

    cout << "Remaining devices count: " << SmartDevice::getTotalDevices() << endl;
    return 0;
}