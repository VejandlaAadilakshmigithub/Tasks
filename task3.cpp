#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

// Enumeration for event types
enum EventType {
    Tap,
    Swipe
};

// Event class to represent user interaction
class Event {
public:
    EventType eventType;
    int x, y; // Coordinates of the touch
    time_t timestamp;

    Event(EventType type, int xCoord, int yCoord)
        : eventType(type), x(xCoord), y(yCoord) {
        timestamp = time(0); // Capture the current time
    }
};

// Function to process a Tap event
void handleTap(const Event& event) {
    cout << "Tap event at position: (" << event.x << ", " << event.y << ") at timestamp " << event.timestamp << endl;
}

// Function to process a Swipe event
void handleSwipe(const Event& event) {
    // For swipe, let's simulate a direction (left, right, up, down)
    string swipeDirection = "Unknown";
    if (event.x > 0 && event.y > 0) {
        if (event.x > event.y)
            swipeDirection = "Right";
        else
            swipeDirection = "Down";
    }
    else if (event.x < 0 && event.y < 0) {
        if (event.x < event.y)
            swipeDirection = "Left";
        else
            swipeDirection = "Up";
    }
    
    cout << "Swipe event detected. Direction: " << swipeDirection 
         << " at position: (" << event.x << ", " << event.y << ") at timestamp " 
         << event.timestamp << endl;
}

// Function to simulate the event generation and processing
void simulateEventHandling() {
    // Event queue
    queue<Event> eventQueue;
    
    // Randomly generate events and push them into the queue
    srand(time(0));
    for (int i = 0; i < 5; ++i) {
        EventType eventType = (rand() % 2 == 0) ? Tap : Swipe; // Randomly choose event type
        int x = rand() % 100; // Random x coordinate
        int y = rand() % 100; // Random y coordinate
        
        eventQueue.push(Event(eventType, x, y));
    }

    // Process the events from the queue
    while (!eventQueue.empty()) {
        Event event = eventQueue.front();
        eventQueue.pop();
        
        if (event.eventType == Tap) {
            handleTap(event);
        }
        else if (event.eventType == Swipe) {
            handleSwipe(event);
        }
    }
}

int main() {
    // Simulate event handling system
    simulateEventHandling();

    return 0;
}
