#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstring>
#include<string>
#include<Windows.h>
using namespace std;
int admin_choice;
string reguser, regpass, ru, rp;
int choicelog;
void variables::add_shopkeeper()
{
    system("cls");
    cout << "ADD DETAILS" << endl;
    fstream file;
    cout << "Enter Identification Number: ";
    cin >> cid;
    cout << "Enter the username :";
    cin >> reguser;
    cout << "Enter the password :";
    cin >> regpass;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter email : ";
    cin >> email;
    cout << "Enter password : ";
    cin >> password;
    cout << "Enter date : ";
    cin >> date;
    cout << "Enter gender : ";
    cin >> gender;
    cout << "Enter blood : ";
    cin >> blood;
B:
    cout << "\n\n\t\tEnter Your Mobile Number: ";
    cin >> phone_no;
    if (phone_no.length() != 11)
    {
        cout << "\nInvalid Phone Number";
        goto B;
    }
    else
    {
        // The First letter should not start with 0 or 1
        if (phone_no[0] != '0' || phone_no[0] == '1')
        {
            cout << "\nInvalid Phone Number\n";
            goto B;
        }
        else
        {
            cout << "\nValid Phone Number\n";
        }
    }
    cout << "Enter address : ";
    cin >> address;
    string fname;
    fname = reguser + "\n" + regpass + "\n" + name + "\n" + cid + "\n" + phone_no + "\n" + gender + "\n" + blood + "\n" + email + "\n" + password + "\n" + username + "\n" + date + "\n" + address;
    int chhhose;
x:
    if (choicelog == 3 || admin_choice == 5)
    {
        file.open("shopkeeper.txt", ios::app);
        file << fname;
        cout << "\n\nYOUR DATA HAS BEEN SUCCESSFULLY INSERTED" << endl;
        cout << "\n\nPress Any Key To Continue..";
        file.close();
        shopping b;
        b.shopkeeper_menu1();
    }
    else if (choicelog == 2)
    {
        file.open("customer.txt", ios::app);
        file << fname;
        cout << "\n\nYOUR DATA HAS BEEN SUCCESSFULLY INSERTED" << endl;
        cout << "\n\nPress Any Key To Continue..";
        file.close();
        shopping b;
        b.shopkeeper_menu1();
    }
    else
        cout << choicelog;
}

void registr() {
    system("cls");
    variables vs;
    vs.add_shopkeeper();
    system("cls");
    cout << "\nRegistration Sucessful\n";
}

void variables::shopkeeper_menu() {
    int choice = 9;
    shopping as;
    system("cls");
    cout << "\n\n\n\t\t\t ShopKeeper Menu\n\n";
    cout << "\n\t\t   1- Add Product   ";
    cout << "\n\t\t   2- Modify Product";
    cout << "\n\t\t   3- Delete Product";
    cout << "\n\t\t   4- View Products ";
    cout << "\n\t\t   5- Exit          ";
    cout << "\n\n\t  Please enter your choice : ";
    int admin_choice;
    cin >> admin_choice;
    while (admin_choice != 7)
    {
        switch (admin_choice)
        {
        case 1:
            as.add();
            system("pause");
            system("cls");
            shopkeeper_menu();
            break;
        case 2:
            as.edit();
            system("pause");
            system("cls");
            shopkeeper_menu();
            break;
        case 3:
            as.rem();
            system("pause");
            system("cls");
            shopkeeper_menu();
            break;
        case 4:
            system("cls");
            as.list();
            system("pause");
            system("cls");
            shopkeeper_menu();
            break;
        case 5:
            as.shopkeeper_menu1();
            system("pause");
            system("cls");
            break;
        default:
            cout << "Enter Valid Choice : ";
            system("pause");
            shopkeeper_menu();
        }
    }
}

class buyerr : public variables {
private:
    shopping sho;
public:
    void buyer();
    void receipt();
};

void login()
{
    if (choicelog == 3)
    {
        int count = 0;;
        string user, pass, u, p;
        system("cls");
        cout << "\n\n\t\t\tplease enter the following details" << endl;
        cout << "\t\t\tUSERNAME :";
        cin >> user;
        cout << "\t\t\tPASSWORD :";
        cin >> pass;
        ifstream input("shopkeeper.txt");
        while (input >> u >> p)
        {
            if (u == user && p == pass)

            {
                count = 1;
                system("cls");
            }
        }
        input.close();
        if (count == 1)
        {
            cout << endl << "\n\n\t\t\t\t\t | Logging In | " << endl;
            cout << "\t\t\t\t ";
            for (int s = 1; s < 5; s++) {
                Sleep(500);
                cout << ".......";
            }
            variables a;
            cout << "\nLogged In ";
            system("pause");
            a.shopkeeper_menu();
        }
        else
        {
            shopping sh;
            cout << "\nLOGIN ERROR\nPlease check your username and password\n";
            sh.shopkeeper_menu1();
        }
    }
    else if (choicelog == 2) {
        int count = 0;;
        string user, pass, u, p;
        system("cls");
        cout << "\n\n\t\t\tplease enter the following details" << endl;
        cout << "\t\t\tUSERNAME :";
        cin >> user;
        cout << "\t\t\tPASSWORD :";
        cin >> pass;

        ifstream input("customer.txt");
        while (input >> u >> p)
        {
            if (u == user && p == pass)

            {
                count = 1;
                system("cls");
            }
        }
        input.close();
        if (count == 1) {
            cout << endl << "\n\n\t\t\t\t\t | Logging In | " << endl;
            cout << "\t\t\t\t ";
            for (int s = 1; s < 5; s++) {
                Sleep(500);
                cout << ".......";
            }
            buyerr a;
            cout << "\nLogged In ";
            system("pause");
            a.buyer();
        }
        else
        {
            shopping sh;
            cout << "\nLOGIN ERROR\nPlease check your username and password\n";
            system("pause");
            sh.shopkeeper_menu1();
        }
    }
}

void shopping::update_data() {

}


void shopping::shopkeeper_menu1() {
    system("cls");
    buyerr bb;
    cout << "\n\t\t   1- Register        ";
    cout << "\n\t\t   2- Login           ";
    cout << "\n\t\t   3- Exit            ";
    cout << "\n\n\t  Please enter your choice : ";
    int admin_choice;
    cin >> admin_choice;
    if (choicelog == 3) {
        while (admin_choice != 7)
        {
            switch (admin_choice)
            {
            case 1:
                registr();
                system("pause");
                system("cls");
                shopkeeper_menu1();
                break;
            case 2:
                login();
                system("pause");
                system("cls");
                break;
            case 3:
                menu();
            }
        }
    }
    if (choicelog == 2) {
        while (admin_choice != 7)
        {
            switch (admin_choice)
            {
            case 1:
                registr();
                system("pause");
                system("cls");
                shopkeeper_menu1();
                break;
            case 2:
                login();
                system("pause");
                system("cls");
                break;
            case 3:
                menu();
            }
        }
    }
}

bool shopping::Admin_login() {
    system("cls");
    cout << "\t\tUser name : ";
    cin >> SAName;
    cout << "\t\tPassword : ";
    while ((ch = _getch()) != 13) {
        cout << "*";
        SAPass[i] = ch;
        i++;
    }
    SAPass[i] = '\0';
    srand(time(0));
    gen_captcha = rand();
    cout << endl << "Enter this number below : " << gen_captcha << endl;
    cout << "Enter the above number : ";
    cin >> Input_captcha;
    if ((strcmp(SAName, "admin") == 0) && (strcmp(SAPass, "admin") == 0) && (Input_captcha == gen_captcha)) {
        cout << endl << "\t\t\t\t | Veryfing Admin | " << endl;
        cout << "\t\t\t\t ";
        for (int s = 1; s < 5; s++) {
            Sleep(500);
            cout << "......";
        }
        cout << endl << endl << "\t\t\t\t   Access Granted... ;)" << endl << endl;
        system("pause");
        system("cls");
        int x = true;
        administrator();
        return true;
    }
    else
    {
        cout << endl << "\t\t\t\t | Veryfing Admin | " << endl;
        cout << "\t\t\t\t ";
        for (int s = 1; s < 5; s++) {
            Sleep(400);
            cout << "......";
        }
        cout << endl << endl << "\t\t\t\t   Access Denied... :(" << endl << endl;
        system("pause");
        menu();
        system("pause");
        return false;
    }
}

void shopping::administrator() {
    system("cls");
    cout << "\n\n\n\t\t\t Administrator Menu";
    cout << "\n\t\t   1- Add Product     ";
    cout << "\n\t\t   2- Modify Product  ";
    cout << "\n\t\t   3- Delete Product  ";
    cout << "\n\t\t   4- View Products   ";
    cout << "\n\t\t   5- Add ShopKeeper  ";
    cout << "\n\t\t   6- Exit            ";
    cout << "\n\n\t   Please enter your choice : ";
    cin >> admin_choice;
    while (admin_choice != 7)
    {
        switch (admin_choice)
        {
        case 1:
            add();
            system("pause");
            system("cls");
            administrator();
            break;
        case 2:
            edit();
            system("pause");
            system("cls");
            administrator();
            break;
        case 3:
            rem();
            system("pause");
            system("cls");
            administrator();
            break;
        case 4:
            system("cls");
            list();
            system("pause");
            system("cls");
            administrator();
            break;
        case 5:
            system("cls");
            add_shopkeeper();
            system("pause");
            system("cls");
            administrator();
        case 6:
            menu();
            system("pause");
            system("cls");
            break;
        default:
            cout << "Enter Valid Choice : ";
            system("pause");
            administrator();
        }
    }
}

void shopping::menu() {
    buyerr buy;
    system("cls");
    cout << "\t\t     Supermarket Main Menu     " << endl;
    cout << "\t\t     1- administrator           " << endl;
    cout << "\t\t     2- Customer                " << endl;
    cout << "\t\t     3- Shop Keeper             " << endl;
    cout << "\t\t     4- Exit                    " << endl;
    cout << "\n\t     Please select : ";
    cin >> choicelog;
    switch (choicelog) {
    case 1:
        Admin_login();
        break;
    case 2:
        shopkeeper_menu1();
    case 3:
        shopkeeper_menu1();
    case 4:
        exit(0);
    default:
        cout << "Please enter from the given options : ";
        system("pause");
        menu();
    }
}

void shopping::rem() {
    system("cls");
    list();
    cout << "\n\n\t Delete Product";
    cout << "\n\n\t Product code : ";
    cin >> pkey;
    data.open("products.txt", ios::in);
    if (!data) {
        cout << "File does not exist";
    }
    else {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pcode == pkey) {
                cout << "Product deleted successfully";
                token++;
            }
            else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("products.txt");
        rename("database1.txt", "products.txt");
        if (token == 0) {
            cout << "\n\nRecord not found";
        }
    }
}

void shopping::add() {
    system("cls");
m:
    token = 0;
    cout << "\n\n\t\t\t Add New Product";
    cout << "\n\n\t Code Of The Product : ";
    cin >> pcode;
    cout << "\n\n\t Name Of The Product : ";
    cin >> pname;
    cout << "\n\n\t Price Of The Product : ";
    cin >> price;
    cout << "\n\n\t Discount Of The Product : ";
    cin >> dis;
    data.open("products.txt", ios::in);
    if (!data) {
        data.open("products.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else {
        data >> c >> n >> p >> d;
        while (!data.eof()) {
            if (c == pcode) {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
        if (token == 1)
            goto m;
        else {
            data.open("products.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t Record Inserted";
}

void shopping::edit() {
    system("cls");
    list();
    cout << "\n\t\t\t Modify The Record";
    cout << "\n\t\t\t Product Code : ";
    cin >> pkey;
    data.open("products.txt", ios::in);
    if (!data) {
        cout << "\n\nFile does not exist";
    }
    else {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\n\t Code Of The Product : ";
                cin >> c;
                cout << "\n\n\t Name Of The Product : ";
                cin >> n;
                cout << "\n\n\t Price Of The Product : ";
                cin >> p;
                cout << "\n\n\t Discount Of The Product : ";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record Has Been Edited";
                token++;
            }
            else {
                data1 << " " << pcode << " " << pname << " " << price << " " << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("products.txt");
        rename("database1.txt", "products.txt");
        if (token == 0) {
            cout << "\n\n Record not found sorry";
        }
    }
    administrator();
}

void buyerr::buyer() {
    system("cls");
    int choice;
    cout << "\t\t\t  Buyer\n\n";
    cout << "\t\t   1- Buy Product  " << endl;
    cout << "\t\t   2- Exit         " << endl;
    cout << "\n\t\t Please select : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
    case 2:
        sho.menu();
    default:
        cout << "Please enter from the given options : ";
        system("pause");
        buyer();
    }
}

void shopping::list() {
    fstream data;
    data.open("products.txt", ios::in);
    cout << "\n\n_______________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n_______________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof()) {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void buyerr::receipt() {
    system("cls");
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;
    cout << "\n\n\t\t\t\t RECEIPT";
    data.open("products.txt", ios::in);
    if (!data) {
        cout << "\n\n No Data has been entered";
    }
    else {
        data.close();
        sho.list();
        cout << "\n___\n";
        cout << "\n|                                    \n";
        cout << "\n|        Please Place order          \n";
        cout << "\n|                                    \n";
        cout << "\n___\n";
        do {
            cout << "\n\nEnter Product Code : ";
            cin >> arrc[c];
            cout << "\n\nEnter Product quantity : ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n Duplicate Product code!!";
                    //goto m;
                }
            }
            c++;
            cout << "\n\nDo you want to buy another product? y/n";
            cin >> choice;
        } while (choice == 'y');
        system("cls");
        cout << "\n\n\t\t\t___RECEIPT_\n";
        cout << "\nProduct No\t Product Name\t Product Quantity\t Price\t Amount\t With Discount\n";
        for (int i = 0; i < c; i++) {
            data.open("products.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
        data.close();
    }
    cout << endl << "\n\t\t\t\t | Taking Out receipt | " << endl;
    cout << "\t\t\t\t ";
    for (int s = 1; s < 5; s++) {
        Sleep(500);
        cout << "......";
    }
    cout << endl << endl << "\t\t\t\t  Thank You For Shopping With Us... :)" << endl << endl;
    cout << "\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    cout << "\n Total amount : " << total << endl;
    cout << "\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    system("pause");
}
Header.h:

#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstring>
#include<string>
#include<Windows.h>
using namespace std;

class variables {
protected:
    int pcode;
    float price;
    float dis;
    string pname;
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p, d;
    string n, name, username, email, password, date, gender, blood, phone_no, address, cid, id, usn, psd;
    bool b = false;
public:
    void add_shopkeeper();
    void shopkeeper_menu();
};

class shopping : public variables {
private:
    char SAName[20];
    char SAPass[20];
    int ch, i = 0, gen_captcha = 0, Input_captcha = 0;
public:
    bool Admin_login();
    void menu();
    void administrator();
    void add();
    void edit();
    void rem();
    void list();
    void shopkeeper_menu1();
    void update_data();
};

Source1.cpp:

#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstring>
#include<string>
#include<Windows.h>
#include "Header.h"
using namespace std;

int main() {
    shopping a;
    a.menu();
}

 
 
  

