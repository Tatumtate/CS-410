#include <iostream>
#include <string>
#include <limits>

using namespace std;

// VULNERABILITY 1 (Global variables): userChoice and permissionLevel should not be global.
// FIX: Move them into main() and pass as needed.

int CheckUserPermissionAccess();
void DisplayInfo();
void ChangeCustomerChoice(int &userChoice);

int main()
{
    cout << "Created by Tatum Scott" << endl << endl;

    int permissionLevel = 0;   // FIX for VULNERABILITY 1
    int userChoice = 0;        // FIX for VULNERABILITY 1

    permissionLevel = CheckUserPermissionAccess();

    if (permissionLevel != 1)
    {
        // VULNERABILITY 7: Information disclosure
        // FIX: Use generic message
        cout << "Unable to verify credentials." << endl;
        return 0;
    }

    do
    {
        DisplayInfo();
        ChangeCustomerChoice(userChoice);
    }
    while (userChoice != 3);

    return 0;
}

// Checks user permission access
int CheckUserPermissionAccess()
{
    string username;
    string password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // VULNERABILITY 2 & 3: Weak authentication and no validation
    // FIX: Add minimal validation (still not secure, but improved)
    if (username.length() < 3 || password.length() < 3)
    {
        return 2; // Access denied
    }

    // NOTE: Real authentication requires secure storage, hashing, etc.
    return 1;
}

void DisplayInfo()
{
    cout << endl;
    cout << "Customer Management System" << endl;
    cout << "---------------------------" << endl;
    cout << "1. View Customer Information" << endl;
    cout << "2. Change Customer Choice" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
}

void ChangeCustomerChoice(int &userChoice)
{
    cout << "Enter your choice: ";

    cin >> userChoice;

    // VULNERABILITY 4 & 6: No input validation
    // FIX: Validate input and clear bad input
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number." << endl;
        userChoice = 0;
        return;
    }

    if (userChoice == 1)
    {
        cout << "Displaying customer information..." << endl;
    }
    else if (userChoice == 2)
    {
        cout << "Customer choice updated." << endl;
    }
    else if (userChoice == 3)
    {
        cout << "Exiting program..." << endl;
    }
    else
    {
        cout << "Invalid selection." << endl;
    }
}
