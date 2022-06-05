#include "Storage.h"

int ControlCommand2();
int Storage::count;

void menu(int* command)
{

    cout << "===============МЕНЮ===============" << endl;

    cout << "Доступные действия:" << endl;

    cout << "\t" << "1) Поиск товара по дате" << endl;
    cout << "\t" << "2) Сортировать по убыванию количества" << endl;
    cout << "\t" << "3) Поиск товара с датой больше, чем заданная" << endl;
    cout << "\t" << "4) Печать базы" << endl;
    cout << "\t" << "5) Добавить элемент" << endl;
    cout << "\t" << "6) Удалить элемент" << endl;
    cout << "\t" << "7) Завершение программы" << endl;

    cout << "==============================" << endl;

    cout << "Введите цифру от 1 до 7: " << endl;

    cout << "==============================" << endl << endl;

    *(command) = controlCommand();

}

int main() 
{
    setlocale(LC_ALL, "Russian");

    Storage element;
    Storage Massive;
    Date DateFor3thCase;
    int CountProductsWhatWeNeed=0;

    element.read_data();

    int command;

    do
    {

        menu(&command);
        switch (command)
        {

        case 1:
            element.case1_search();

            break;

        case 2:
            element.case2_sort();

            break;

        case 3:
            element.case3();

            break;

        case 4:
            element.show_data();

            break;

        case 5:
            element.add_element();

            break;

        case 6:
            element.delete_element();

            break;

        case 7:
            element.save_data();

            break;

        default:
            cout << "Неверно введен номер действия";

            break;

        }

    } while (command != 7);

    return 0;
}
