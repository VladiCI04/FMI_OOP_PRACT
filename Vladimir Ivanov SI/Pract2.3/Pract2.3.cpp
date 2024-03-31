#include <iostream>
#include <fstream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::ostream;
using std::istream;


// Global Constants
namespace GlobalConstants {
    constexpr unsigned short USER_FIELD_MAX_SIZE = 128;
    constexpr unsigned short USERS_MAX_COUNT = 100;
    constexpr char FILE_NAME[] = "system.csv";
    constexpr unsigned short MAX_COLS = 3;
    constexpr char SEP = ',';
    constexpr unsigned int BUFFER_SIZE = 300;
}


// Structs
struct User {
    char userName[GlobalConstants::USER_FIELD_MAX_SIZE];
    char email[GlobalConstants::USER_FIELD_MAX_SIZE];
    char password[GlobalConstants::USER_FIELD_MAX_SIZE];
};

struct System {
    User* users = new User[GlobalConstants::USERS_MAX_COUNT];
    unsigned short usersCount;
};
System s;

struct Row {
    User users[GlobalConstants::MAX_COLS];
};

struct CsvTable {
    Row rows[GlobalConstants::USERS_MAX_COUNT];
    unsigned short rowsCount = 0;
    unsigned short collsCount = 0;
};


// Functions
unsigned short parseRow(const char* row, Row& toReturn) {
    stringstream ss(row);
    unsigned short currentColumnCount = 0;

    while (!ss.eof()) {
        ss.getline(toReturn.users[currentColumnCount++], GlobalConstants::USER_FIELD_MAX_SIZE, GlobalConstants::SEP);
    }

    return currentColumnCount;
}

CsvTable parseFromFile(istream& ifs) {
    CsvTable result;
    char buff[GlobalConstants::BUFFER_SIZE];

    while (!ifs.eof()) {
        ifs.getline(buff, GlobalConstants::BUFFER_SIZE);
        result.collsCount = parseRow(buff, result.rows[result.rowsCount++]);
    }

    return result;
}

CsvTable parseFromFile(const char* fileName) {
    ifstream ifs(fileName);

    if (!ifs.is_open()) {
        return {};
    }

    return parseFromFile(ifs);
}

void printTable(const CsvTable& table) {
    for (unsigned short i = 0; i < table.rowsCount; i++) {
        for (unsigned short j = 0; j < table.collsCount; j++) {
            cout << table.rows[i].users[j] << ' ';
        }

        cout << endl;
    }
}

void saveRowToFile(ostream& ofs, const Row& row, unsigned short collsCount) {
    for (unsigned short i = 0; i < collsCount; i++) {
        ofs << row.users[i];

        if (i != collsCount - 1) {
            ofs << GlobalConstants::SEP;
        }
    }
}

void saveToFile(ostream& ofs, const CsvTable& table) {
    for (unsigned short i = 0; i < table.rowsCount; i++) {
        saveRowToFile(ofs, table.rows[i], table.collsCount);

        if (i != table.rowsCount - 1) {
            ofs << endl;
        }
    }
}

void saveToFile(const char* fileName, const CsvTable& table) {
    ofstream ofs(fileName);
    saveToFile(ofs, table);
    ofs.close();
}

void login() {
    User u;

    cout << "Enter Email: " << endl;
    cin >> u.email;
    cout << "Enter Password: " << endl;
    cin >> u.password;
    
    unsigned short index = 0;
    while (index < s.usersCount) {
        if (s.users[index].email == u.email && s.users[index].password == u.password) {
            cout << "Login successfully!" << endl; 
            return;
        }

        index++;
    }

    cout << "Login unsuccessfully!" << endl;
    return;
}

void reg() {
    User u;

    cout << "Enter UserName: " << endl;
    cin >> u.userName;
    cout << "Enter Email: " << endl;
    cin >> u.email;
    cout << "Enter Password: " << endl;
    cin >> u.password;

    s.users[s.usersCount++] = u;

    cout << "Register successfully!" << endl;
    return;
}

void showUsers() {

}

int main()
{
    char* command = new char[GlobalConstants::USERS_MAX_COUNT];

    while (true) {
        cout << "Enter command (Login, Register, ShowUsers or Exit): " << endl;
        cin >> command;

        if (command == "Login") {
            login();
        }
        else if (command == "Register") {
            reg();
        }
        else if (command == "ShowUsers") {
            showUsers();
        }
        else if (command == "Exit") {
            cout << "Goodbye!" << endl;
            return 0;
        }
        else {
            cout << "Not a valid command! Please write other one.";
        }
    }
}