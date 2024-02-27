#include <iostream>
using namespace std;
 
int main() {
    int n; 
    cin >> n;

    if (n < 10) {
        switch (n) {
            case 1: cout << "mot"; break;
            case 2: cout << "hai"; break;
            case 3: cout << "ba"; break;
            case 4: cout << "bon"; break;
            case 5: cout << "nam"; break;
            case 6: cout << "sau"; break;
            case 7: cout << "bay"; break;
            case 8: cout << "tam"; break;
            case 9: cout << "chin"; break;
        }
    } else if (n < 100) {
        switch (n/10) {
            case 1: cout << "muoi "; break;
            case 2: cout << "hai muoi "; break;
            case 3: cout << "ba muoi "; break;
            case 4: cout << "bon muoi "; break;
            case 5: cout << "nam muoi "; break;
            case 6: cout << "sau muoi "; break;
            case 7: cout << "bay muoi "; break;
            case 8: cout << "tam muoi "; break;
            case 9: cout << "chin muoi "; break;
        }
        switch (n%10) {
            case 1: cout << "mot"; break;
            case 2: cout << "hai"; break;
            case 3: cout << "ba"; break;
            case 4: cout << "bon"; break;
            case 5: cout << "nam"; break;
            case 6: cout << "sau"; break;
            case 7: cout << "bay"; break;
            case 8: cout << "tam"; break;
            case 9: cout << "chin"; break;   
        }
    } else {
        switch (n/100) {
            case 1: cout << "mot tram "; break;
            case 2: cout << "hai tram "; break;
            case 3: cout << "ba tram "; break;
            case 4: cout << "bon tram "; break;
            case 5: cout << "nam tram "; break;
            case 6: cout << "sau tram "; break;
            case 7: cout << "bay tram "; break;
            case 8: cout << "tam tram "; break;
            case 9: cout << "chin tram "; break;               
        }
        if (n/10%10 == 0 && n%10 != 0) {
            cout << "linh ";
            switch (n%10) {
                case 1: cout << "mot"; break;
                case 2: cout << "hai"; break;
                case 3: cout << "ba"; break;
                case 4: cout << "bon"; break;
                case 5: cout << "nam"; break;
                case 6: cout << "sau"; break;
                case 7: cout << "bay"; break;
                case 8: cout << "tam"; break;
                case 9: cout << "chin"; break;   
            }
        } else {
            switch (n/10%10) {
                case 1: cout << "muoi "; break;
                case 2: cout << "hai muoi "; break;
                case 3: cout << "ba muoi "; break;
                case 4: cout << "bon muoi "; break;
                case 5: cout << "nam muoi "; break;
                case 6: cout << "sau muoi "; break;
                case 7: cout << "bay muoi "; break;
                case 8: cout << "tam muoi "; break;
                case 9: cout << "chin muoi "; break;
            }
            switch (n%10) {
                case 1: cout << "mot"; break;
                case 2: cout << "hai"; break;
                case 3: cout << "ba"; break;
                case 4: cout << "bon"; break;
                case 5: cout << "nam"; break;
                case 6: cout << "sau"; break;
                case 7: cout << "bay"; break;
                case 8: cout << "tam"; break;
                case 9: cout << "chin"; break;   
            }
        }
    }

    return 0;
}