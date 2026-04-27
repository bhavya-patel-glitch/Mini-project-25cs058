# 🚆 Railway Reservation System (C++)

## 📖 Description
This project is a **console-based Railway Reservation System** developed in C++ using Object-Oriented Programming (OOP) concepts and file handling.

It allows two types of users:
- **Admin** → Manage train records
- **Passenger** → Book, cancel, and view tickets

All data is stored using text files, making the system simple and persistent.

---

## ✨ Features

### 👨‍💼 Admin Module
- Add new train details
- View all trains
- Data stored in `trains.txt`

### 👤 Passenger Module
- Book tickets:
  - By Train Number
  - By Train Name
- Cancel tickets:
  - By Ticket ID
  - By Passenger Name
- View all bookings
- Data stored in `tickets.txt`

---

## 🧠 OOP Concepts Used

- **Multiple Inheritance**
  - `Admin` → inherits from `Train` and `ReservationSystem`
  - `PassengerUser` → inherits from `Passenger` and `ReservationSystem`

- **Encapsulation**
  - Data members are protected

- **Function Overloading**
  - `bookTicket()` → by number / name
  - `cancelTicket()` → by ID / name

- **Polymorphism**
  - Virtual `display()` functions

---

## 📂 File Structure

### `trains.txt`
```
TrainNo|TrainName|Source|Destination|Seats
```

### `tickets.txt`
```
TicketID|TrainNo|PassengerName|Age|Gender
```

---

## ⚙️ Working

1. User selects role:
   - Admin
   - Passenger

2. Admin can:
   - Add trains
   - View train list

3. Passenger can:
   - Search train
   - Book tickets
   - Cancel tickets
   - View bookings

4. Ticket IDs are generated automatically.

---

## ▶️ How to Run

```bash
g++ main.cpp -o railway
./railway
```

---

## ⚠️ Limitations

- No login/authentication system
- No seat availability tracking
- Uses text files instead of database
- Basic string matching for cancellation

---

## 🔮 Future Improvements

- Add login system
- Implement seat management
- Use database (MySQL / SQLite)
- Improve search accuracy
- Add GUI

---

## 👨‍💻 Author

**Bhavya Patel**  
Enrollment No: 25CS058
