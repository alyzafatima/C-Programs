#include <iostream>
using namespace std;
#include <string>
#include <fstream>

void login();
void registeration();
void forgot_password();

int main()
{
    int c;
    cout << "\n\t\tREGISTERATION \n";
    cout << "\t\t    MENU \n";
    cout << "\n      ---------------------------------\n";
    cout << "\n\nPRESS 1 FOR REGISTERATION .\n";
    cout << "PRESS 2 FOR LOGIN . \n";
    cout << "PRESS 3 FOR FORGOT PASSWORD. \n";
    cout << "PRESS 4 TO EXIT \n";
    cout << "Enter your choice : ";
    cin >> c;
    switch (c)
    {
    case 1:
        registeration();
        break;
    case 2:
        login();
        break;
    case 3:
        forgot_password();
        break;
    case 4:
        cout << "Thankyou !";
        break;
    default:
        system("cls");
        cout << "Please choose number from (1 -4) ";
        main();
    }
}

void login()
{
    string log_user, log_password, rpass, rid;
    int count;
    system("cls");
    cout << "Enter the username and password : ";
    cin >> log_user;
    cin >> log_password;
    ifstream input("records.txt");
    while (input >> rid >> rpass)
    {
        if (rid == log_user && rpass == log_password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << log_user << " You are registered, Thankyou for logging in ";
        main();
    }
    else
    {
        cout << "login error!!! Plese check password and username\n";
        main();
    }
}

void registeration()
{
    string username, password, uid, upass;
    int count;
    system("cls");
    cout << "Enter your username and password  : ";
    cin >> username;
    cin >> password;

    ofstream fout("records.txt", ios::app);
    fout << username << " " << password << " ";
    fout.close();
    system("cls");
    cout << "You are succefully registerd \n";
    main();
}
void forgot_password()
{
    int a;
    system("cls");
    cout << "If you forgot password no worries \n ";
    cout << "Press 1 to search your password by username \n";
    cout << "Press 2 to go back to main menu \n";
    cin >> a;
    switch (a)
    {
    case 1:
    {
        int count = 0;
        string usr, pass, ud;
        cout << "Enter your username which you remembered : ";
        cin >> usr;
        ifstream if2("records.txt");
        while (if2 >> ud >> pass)
        {
            if (ud == usr)
            {
                count = 1;
            }
        }
        if2.close();
        if (count == 1)
        {
            cout << "Your password is found and it is  : " << pass << endl;
            main();
        }
        else
        {
            cout << "sorry your account is not fount ";
            main();
        }
        break;
    }

    case 2:
    {
        main();
    }
    break;
    default:
        cout << "Wrong choice please try again \n ";
        forgot_password();
    }
}
