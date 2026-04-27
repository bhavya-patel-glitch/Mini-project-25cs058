🚆 Railway Reservation System (C++)

This project is a console-based Railway Reservation System implemented in C++ using Object-Oriented Programming concepts and file handling. It simulates basic railway booking operations for both Admin and Passenger roles.

📌 Features
👨‍💼 Admin Module
Add new train details (Train No, Name, Source, Destination, Seats)
View all available trains
Train data is stored persistently in trains.txt
👤 Passenger Module
Book tickets:
By Train Number
By Train Name
Cancel tickets:
By Ticket ID
By Passenger Name
View all bookings
Ticket data is stored in tickets.txt
🧱 OOP Concepts Used
Multiple Inheritance
Admin → inherits from Train and ReservationSystem
PassengerUser → inherits from Passenger and ReservationSystem
Encapsulation
Data members are protected and accessed via member functions
Function Overloading
bookTicket() (by train number / train name)
cancelTicket() (by ID / name)
Polymorphism
Virtual display() functions in base classes
📂 File Handling

trains.txt → stores train records
Format:

TrainNo|TrainName|Source|Destination|Seats

tickets.txt → stores ticket bookings
Format:

TicketID|TrainNo|PassengerName|Age|Gender
⚙️ How It Works
User selects role:
Admin
Passenger
Admin can:
Add new trains
View train list
Passenger can:
Search train (by name)
Book tickets for multiple passengers
Cancel tickets
View bookings
Ticket IDs are auto-generated using a counter.

▶️ How to Run
g++ main.cpp -o railway
./railway

⚠️ Limitations
No authentication system for Admin/Passenger
No seat availability tracking (seats are stored but not updated)
File-based storage (no database)
Basic string matching for cancellation (may remove unintended entries)

🔮 Future Improvements
Add login authentication
Implement seat availability management
Use database instead of text files
Improve search and cancellation accuracy
Add GUI interface

📜 Author
Bhavya Patel (25CS058)
