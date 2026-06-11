#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001); 

    char text[500];
    cout << "Enter text: ";
    cin.getline(text, 500);

    while (true) { //безкінечний цикл для повторного вибору дії
    system("cls"); //очищення консолі

        cout << "Text: " << text << "\n\n";
        cout << "Choose option:\n";
        cout << "1. Delete Latin letters\n";
        cout << "2. Delete Cyrillic letters\n";
        cout << "3. Delete punctuation\n";
        cout << "4. Delete digits\n";
        cout << "5. Show final result\n\n";
        cout << "Choose option 1-5: ";

        int choice;
        cin >> choice;

        if (choice == 5) {
            break;
        }

        for (int i = 0; text[i] != '\0'; i++) { //проходимо по кожному символу тексту
            unsigned char c = text[i]; //отримуємо ASCII код символу

            if (choice == 1 && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) { //видалення латиниці
                text[i] = ' '; //замінюємо на пробіл
            }
            else if (choice == 2 && ((c >= 192 && c <= 255) || c == 165 || c == 180 || c == 170 || c == 186 || c == 175 || c == 191 || c == 162 || c == 178)) { //видалення кирилиці
                text[i] = ' ';
            }
            else if (choice == 3 && ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))) { //видалення пунктуації
                text[i] = ' ';
            }
            else if (choice == 4 && (c >= '0' && c <= '9')) { //видалення цифр
                text[i] = ' ';
            }
        }
    }
    system("cls"); //очищення консолі перед показом результату
    cout << "Final result:\n" << text << "\n";

    return 0;
}
