#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Rating {
private:
    int like;
    int dislike;
    int *comment;
    int n;
public:
    Rating() {
        like = 0;
        dislike = 0;
        comment = new int[100];
    }

    Rating(int like,int dislike, int n) {
        this->like = like;
        this->dislike = dislike;
        this->n = n;
        this->comment = new int[n];
    } 

    ~Rating() {}

    float getLikeRating() {
        return like*1.0*100/(like + dislike);
    }

    float getDislikeRating() {
        return 100.0 - getLikeRating();
    }

    float getPositiveCommentRating() {
        float amountOfPositiveComment = 0;
        for (int i = 0; i < this->n; i++)
            if (comment[i] > 0) amountOfPositiveComment++;
        return amountOfPositiveComment*100.0/n;
    }

    float getNegativeCommentRating() {
        return 100.0 - getPositiveCommentRating();
    }
    
    float getGeneralRating() {
        return (getLikeRating() + getPositiveCommentRating())*100.0/200;
    }

    friend istream& operator >> (istream& in, Rating& rt) {
        in >> rt.like >> rt.dislike >> rt.n; 
        for (int i = 0; i < rt.n; i++)
            in >> rt.comment[i]; 
    }

    friend ostream& operator << (ostream& out, Rating rt) {
        out << fixed << setprecision(2)
        << rt.getLikeRating() << "%-" << rt.getDislikeRating() << "%-"
        << rt.getPositiveCommentRating() << "%-" << rt.getNegativeCommentRating() << "%-"
        << rt.getGeneralRating() << "%" << endl;
    }
};

int main() {
    int test; 
    cin >> test;

    while (test--) {
        Rating rt; 
        cin >> rt; 
        cout << rt;
    }

    return 0;
}