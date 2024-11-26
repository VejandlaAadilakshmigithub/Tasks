
#include <iostream>
#include <thread>      // Include this for std::thread and std::this_thread
#include <chrono>      // Include this for std::chrono
#include <random>
#include <iomanip> // for std::setw

using namespace std; // This allows us to use standard library types like thread, chrono, etc.

class VehicleData {
public:
    int speed;               // Speed in km/h
    int fuelLevel;           // Fuel level in percentage (0-100)
    int engineTemperature;   // Engine temperature in Celsius

    // Constructor to initialize the data
    VehicleData() : speed(0), fuelLevel(100), engineTemperature(90) {}

    // Function to simulate updates (speed, fuel, temperature)
    void updateData() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> speedDist(0, 200);
        uniform_int_distribution<> fuelDist(0, 100);
        uniform_int_distribution<> tempDist(70, 120);

        // Randomly update the vehicle parameters
        speed = speedDist(gen);
        fuelLevel = fuelDist(gen);
        engineTemperature = tempDist(gen);
    }
};

class Display {
private:
    VehicleData& vehicleData;

public:
    // Constructor to link with VehicleData object
    Display(VehicleData& data) : vehicleData(data) {}

    // Function to display current data
    void showData() {
        // Clear screen (works in Windows, change to "clear" for Linux/Mac)
        system("CLS");

        // Display the parameters in a formatted manner
        cout << "=== Vehicle Instrument Cluster ===" << endl;
        cout << "Speed: " << setw(3) << vehicleData.speed << " km/h" << endl;
        cout << "Fuel Level: " << setw(3) << vehicleData.fuelLevel << "%" << endl;
        cout << "Engine Temp: " << setw(3) << vehicleData.engineTemperature << "°C" << endl;

        // Check for warning conditions and display alerts
        if (vehicleData.engineTemperature > 100) {
            cout << "\n** WARNING: High Engine Temperature! **" << endl;
        }
        if (vehicleData.fuelLevel < 10) {
            cout << "\n** WARNING: Low Fuel! **" << endl;
        }

        // Add a pause to simulate real-time updates
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Correct use of std::this_thread and std::chrono
    }
};

// Function to simulate real-time updates using threads
void updateVehicleData(VehicleData& vehicleData) {
    while (true) {
        vehicleData.updateData(); // Update vehicle data randomly
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Correct use of std::this_thread and std::chrono
    }
}

int main() {
    // Create a VehicleData object and a Display object
    VehicleData vehicleData;
    Display display(vehicleData);

    // Create a thread to update the vehicle data in real-time
    std::thread dataUpdater(updateVehicleData, std::ref(vehicleData));  // Correctly use std::thread and std::ref

    // Display the vehicle data continuously on the console
    while (true) {
        display.showData(); // Display current vehicle data
    }

    // Join the thread (although the program runs infinitely, this line is for good practice)
    dataUpdater.join();

    return 0;
}
