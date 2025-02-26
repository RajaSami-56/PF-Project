This is a C++ program of a Stadium Seating Management System
It pweforms following tasks:
Book a seat in different seating categories.
View seating arrangements to see which seats are occupied.
Display details of a specific seat.
Exit the program.

![Image](https://github.com/user-attachments/assets/4ad14093-f46e-4e29-b01a-b4887b069aaf)
Defines three seating categories: VIP, Regular, and Economy and Specifies the number of seats in each category.


![Image](https://github.com/user-attachments/assets/4ad14093-f46e-4e29-b01a-b4887b069aaf)
Defines a structure TicketHolder to store ticket holder details:
Name (string)
Age (integer)
Unique ID (UID) (string)
Whether they are with family ( 1 for Yes and 0 for No)

![Image](https://github.com/user-attachments/assets/4921ada4-a57c-405c-b035-93fd00a0b583)
Displays a menu for users to choose an action.
Uses a do-while loop to keep running until the user chooses Exit (option 4).
Calls different functions based on user choice


![Image](https://github.com/user-attachments/assets/81511397-1223-4f00-b599-09d5983a4e98)
It is a Booking a Seat (function)
Asks the user to choose a seat category
Initializes a pointer seats and totalSeats to store the chosen seat category.


![Image](https://github.com/user-attachments/assets/bc5f65ff-4428-4ead-9b57-ed50d3f3d34b)
Assigns seats to the appropriate seat array (VIP, Regular, or Economy).
If an invalid category is selected, it prints an error message and exits


![Image](https://github.com/user-attachments/assets/75fefa60-9b59-48b5-892f-19e1e7dca690)
Finds the first available empty seat.
If no seats are available, it displays an error message.
Collects the ticket holder's details.
Stores the user data in the selected seat array.


![Image](https://github.com/user-attachments/assets/764b7155-9905-43e0-9ecf-3d976f065734)
Display Seating Arrangements (displaySeatingArrangements function)
Displays seating availability.
Iterates through the VIP seat array:
Displays [Empty] if the seat is available.
Displays [Booked] if the seat is occupied.
Adds a new line after every 5 seats for better formatting.
Similar logic is used for Regular and Economy seats.



