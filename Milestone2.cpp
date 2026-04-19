#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

// ================= CONSTANTS =================
const int VIEW_OPTION = 1;
const int UPDATE_OPTION = 2;
const int EXIT_OPTION = 3;
const int LOGOUT_OPTION = 4;
const int MAX_ATTEMPTS = 3;

// ================= DATA STRUCTURE =================
struct Customer {
    string name;
    string service;
};

// Hardcoded credentials
const string VALID_USERNAME = "admin";
const string VALID_PASSWORD = "password123";

// ================= FUNCTION PROTOTYPES =================
bool CheckUserPermissionAccess();
void DisplayMenu();
int GetValidatedInput();
void ProcessUserChoice(int choice, vector<Customer>& customers);
void ViewCustomers(const vector<Customer>& customers);
void UpdateCustomer(vector<Customer>& customers);

// ================= MAIN =================
int main()
{
    cout << "Created by Tatum Scott\n" << endl;

    vector<Customer> customers = {
        {"John Doe", "Internet"},
        {"Jane Smith", "Cable"},
        {"Mike Brown", "Phone"}
    };

    while (true)
    {
        if (!CheckUserPermissionAccess())
        {
            cout << "Too many failed attempts. Exiting.\n";
            return 0;
        }

        int choice = 0;

        do {
            DisplayMenu();
            choice = GetValidatedInput();
            ProcessUserChoice(choice, customers);

        } while (choice != EXIT_OPTION && choice != LOGOUT_OPTION);

        if (choice == EXIT_OPTION)
            break;

        cout << "\nYou have been logged out.\n";
    }

    cout << "Program terminated.\n";
    return 0;
}

// ================= AUTH =================
bool CheckUserPermissionAccess()
{
    string username, password;

    for (int attempts = 0; attempts < MAX_ATTEMPTS; attempts++)
    {
        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        if (username == VALID_USERNAME && password == VALID_PASSWORD)
            return true;

        cout << "Invalid credentials.\n";
    }

    return false;
}

// ================= MENU =================
void DisplayMenu()
{
    cout << "\nCustomer Management System\n";
    cout << "--------------------------\n";
    cout << VIEW_OPTION << ". View Customers\n";
    cout << UPDATE_OPTION << ". Update Customer\n";
    cout << EXIT_OPTION << ". Exit\n";
    cout << LOGOUT_OPTION << ". Logout\n";
}

// ================= INPUT =================
int GetValidatedInput()
{
    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again: ";
        cin >> choice;
    }

    return choice;
}

// ================= PROCESS =================
void ProcessUserChoice(int choice, vector<Customer>& customers)
{
    switch (choice)
    {
    case VIEW_OPTION:
        ViewCustomers(customers);
        break;
    case UPDATE_OPTION:
        UpdateCustomer(customers);
        break;
    case EXIT_OPTION:
        cout << "Exiting...\n";
        break;
    case LOGOUT_OPTION:
        cout << "Logging out...\n";
        break;
    default:
        cout << "Invalid option.\n";
    }
}

// ================= VIEW =================
void ViewCustomers(const vector<Customer>& customers)
{
    cout << "\nCustomer List:\n";

    for (size_t i = 0; i < customers.size(); i++)
    {
        cout << i + 1 << ". " << customers[i].name
            << " - " << customers[i].service << endl;
    }
}

// ================= UPDATE =================
void UpdateCustomer(vector<Customer>& customers)
{
    ViewCustomers(customers);

    int index;
    cout << "Select customer number: ";
    cin >> index;

    if (index < 1 || index > customers.size())
    {
        cout << "Invalid selection.\n";
        return;
    }

    cout << "Enter new service: ";
    cin >> customers[index - 1].service;

    cout << "Customer updated successfully.\n";
}