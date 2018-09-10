#include <iostream>
#include <vector>

using namespace std;

int seats[20][5];

class Train {
private:
    int scanAvailableSeats(int qty) {
        for (int row = 0; row < 20; row++) {
            int counter = 0;
            for (int seat = 0; seat < 5; seat++) {
                if (seats[row][seat] == 0) {
                    counter += 1;
                }
                if (qty == counter) {
                    return row;
                }
            }
        }
        return -1;
    }

public:
    vector<int> arrangeSeat(int qty) {
        int suitableRow = scanAvailableSeats(qty);
        vector<int> bookSeats;
        int counter = 0;
        for (int seat = 0; seat < 5; seat++) {
            if (seats[suitableRow][seat] == 0) {
                seats[suitableRow][seat] = 1;
                int seatNumber = (suitableRow * 5) + seat + 1;
                bookSeats.push_back(seatNumber);
                counter += 1;
            }
            if (counter == qty) {
                return bookSeats;
            }
        }
        return bookSeats;
    }

};

int main() {
    int n, qty;
    Train t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> qty;
        vector<int> bookSeats = t.arrangeSeat(qty);
        for (int j = 0; j < bookSeats.size(); ++j) {
            cout << bookSeats[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
