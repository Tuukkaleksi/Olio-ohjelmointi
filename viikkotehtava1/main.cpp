#include <iostream>

using namespace std;

int game(int maxnum) {
    srand(time(NULL));
    int satluku = rand() % maxnum + 1;

    int arvaus = -1;
    int yritykset = 0;

    while (arvaus != satluku) {
        cout << "Arvauksesi? ";
        cin >> arvaus;

        if (arvaus < satluku) {
            cout << "Arvauksesi oli liian pieni" << endl;
        } else if (arvaus > satluku) {
            cout << "Arvauksesi oli liian suuri" << endl;
        } else {
            cout << "Arvasit oikein!" << endl;
            cout << "Oikea luku oli: " << satluku << endl;
        }
        yritykset++;
    }
    return yritykset;
}

int main()
{
    int maxnum;
    cout << "Anna korkein mahdollinen numero: ";
    cin >> maxnum;

    int yritykset = game(maxnum);

    cout << "Yritit " << yritykset << " kertaa" << endl;
    return 0;
}
