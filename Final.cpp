?#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*This class contains functions to calculate the monthly salary, leave entitlement, and insurance price based on the employee's status.*/
class EmployeeInfo {
private:
    double statu, price;
    double insurance;
public:
    void priceAcordingStatu(int y) {/* Calculate monthly salary based on employee status*/
        if (y == 1) {
            statu = 3;
            price = statu * 17000;
            cout << "your monthly salary: " << price << endl;
        } else if (y == 2) {
            statu = 2;
            price = statu * 17000;
            cout << "your monthly salary: " << price << endl;
        } else if (y == 3) {
            statu = 1;
            price = statu * 17000;
            cout << "your monthly salary: " << price << endl;
        }
    }

    void leaveAcordingStatu(int y) {/// Calculate monthly leave entitlment based on employee status/
        if (y == 1) {
            statu = 3;
            cout << "your monthly leave entitlement: " << statu << endl;
        } else if (y == 2) {
            statu = 2;
            cout << "your monthly leave entitlement: " << statu << endl;
        } else if (y == 3) {
            statu = 1;
            cout << "your monthly leave entitlement: " << statu << endl;
        }
    }

    void insuranceAcordingStatu(int y) {/// Calculate monthly insurance price based on employee status/
        if (y == 1) {
            statu = 3;
            price = statu * 17000;
            insurance = price * 10 / 100;
            cout << "your monthly insurance price: " << insurance << endl;
        } else if (y == 2) {
            statu = 2;
            price = statu * 17000;
            insurance = price * 10 / 100;
            cout << "your monthly insurance price: " << insurance << endl;
        } else if (y == 3) {
            statu = 1;
            price = statu * 17000;
            insurance = price * 10 / 100;
            cout << "your monthly insurance price: " << insurance << endl;
        }
    }
};
/* This class handles user registration, login, and stores user information such as username, password, and employee status. It also writes the user information to a file for future reference.*/
class UserMemory : public EmployeeInfo {
private:
    string getUserName, getPassword, userNameCheck[100], passwordCheck[100], employeeStatuCheck[100];
    string *UN, *P, *ES;
    int j = 0;
    int SC2, employeeStatu;
    EmployeeInfo deneme1;

public:
    UserMemory() {
        UN = userNameCheck;
        P = passwordCheck;
        ES = employeeStatuCheck;
    }
    //Register a new user and store their information
    void sign_up() {
        if (j < 100) {
            cout << "choose which one you are" << endl << "1=full time employee 2=part time employee 3=intern";
            cin >> *(ES + j);
            cout << endl << endl << "create username: ";
            cin >> *(UN + j);
            cout << "create password: ";
            cin >> *(P + j);
            j++;
            cout << "your personal number is: " << j << endl;
            cout << "!!!!!!!!!!Please do not forget your personal number. If you forget it, you will not be able to log in again!!!!!!!!!" << endl;

            ofstream file("employee_info.txt", ios::app);
        if (file.is_open()) {
            file << "Employee status: " << ES[j-1] << endl;
            file << "Username: " << UN[j-1] << endl;
            file << "Password: " << P[j-1] << endl;
            file << "-----------------------------" << endl;
            file.close();
        } else {
            cout << "Unable to open file for writing." << endl;
        }
        } else {
            cout << "Maximum user limit reached." << endl;
        }
    }
     //Logging in as an Employee
    void login() {
        int personalNum;
        cout << "personal number: ";
        cin >> personalNum;
        cout << "user name: ";
        cin >> getUserName;
        cout << "password: ";
        cin >> getPassword;

        if (personalNum <= j && *(UN + personalNum - 1) == getUserName && *(P + personalNum - 1) == getPassword) {
            cout << "Press 1 for operations regarding salary, press 2 for operations regarding monthly leave entitlement, press 3 for insurance information.";
            cin >> SC2;
            switch (SC2) {
                case 1:
                    if (*(ES + personalNum - 1) == "1") {
                        priceAcordingStatu(1);
                    } else if (*(ES + personalNum - 1) == "2") {
                        priceAcordingStatu(2);
                    } else if (*(ES + personalNum - 1) == "3") {
                        priceAcordingStatu(3);
                    } else {
                        cout << "Invalid employee status." << endl;
                    }
                    break;
                case 2:
                    if (*(ES + personalNum - 1) == "1") {
                        leaveAcordingStatu(1);
                    } else if (*(ES + personalNum - 1) == "2") {
                        leaveAcordingStatu(2);
                    } else if (*(ES + personalNum - 1) == "3") {
                        leaveAcordingStatu(3);
                    } else {
                        cout << "Invalid employee status." << endl;
                    }
                    break;
                case 3:
                    if (*(ES + personalNum - 1) == "1") {
                        insuranceAcordingStatu(1);
                    } else if (*(ES + personalNum - 1) == "2") {
                        insuranceAcordingStatu(2);
                    } else if (*(ES + personalNum - 1) == "3") {
                        insuranceAcordingStatu(3);
                    } else {
                        cout << "Invalid employee status." << endl;
                    }
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    break;
            }
        } else {
            cout << "something went wrong. Please check your information." << endl;
        }
    }

    friend class Boss;
};
/*This class extends the EmployeeInfo class and provides additional functions specific to the boss, such as calculating the boss's monthly salary, leave entitlement, and insurance price. The boss can also view the information of all employees.*/
class Boss : public EmployeeInfo {
private:
    UserMemory* um;

public:
    Boss(UserMemory* userMemory) : um(userMemory) {}

    void priceAcordingStatu() {
        double statu = 5;
        double price = statu * 25000;
        cout << "Boss's monthly salary: " << price << endl;
    }

    void leaveAcordingStatu() {
        double statu = 6;
        cout << "Boss's monthly leave entitlement: " << statu << endl;
    }

    void insuranceAcordingStatu() {
        double statu = 5;
        double price = statu * 25000;
        double insurance = price * 5 / 100;
        cout << "Boss's monthly insurance price: " << insurance << endl;
    }
    //Logging in as a Boss
    void login() {
        string personalNum;
        cout << "personal number: ";
        cin >> personalNum;

        if (personalNum == "0001") {
            for (int i = 0; i < um->j; i++) {
                cout << "Employee Personal Number: " << (i + 1) << endl;
                cout << "Employee Username: " << *(um->UN + i) << endl;
                cout << "Employee Status: " << *(um->ES + i) << endl;
                cout << "-----------------------------" << endl;
            }
            cout << "Boss additional information:" << endl;
            priceAcordingStatu();
            leaveAcordingStatu();
            insuranceAcordingStatu();
        } else {
            cout << "Invalid personal number." << endl;
        }
    }
};
//Main menu for user interaction
/*This class acts as the main interface for the Employee Management System. It allows users to sign up, log in as an employee or boss, and perform various operations based on their role.*/
class MainMenu : public UserMemory {
private:
    UserMemory deneme;
    Boss* boss;
    int loop = 1, SC1;

public:
    MainMenu() {
        boss = new Boss(&deneme);
    }

    ~MainMenu() {
        delete boss;
    }

    void start() {
        while (loop == 1) {
            cout << "Please press 1 to sign up" << endl << "Please press 2 to log in as employee" << endl << "Please press 3 to log in as boss" << endl << "Your choice is: ";
            cin >> SC1;

            switch (SC1) {
                case 1:
                    deneme.sign_up();
                    break;
                case 2:
                    deneme.login();
                    break;
                case 3:
                    boss->login();
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }

            cout << "Press 1 to go to home tab and press 0 to exit the application. ";
            cin >> loop;
        }
    }
};

int main() {
    cout << "hello welcome to our company" << endl << endl;
    MainMenu x1;
    x1.start();

    return 0;
}

