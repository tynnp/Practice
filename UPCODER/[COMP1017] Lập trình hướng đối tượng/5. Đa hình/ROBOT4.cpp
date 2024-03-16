#include <iostream>
#include <sstream>
#define endl '\n'
using namespace std;

class Robot {
protected:
    string name;
    string userName;
    int energyLevel;
    int locationX;
    int locationY;
public:
    Robot() {
        this->name = "Robot";
        this->userName = "NoName";
        this->energyLevel = 100;
        this->locationX = 0;
        this->locationY = 0;
    }

    Robot(string name, string userName) {
        this->name = name;
        this->userName = userName;
        this->energyLevel = 100;
        this->locationX = 0;
        this->locationY = 0;
    }

    Robot(string name, string userName, int x, int y) {
        this->name = name;
        this->userName = userName;
        this->energyLevel = 100;
        this->locationX = x;
        this->locationY = y;
    }

    Robot(string name, string userName, int energyLevel, int x, int y) {
        this->name = name;
        this->userName = userName;
        this->energyLevel = energyLevel;
        this->locationX = x;
        this->locationY = y;
    }

    Robot(const Robot &other) {
        this->name = other.name;
        this->userName = other.userName;
        this->energyLevel = other.energyLevel;
        this->locationX = other.locationX;
        this->locationY = other.locationY;
    }

    void Charge() {
        this->energyLevel += 10;
        return;
    }

    virtual bool Move(int direction) {
        if (this->energyLevel <= 0) return false;
        if (direction < 0 || direction > 3) return false;

        switch (direction) {
            case 0: this->locationX--; break;
            case 1: this->locationX++; break;
            case 2: this->locationY++; break;
            case 3: this->locationY--; break; 
        }

        this->energyLevel -= 5;
        return true;
    }

    int getEnergyLevel() {
        return this->energyLevel;
    }

    void setEnergyLevel(int energyLevel) {
        this->energyLevel = energyLevel;
        return;
    }

    void Display() {
        cout << "{" << this->name << "}:{" << this->userName << "}\n";
        cout << "(" << this->locationX << "," << this->locationY << ")\n";
        cout << this->energyLevel << endl;
        return;
    }
};

class AdaptiveRobot : public Robot {
public: 
    AdaptiveRobot(string name, string userName, int energyLevel, int locationX, int locationY) :
        Robot(name, userName, energyLevel, locationX, locationY) {}

    AdaptiveRobot() {
        this->name = "AdaptiveRobot";
        this->userName = "NoName";
        this->energyLevel = 100;
        this->locationX = 0;
        this->locationY = 0;
    }

    bool Move(int direction) {
        if (this->energyLevel <= 0) return false;
        if (direction < 0 || direction > 3) return false;

        switch (direction) {
            case 0: this->locationX--; break;
            case 1: this->locationX++; break;
            case 2: this->locationY++; break;
            case 3: this->locationY--; break; 
        }

        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    Robot* danhSach[n];

    for (int i = 0; i < n; i++) {
        string name, userName, diChuyen;
        int energyLevel, locationX, locationY;
        cin >> name; 
        cin.ignore();
        getline(cin, userName);
        cin >> energyLevel >> locationX >> locationY;

        if (name[0] == 'A') danhSach[i] = new AdaptiveRobot(name, userName, energyLevel, locationX, locationY);
        else danhSach[i] = new Robot(name, userName, energyLevel, locationX, locationY);

        cin.ignore();
        getline(cin, diChuyen);
        stringstream ss(diChuyen);

        string tmp; int cnt = 1;
        while (ss >> tmp) {
            if (tmp == "-1") break;

            int number = stoi(tmp);
            if (number == 4) danhSach[i]->Charge();
            else if (name[0] != 'A') danhSach[i]->Move(number);

            else if (danhSach[i]->getEnergyLevel() > 50) {
                danhSach[i]->Move(number);
                ss >> tmp; number = stoi(tmp);
                danhSach[i]->Move(number);
                ss >> tmp; number = stoi(tmp);
                danhSach[i]->Move(number);
                danhSach[i]->setEnergyLevel(danhSach[i]->getEnergyLevel()-12);

            } else if (danhSach[i]->getEnergyLevel() > 20) {
                danhSach[i]->Move(number);
                ss >> tmp; number = stoi(tmp);
                danhSach[i]->Move(number);
                danhSach[i]->setEnergyLevel(danhSach[i]->getEnergyLevel()-9);

            } else {
                danhSach[i]->Move(number);
                danhSach[i]->setEnergyLevel(danhSach[i]->getEnergyLevel()-6);
            }
        }

        danhSach[i]->Display();
    }

    return 0;
}