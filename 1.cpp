//25cs058
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Base class 1
class Train {
protected:
    int trainNo;
    string trainName;
    string source;
    string destination;
    int seats;

public:
    Train(int no=0, string name="default", string src="default", string dest="default", int s=0) {
        trainNo = no;
        trainName = name;
        source = src;
        destination = dest;
        seats = s;
    }

    virtual void display() {
        cout << "\nTrain No: " << trainNo  << "\nName: " << trainName  << "\nRoute: " << source << " to " << destination << "\nSeats: " << seats << endl;
    }
};

// Base class 2
class Passenger {
protected:
    string name;
    int age;
    string gender;

public:
    Passenger(string n="default", int a=0, string g="default") {
        name = n;
        age = a;
        gender = g;
    }

    void setPassenger(string n, int a, string g) {
        name = n;
        age = a;
        gender = g;
    }

    virtual void display() {
        cout << "\nPassenger: " << name  << "\nAge: " << age   << "\nGender: " << gender << endl;
    }
};

// Base class 3
class ReservationSystem {
protected:
    int ticketCounter;

public:
    ReservationSystem() {
        ticketCounter = 1000;
    }

  int getTrainNoByName(string tName) {
    ifstream file("trains.txt");

    int no, seats;
    string name, src, dest;

    while (file >> no) {
        file.ignore();
        getline(file, name, '|');
        getline(file, src, '|');
        getline(file, dest, '|');
        file >> seats;
        file.ignore();

        if (name == tName) {
            return no;
        }
    }

    return -1;
}
};

// Derived class 1(Admin)
class Admin : public ReservationSystem, public Train {
public:
    void addTrain() {
        ofstream file("trains.txt", ios::app);

        cout << "\nEnter Train No: ";
        cin >> trainNo;

        cin.ignore();
        cout << "Enter Train Name: ";
        getline(cin, trainName);

        cout << "Enter Source: ";
        getline(cin, source);

        cout << "Enter Destination: ";
        getline(cin, destination);

        cout << "Enter Seats: ";
        cin >> seats;

        file << trainNo << "|" << trainName << "|" << source
             << "|" << destination << "|" << seats << endl;

        cout << "Train Added!\n";
    }

    void viewTrains() {
        ifstream file("trains.txt");
        string line;

        cout << "\n--- Train List ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
};

// Derived class 2(Passenger)
class PassengerUser : public ReservationSystem, public Passenger {
public:

   // Book tarin by No.
    void bookTicket(int tNo) {
        int count;
        cout << "Enter number of passengers: ";
        cin >> count;

        ofstream file("tickets.txt", ios::app);

        for (int i = 0; i < count; i++) {
            string n, g;
            int a;

            cin.ignore();
            cout << "\nPassenger " << i + 1 << endl;

            cout << "Name: ";
            getline(cin, n);

            cout << "Age: ";
            cin >> a;

            cin.ignore();
            cout << "Gender: ";
            getline(cin, g);

            setPassenger(n, a, g);

            ticketCounter++;

            file << ticketCounter << "|" << tNo << "|"
                 << name << "|" << age << "|" << gender << endl;

            cout << "\n====== TICKET ======\n";
            cout << "ID: " << ticketCounter<< "\nTrain: " << tNo << "\nName: " << name << "\nAge: " << age << "\nGender: " << gender << endl;
            cout << "====================\n";
        }

        cout << "Booking Successful!\n";
    }

    //book train by name
    void bookTicket(string tName) {
        int tNo = getTrainNoByName(tName);

        if (tNo == -1) {
            cout << "Train not found!\n";
            return;
        }

        cout << "Train Found! No: " << tNo << endl;
        bookTicket(tNo);
    }

    // Cancel train by Id
    void cancelTicket(int id) {
        ifstream file("tickets.txt");
        ofstream temp("temp.txt");

        string line;
        bool found = false;

        while (getline(file, line)) {
            int fileID = stoi(line.substr(0, line.find('|')));

            if (fileID == id) {
                found = true;
                cout << "Ticket Cancelled!\n";
                continue;
            }

            temp << line << endl;
        }

        file.close();
        temp.close();

        remove("tickets.txt");
        rename("temp.txt", "tickets.txt");

        if (!found)
            cout << "Ticket Not Found!\n";
    }

    // Cancel by name
    void cancelTicket(string nameToCancel) {
        ifstream file("tickets.txt");
        ofstream temp("temp.txt");

        string line;
        bool found = false;

        while (getline(file, line)) {
            if (line.find(nameToCancel) != string::npos && !found) {
                found = true;
                cout << "Ticket Cancelled for " << nameToCancel << endl;
                continue;
            }

            temp << line << endl;
        }

        file.close();
        temp.close();

        remove("tickets.txt");
        rename("temp.txt", "tickets.txt");

        if (!found)
            cout << "Passenger not found!\n";
    }

    void viewBookings() {
        ifstream file("tickets.txt");
        string line;

        cout << "\n--- Bookings ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
};

// Main
int main() {
    int ro;

    while (true) {
        cout << "\nRAILWAY RESERVATION SYSTEM\n";
        cout << "\n====== LOGIN SYSTEM ======\n";
        cout << "1. Admin\n2. Passenger\n3. Exit\n";
        cout << "Select Role: ";
        cin >> ro;

        if (ro == 1) {
            Admin a;
            int ch;

            do {
                cout << "\n--- ADMIN SECTION ---\n";
                cout << "1. Add Train\n2. View Trains\n3. Logout\n";
                cout << "Choice: ";
                cin >> ch;

                if (ch == 1) a.addTrain();
                else if (ch == 2) a.viewTrains();

            } while (ch != 3);
        }

        else if (ro == 2) {
            PassengerUser p;
            int ch;

            do {
                cout << "\n--- PASSENGER SECTION ---\n";
                cout << "1. Book Ticket\n2. Cancel Ticket\n3. View Bookings\n4. Logout\n";
                cout << "Choice: ";
                cin >> ch;

                if (ch == 1) {
                    int opt;
                    cout << "1. By Train No\n2. By Train Name\nChoice: ";
                    cin >> opt;

                    if (opt == 1) {
                        int t;
                        cout << "Enter Train No: ";
                        cin >> t;
                        p.bookTicket(t);
                    } else {
                        string name;
                        cin.ignore();
                        cout << "Enter Train Name: ";
                        getline(cin, name);
                        p.bookTicket(name);
                    }
                }

                else if (ch == 2) {
                    int opt;
                    cout << "1. By Ticket ID\n2. By Passenger Name\nChoice: ";
                    cin >> opt;

                    if (opt == 1) {
                        int id;
                        cout << "Enter Ticket ID: ";
                        cin >> id;
                        p.cancelTicket(id);
                    } else {
                        string name;
                        cin.ignore();
                        cout << "Enter Passenger Name: ";
                        getline(cin, name);
                        p.cancelTicket(name);
                    }
                }

                else if (ch == 3) {
                    p.viewBookings();
                }

            } while (ch != 4);
        }

        else if (ro == 3) {
            cout << "Exiting system\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}