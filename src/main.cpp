// Blood Bank Management System
// Academic project demonstrating OOP, file handling, and basic user interaction

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// Base class representing a blood donor
class Blood
{
public:
    string firstname, lastname, gender, address, contact, bloodgroup, disease;
    int age, ageCheck, bp;
    float weight, height;

    void donate();

    // Function to collect donor details
    virtual void getDetails()
    {
        system("cls");
        cout << "\n\n\t\t----- Enter Donor Information -----\n\n";

        cout << "First Name: ";
        cin >> firstname;

        cout << "Last Name: ";
        cin >> lastname;

        cout << "Age: ";
        cin >> age;
        while(age < 18 || age > 60)
        {
            cout << "Invalid age! Enter age between 18 and 60: ";
            cin >> age;
        }

        cout << "Gender: ";
        cin >> gender;

        cout << "Weight (kg): ";
        cin >> weight;

        cout << "Height (cm): ";
        cin >> height;

        cout << "Blood Group: ";
        cin >> bloodgroup;

        cout << "Contact: ";
        cin >> contact;

        cout << "Address: ";
        cin >> address;
    }
};

// Derived class for recipient
class Recipient : public Blood
{
public:
    void getDetails() override
    {
        system("cls");
        cout << "\n\n\t\t----- Recipient Registration -----\n\n";

        cout << "First Name: ";
        cin >> firstname;

        cout << "Last Name: ";
        cin >> lastname;

        cout << "Age: ";
        cin >> age;

        cout << "Gender: ";
        cin >> gender;

        cout << "Address: ";
        cin >> address;

        cout << "Contact: ";
        cin >> contact;

        cout << "Required Blood Group: ";
        cin >> bloodgroup;

        cout << "Number of Blood Packets Needed: ";
        cin >> bp;
    }
};

Blood donor;
Blood* donorPtr = &donor;
Recipient recipientObj;

fstream donorFile;
fstream recipientFile;

// Save donor data
void saveDonorData()
{
    donorFile.open("donor_records.txt", ios::out | ios::app);
    donorPtr->getDetails();

    donorFile << "Name: " << donor.firstname << " " << donor.lastname << endl;
    donorFile << "Age: " << donor.age << endl;
    donorFile << "Gender: " << donor.gender << endl;
    donorFile << "Blood Group: " << donor.bloodgroup << endl;
    donorFile << "Contact: " << donor.contact << endl;
    donorFile << "Address: " << donor.address << endl << endl;

    donorFile.close();
}

// Show donor data
void displayDonorData()
{
    system("cls");
    donorFile.open("donor_records.txt", ios::in);

    if(!donorFile)
    {
        cout << "No donor data available.\n";
    }
    else
    {
        string line;
        while(getline(donorFile, line))
            cout << line << endl;
    }

    donorFile.close();
    system("pause");
}

// Eligibility check
void Blood::donate()
{
    system("cls");
    cout << "\n\n\t\t----- Donor Eligibility Check -----\n\n";

    cout << "Enter your age: ";
    cin >> ageCheck;

    cout << "Do you have any major disease? (yes/no): ";
    cin >> disease;

    if(ageCheck < 18 || ageCheck > 60 || disease == "yes")
    {
        cout << "\nYou are NOT eligible to donate blood.\n";
        system("pause");
    }
    else
    {
        cout << "\nYou are eligible! Proceeding with registration...\n";
        system("pause");
        saveDonorData();
    }
}

// Save recipient data
void saveRecipientData()
{
    recipientFile.open("recipient_records.txt", ios::out | ios::app);
    recipientObj.getDetails();

    recipientFile << "Name: " << recipientObj.firstname << " " << recipientObj.lastname << endl;
    recipientFile << "Age: " << recipientObj.age << endl;
    recipientFile << "Gender: " << recipientObj.gender << endl;
    recipientFile << "Blood Group Needed: " << recipientObj.bloodgroup << endl;
    recipientFile << "Packets Required: " << recipientObj.bp << endl << endl;

    recipientFile.close();

    cout << "\nRegistration successful!\n";
    system("pause");
}

// Show recipient data
void displayRecipientData()
{
    system("cls");
    recipientFile.open("recipient_records.txt", ios::in);

    if(!recipientFile)
    {
        cout << "No recipient data available.\n";
    }
    else
    {
        string line;
        while(getline(recipientFile, line))
            cout << line << endl;
    }

    recipientFile.close();
    system("pause");
}

// Admin panel
void adminPanel()
{
    int password;
    cout << "\nEnter Admin Password: ";
    cin >> password;

    if(password == 2107053)
    {
        int choice;
        cout << "\n1. View Donor Records\n2. View Recipient Records\nChoice: ";
        cin >> choice;

        if(choice == 1) displayDonorData();
        else if(choice == 2) displayRecipientData();
        else cout << "Invalid option.\n";
    }
    else
    {
        cout << "Wrong password!\n";
        system("pause");
    }
}

// Main menu
int main()
{
    int choice = 0;

    while(choice != 4)
    {
        system("cls");
        cout << "\n==== Blood Bank Management System ====\n";
        cout << "1. Donor\n";
        cout << "2. Recipient\n";
        cout << "3. Admin\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: donorPtr->donate(); break;
            case 2: saveRecipientData(); break;
            case 3: adminPanel(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n"; system("pause");
        }
    }
    return 0;
}
