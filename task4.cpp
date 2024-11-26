
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Theme {
private:
    string backgroundColor;
    string fontColor;
    int fontSize;
    string iconStyle;

public:
    // Constructor with parameters
    Theme(string bgColor, string fColor, int fSize, string icon)
        : backgroundColor(bgColor), fontColor(fColor), fontSize(fSize), iconStyle(icon) {}

    // Default constructor
    Theme() 
        : backgroundColor("White"), fontColor("Black"), fontSize(12), iconStyle("Default") {}

    // Method to apply the theme
    void applyTheme() {
        cout << "Applying Theme:" << endl;
        cout << "Background Color: " << backgroundColor << endl;
        cout << "Font Color: " << fontColor << endl;
        cout << "Font Size: " << fontSize << endl;
        cout << "Icon Style: " << iconStyle << endl;
    }

    // Method to display theme details
    void displayTheme() const {
        cout << "Theme Preview: " << endl;
        cout << "Background Color: " << backgroundColor << ", "
             << "Font Color: " << fontColor << ", "
             << "Font Size: " << fontSize << ", "
             << "Icon Style: " << iconStyle << endl;
    }
};

int main() {
    // Create a map to store themes
    map<string, Theme> themes;

    // Add themes to the map
    themes["Classic"] = Theme("White", "Black", 12, "ClassicIcon");
    themes["Sport"] = Theme("Red", "White", 16, "SportIcon");
    themes["Eco"] = Theme("Green", "DarkGray", 14, "EcoIcon");

    // User selects a theme from the list
    cout << "Select a theme (Classic, Sport, Eco): ";
    string selectedTheme;
    cin >> selectedTheme;

    // Find the selected theme in the map
    auto it = themes.find(selectedTheme);
    if (it != themes.end()) {
        cout << "\nYou selected the " << selectedTheme << " theme." << endl;
        it->second.displayTheme();
    } else {
        cout << "Theme not found!" << endl;
    }

    return 0;
}
