#include <iostream>
using namespace std;

char b[9];
int cx=0, co=0, wx=0, wo=0;

bool check(char c, int i) {
    return ((b[i] == c && b[i + 3] == c && b[i + 6] == c) || (b[i * 3 + 0] == c && b[i * 3 + 1] == c && b[i * 3 + 2] == c) || (b[0] == c && b[4] == c && b[8] == c) || (b[2] == c && b[4] == c && b[6] == c));
}

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> b[i];
        if (b[i] == 'X') cx++;
        else if (b[i] == 'O') co++;
    }
    
    for (int i = 0; i < 3; i++) {
        wx += check('X', i);
        wo += check('O', i);
    }
    
    if ((wo > 0 && cx != co) || (cx != co && cx != co + 1) || (wx > 0 && cx != co + 1) || (wo > 0 && wx > 0)) 
        cout << "illegal";
    else if (wx) 
        cout << "the first player won";
    else if (wo) 
        cout << "the second player won";
    else if (cx + co == 9) 
        cout << "draw";
    else if (cx == co) 
        cout << "first";
    else 
        cout << "second";
        
    return 0;
}
