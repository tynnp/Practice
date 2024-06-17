struct Diem {
    int x, y;

    friend istream& operator >> (istream &in, Diem &diem) {
        in >> diem.x >> diem.y;
        return in;
    }

    friend ostream& operator << (ostream &out, Diem diem) {
        out << "(" << diem.x << ", " << diem.y << ")";
        return out;
    }