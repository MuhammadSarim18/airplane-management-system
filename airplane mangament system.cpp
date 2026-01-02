#include <iostream> 
using namespace std; 
const int ROWS = 12; 
const int COLS = 7; 
void viewSeatingPlan(int Seats[][7], int 
rows, int cols) { 
    cout << "Seating Plan (0 = Available, 1 = Booked):" << endl; 
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            cout << Seats[i][j] << " "; 
        } 
        cout << endl; 
    } 
} 
  
int checkAvailableSeats(int Seats[][7], int 
rows, int cols) { 
    int availableSeats = 0; 
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            if (Seats[i][j] == 0) { 
                availableSeats++; 
            } 
        } 
    } 
    return availableSeats; 
} 

void getFare() { 
    cout << "Fare for each class:" << endl; 
    cout << "1. First Class: Rs. 20,000" << 
endl; 
    cout << "2. Business Class: Rs. 17,000" 
<< endl; 
    cout << "3. Economy Class: Rs. 12,000" 
<< endl; 
} 


bool bookEconomyClass(int Seats[][7], 
int rows, int cols, int noOfSeats) { 
    int bookedSeats = 0; 
    for (int i = 4; i < rows && bookedSeats < 
noOfSeats; i++) { 
        for (int j = 0; j < cols && bookedSeats 
< noOfSeats; j++) { 
            if (Seats[i][j] == 0) { 
                Seats[i][j] = 1; 
                bookedSeats++; 
            } 
        } 
    } 
    return bookedSeats == noOfSeats; 
} 
  
  
bool systemReset(int Seats[][7], int rows, 
int cols) { 
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            Seats[i][j] = 0; 
        } 
    } 
    return true; 
} 
int main() { 
    int Seats[ROWS][COLS] = {0};  
    int choice, noOfSeats; 
  
    while (true) { 
        cout << "\nAirline Reservation System" << endl; 
        cout << "1. Book First Class Seats" << endl; 
        cout << "2. Book Business Class Seats" << endl; 
        cout << "3. Book Economy Class Seats" << endl; 
        cout << "4. View Aeroplane Seating Plan" << endl; 
        cout << "5. View Fare (s)" << endl; 
        cout << "6. System Reset" << endl; 
        cout << "7. Exit From The Booking System" << endl; 
        cout << "Enter your choice: "; 
        cin >> choice; 
  
        switch (choice) { 
            case 1: 
                cout << "Enter the number of seats to book in First Class: "; 
                cin >> noOfSeats; 
                
  
            case 3: 
                cout << "Enter the number of seats to book in Economy Class: "; 
                cin >> noOfSeats; 
                if (bookEconomyClass(Seats, ROWS, COLS, noOfSeats)) { 
                    cout << "Seats successfully booked in Economy Class." << endl; 
                } else { 
                    cout << "Unable to book the requested number of seats in Economy Class." << endl; 
                } 
                break; 
  
            case 4: 
                viewSeatingPlan(Seats, ROWS, COLS); 
                break; 
  
            case 5: 
                getFare(); 
                break; 
  
            case 6: 
                if (systemReset(Seats, ROWS, COLS)) { 
                    cout << "System reset successful. All seats are now available." << endl; 
                } 
                break; 
  
            case 7: 
                cout << "Exiting the system." << 
endl; 
                return 0; 
  
            default: 
                cout << "Invalid choice. Please try again." << endl; 
        } 
    } 
  
    return 0; 
}