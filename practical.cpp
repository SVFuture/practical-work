#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char text[500];
    cout << "Введіть текст: ";
    cin.getline(text, 500);

    while (true) {
        system("cls");

        cout << "Поточний текст: " << text << "\n\n";
        cout << "Оберіть, що видалити з тексту:\n";
        cout << "1. Видалити латиницю\n";
        cout << "2. Видалити кирилицю\n";
        cout << "3. Видалити пунктуацію\n";
        cout << "4. Видалити цифри\n";
        cout << "5. Вийти з програми\n\n";
        cout << "Оберіть пункт (1-5): ";

        int choice;
        cin >> choice;

        if (choice == 5) {
            break;
        }

        for (int i = 0; text[i] != '\0'; i++) {
            unsigned char c = text[i];

            if (choice == 1 && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                text[i] = ' ';
            }
            else if (choice == 2 && ((c >= 192 && c <= 255) || c == 165 || c == 180 || c == 170 || c == 186 || c == 175 || c == 191 || c == 162 || c == 178)) {
                text[i] = ' ';
            }
            else if (choice == 3 && ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))) {
                text[i] = ' ';
            }
            else if (choice == 4 && (c >= '0' && c <= '9')) {
                text[i] = ' ';
            }
        }
    }

    system("cls");
    cout << "Фінальний результат:\n" << text << "\n";

    return 0;
}