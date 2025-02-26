#include <iostream>
#include <string>
using namespace std;

// Constants for seat types and total seats
const int VIP_SEATS = 10;
const int REGULAR_SEATS = 15;
const int ECONOMY_SEATS = 20;

// Structure to hold ticket holder details
struct TicketHolder 
{
    string name;
    int age;
    string uid;
    bool isFamily;
};

// Arrays to represent seating arrangements
TicketHolder vipSeats[VIP_SEATS];
TicketHolder regularSeats[REGULAR_SEATS];
TicketHolder economySeats[ECONOMY_SEATS];

// Functions
void displaySeatingArrangements();
void bookSeat();
void displaySeatDetails();

int main() 
{
    int choice;
    do {
        cout << "\n--- Stadium Seating Management ---\n";
        cout << "1. Book a Seat\n";
        cout << "2. Display Seating Arrangements\n";
        cout << "3. Display Seat Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                bookSeat();
                break;
            case 2:
                displaySeatingArrangements();
                break;
            case 3:
                displaySeatDetails();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void bookSeat() 
{
    int type;
    cout << "\nSelect Seat Type:\n";
    cout << "1. VIP\n2. Regular\n3. Economy\n";
    cout << "Enter your choice: ";
    cin >> type;

    int seatIndex = -1;
    TicketHolder *seats;
    int totalSeats;

    switch (type)
    {
        case 1:
            seats = vipSeats;
            totalSeats = VIP_SEATS;
            break;
        case 2:
            seats = regularSeats;
            totalSeats = REGULAR_SEATS;
            break;
        case 3:
            seats = economySeats;
            totalSeats = ECONOMY_SEATS;
            break;
        default:
            cout << "Invalid seat type!\n";
            return;
    }

    for (int i = 0; i < totalSeats; i++) 
    {
        if (seats[i].name.empty()) 
        {
            seatIndex = i;
            break;
        }
    }

    if (seatIndex == -1) 
    {
        cout << "No available seats in the selected category.\n";
        return;
    }

    TicketHolder holder;
    cout << "Enter ticket holder name: ";
    cin.ignore();
    getline(cin, holder.name);
    cout << "Enter age: ";
    cin >> holder.age;
    cout << "Enter UID: ";
    cin >> holder.uid;
    cout << "Is the ticket holder coming with family? (1 for Yes, 0 for No): ";
    cin >> holder.isFamily;

    seats[seatIndex] = holder;
    cout << "Seat booked successfully at index " << seatIndex + 1 << "!\n";
}

void displaySeatingArrangements() 
{
    cout << "\n--- Seating Arrangements ---\n";

    cout << "VIP Seats:\n";
    for (int i = 0; i < VIP_SEATS; i++) 
    {
        cout << (vipSeats[i].name.empty() ? "[Empty]" : "[Booked]") << " ";
        if ((i + 1) % 5 == 0) cout << "\n";
    }

    cout << "\nRegular Seats:\n";
    for (int i = 0; i < REGULAR_SEATS; i++) 
    {
        cout << (regularSeats[i].name.empty() ? "[Empty]" : "[Booked]") << " ";
       if ((i + 1) % 5 == 0) cout << "\n";
    }

    cout << "\nEconomy Seats:\n";
    for (int i = 0; i < ECONOMY_SEATS; i++) 
    {
        cout << (economySeats[i].name.empty() ? "[Empty]" : "[Booked]") << " ";
        if ((i + 1) % 5 == 0) cout << "\n";
    }
    cout << "\n";
}

void displaySeatDetails() 
{
    int type, index;
    cout << "\nSelect Seat Type:\n";
    cout << "1. VIP\n2. Regular\n3. Economy\n";
    cout << "Enter your choice: ";
    cin >> type;

    cout << "Enter seat index (1-based): ";
    cin >> index;
    index--; // Convert to 0-based index

    TicketHolder *seats;
    int totalSeats;

    switch (type) 
    {
        case 1:
            seats = vipSeats;
            totalSeats = VIP_SEATS;
            break;
        case 2:
            seats = regularSeats;
            totalSeats = REGULAR_SEATS;
            break;
        case 3:
            seats = economySeats;
            totalSeats = ECONOMY_SEATS;
            break;
        default:
            cout << "Invalid seat type!\n";
            return;
    }

    if (index < 0 || index >= totalSeats) 
    {
        cout << "Invalid seat index!\n";
        return;
    }

    if (seats[index].name.empty()) 
    {
        cout << "Seat is empty.\n";
    } 
    else 
    {
        cout << "\n--- Seat Details ---\n";
        cout << "Name: " << seats[index].name << "\n";
        cout << "Age: " << seats[index].age << "\n";
        cout << "UID: " << seats[index].uid << "\n";
        cout << "Family: " << (seats[index].isFamily ? "Yes" : "No") << "\n";
    }
}
