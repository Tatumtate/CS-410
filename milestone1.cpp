#include <iostream>
#include <string>
#include <limits>

using namespace std;

// ================= CONSTANTS =================
const int VIEW_OPTION = 1;
const int UPDATE_OPTION = 2;
const int EXIT_OPTION = 3;
const int LOGOUT_OPTION = 4;

const int MAX_ATTEMPTS = 3;

// Hardcoded credentials (for demonstration purposes)
const string VALID_USERNAME = "admin";
const string VALID_PASSWORD = "password123";

// ================= FUNCTION PROTOTYPES =================
int CheckUserPermissionAccess();
void DisplayInfo();
int GetValidatedInput();
void ProcessUserChoice(int userChoice);

// ================= MAIN FUNCTION =================
int main()
{
    cout << "Created by Tatum Scott" << endl << endl;

    while (true)
    {
        int permissionLevel = CheckUserPermissionAccess();

        if (permissionLevel != 1)
        {
            cout << "Unable to verify credentials." << endl;
            return 0;
        }

        int userChoice = 0;

        do
        {
            DisplayInfo();
            userChoice = GetValidatedInput();
            ProcessUserChoice(userChoice);

        } while (userChoice != EXIT_OPTION && userChoice != LOGOUT_OPTION);

        if (userChoice == EXIT_OPTION)
        {
            break;
        }

        // If LOGOUT_OPTION is selected, loop continues and user logs in again
        cout << "\nYou have been logged out.\n" << endl;
    }

    cout << "Program terminated." << endl;
    return 0;
}

// ================= AUTHENTICATION =================
int CheckUserPermissionAccess()
{
    string username;
    string password;

    int attempts = 0;

    while (attempts < MAX_ATTEMPTS)
    {
        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        if (username == VALID_USERNAME && password == VALID_PASSWORD)
        {
            return 1; // Access granted
        }

        cout << "Invalid credentials. Try again." << endl;
        attempts++;
    }

    return 2; // Access denied
}

// ================= DISPLAY MENU =================
void DisplayInfo()
{
    cout << endl;
    cout << "Customer Management System" << endl;
    cout << "---------------------------" << endl;
    cout << VIEW_OPTION << ". View Customer Information" << endl;
    cout << UPDATE_OPTION << ". Change Customer Choice" << endl;
    cout << EXIT_OPTION << ". Exit Program" << endl;
    cout << LOGOUT_OPTION << ". Logout" << endl;
    cout << endl;
}

// ================= INPUT VALIDATION =================
int GetValidatedInput()
{
    int choice;

    cout << "Enter your choice: ";
    cin >> choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number." << endl;
        return 0;
    }

    return choice;
}

// ================= PROCESS USER CHOICE =================
void ProcessUserChoice(int userChoice)
{
    if (userChoice == VIEW_OPTION)
    {
        cout << "Displaying customer information..." << endl;
    }
    else if (userChoice == UPDATE_OPTION)
    {
        cout << "Customer choice updated." << endl;
    }
    else if (userChoice == EXIT_OPTION)
    {
        cout << "Exiting program..." << endl;
    }
    else if (userChoice == LOGOUT_OPTION)
    {
        cout << "Logging out..." << endl;
    }
    else
    {
        cout << "Invalid selection." << endl;
    }
}