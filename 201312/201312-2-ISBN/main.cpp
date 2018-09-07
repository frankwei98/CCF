#include <iostream>

using namespace std;

int charToNumber(char c)
{
    return (c - '0') % 48;
}

class ISBN
{
  public:
    ISBN(string isbn)
    {
        total = 0;
        _isbn = isbn;
        int addIndex = 0;
        for (int i = 0; i < 11; i++)
        {
            if (i == 1 || i == 5)
            {
                continue;
            }
            total += charToNumber(isbn[i]) * (1 + addIndex);
            addIndex++;
        }
    };

    void check(string isbn)
    {
        bool b = verify(isbn);
        if (b)
        {
            cout << "Right" << endl;
        }
        else
        {
            if (total % 11 == 10)
            {
                cout << _isbn.substr(0, 12) << 'X' << endl;
            }
            else
            {
                cout << _isbn.substr(0, 12) << total % 11 << endl;
            }
        }
    }

  private:
    int total;
    string _isbn;
    bool verify(string isbn)
    {
        char c = isbn[12];
        if (c == 'X')
        {
            return total % 11 == 10;
        }
        else
        {
            return total % 11 == charToNumber(c);
        }
    }
};

int main()
{
    string isbn;
    cin >> isbn;
    ISBN isbnObj(isbn);
    isbnObj.check(isbn);
    return 0;
}