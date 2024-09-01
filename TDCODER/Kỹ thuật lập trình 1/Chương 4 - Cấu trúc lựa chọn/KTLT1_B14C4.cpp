#include <iostream>
using namespace std;

int main() {
    char a, b;
    cin >> a >> b;
    
    string s1 = "NGUOI THU 1 THANG";
    string s2 = "NGUOI THU 2 THANG";
    string s3 = "HOA NHAU";
    string s4 = "KHONG HOP LE";
    
    switch (a) {
        case 'K': {
            switch (b) {
                case 'G':
                    cout << s1;
                    break;
                case 'B':
                    cout << s2;
                    break;
                case 'K':
                    cout << s3;
                    break;
                default:
                    cout << s4;
            }
            break;
        }
        
        case 'B': {
            switch (b) {
                case 'K':
                    cout << s1;
                    break;
                case 'G':
                    cout << s2;
                    break;
                case 'B':
                    cout << s3;
                    break;
                default:
                    cout << s4;
            }
            break;
        }
        
        case 'G': {
            switch (b) {
                case 'B':
                    cout << s1;
                    break;
                case 'K':
                    cout << s2;
                    break;
                case 'G':
                    cout << s3;
                    break;
                default:
                    cout << s4;
            }
            break;
        }
        
        default:
            cout << s4;
    }
    
    return 0;
}