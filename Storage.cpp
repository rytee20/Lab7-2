#include "Storage.h"
#include "Compare_down.h"

double ControlCost();
char* ControlName();
int ControlAmount();
int ControlSection();
int ControlMounth();
int ControlYear();
int ControlDay(int fyear, int fmounth);
int ControlCommand2();

Storage& Storage::operator=(const Storage& equal)
{
    name = equal.name;
    cost = equal.cost;
    amount = equal.amount;
    sectionnumber = equal.sectionnumber;
    arriveddate.day = equal.arriveddate.day;
    arriveddate.mounth = equal.arriveddate.mounth;
    arriveddate.year = equal.arriveddate.year;
    return *this;
}
bool operator>(Storage& Obj, Date& fdate)
{
    if ((fdate.year < Obj.arriveddate.year) || (fdate.year == Obj.arriveddate.year && fdate.mounth < Obj.arriveddate.mounth) || (fdate.year == Obj.arriveddate.year && fdate.mounth == Obj.arriveddate.mounth && fdate.day < Obj.arriveddate.day))
        return 1;
    else
        return 0;
}
istream& operator>> (istream& in, Storage& equal)
{
    char* tmpname = new char[50];
    bool not_ok = true;
    //cout << "Введите название товара: ";
    while (not_ok) {
        try
        {
            tmpname = ControlName();
            equal.SetName(tmpname);
            not_ok = false;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Ошибка: " << ex.what() << std::endl;
            not_ok = true;
        }
    }

    double tmpcost;
    not_ok = true;
    while (not_ok)
    {
        try
        {
            tmpcost = ControlCost();
            equal.SetCost(tmpcost);
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.SetAmount(ControlAmount());
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.SetSectionnumber(ControlSection());
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.arriveddate.year = ControlYear();
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.arriveddate.mounth = ControlMounth();
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.arriveddate.day = ControlDay(equal.arriveddate.year, equal.arriveddate.mounth);
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    return in;
}

string Storage::GetName() { return name; }
double Storage::GetCost() { return cost; }
int Storage::GetAmount() { return amount; }
int Storage::GetSectionnumber() { return sectionnumber; }

void Storage::SetName(string new_name)
{
    name = new_name;
    //strcpy(name, new_name);
};
void Storage::SetCost(double new_cost) {
    cost = new_cost;
}
void Storage::SetAmount(int new_amount) {
    amount = new_amount;
}
void Storage::SetSectionnumber(int new_sectionnumber) {
    sectionnumber = new_sectionnumber;
}

int Storage::ControlPlase()
{
    int control;
    while (true)
    {
        cout << "доступны места от [1," << Array.size() << "]: ";
        cin >> control;
        if (cin.fail() or (control > Array.size() + 1))
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
        {
            return control;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
    return control;
}
void Storage::show_data()
{
    cout << endl << "НАЗВАНИЕ" << "\t\t" << "ЦЕНА" << "\t\t" << "КОЛИЧЕСТВО" << "\t\t" << "СЕКЦИЯ" << "\t\t" << "ДАТА"<< endl;

    for (auto& i : Array)
    {
        cout << i.name << "\t\t" << i.cost << "\t\t" << i.amount << "\t\t" << i.sectionnumber << "\t\t" << i.arriveddate.day << "." << i.arriveddate.mounth << "." << i.arriveddate.year << endl;
    }
    cout << endl;
}
void Storage::add_element()
{
    cout << endl << "Введите место, на которое хотяте поставить товар, ";
    int choise = ControlCommand2();
    Storage tmpStorage;
    cin >> tmpStorage;
    if (choise==1)
    {
        Array.push_front(tmpStorage);
    }
    else if (choise == 2)
    {
        Array.push_back(tmpStorage);
    }
    else
    {
        int plase;
        plase = ControlPlase();

        auto it = Array.begin();
        advance(it, plase - 1);
        Array.insert(it, tmpStorage);
    }
    cout << endl << "Элемент добавлен" << endl << endl;
}
void Storage::delete_element()
{
    cout << endl << "Введите место, с которого надо удалить товар, ";
    int plase = ControlPlase();
    auto it = Array.begin();
    advance(it, plase-1);
    Array.erase(it);
    count--;
    cout << endl << "Элемент удален" << endl << endl;
}
void Storage::read_data()
{
    ifstream fin;
    fin.open("Base.txt");
    Storage tmpStorage;

    if (!fin.is_open()) cout << endl << "Не удается открыть файл" << endl << endl; //если с файлом плохо
    else
    {
        if (fin.peek() == EOF) cout << endl << "Файл пуст" << endl << endl; //файл пуст или его нет
        else // иначе все хорошо и мы считываем
        {
            fin.close();
            fin.open("Base.txt");

            string fname;
            int fday;
            int fmounth;
            int fyear;
            double fcost;
            int famount;
            int fsectionnumber;

            fin >> count;

            for (int i = 0; i < count; i++)
            {
                fin >> fname >> fcost >> famount >> fsectionnumber >> fday >> fmounth >> fyear;

                this->name = fname;
                this->cost=fcost;
                this->amount = famount;
                this->sectionnumber = fsectionnumber;
                this->arriveddate.day = fday;
                this->arriveddate.mounth = fmounth;
                this->arriveddate.year = fyear;

                Array.push_back(*this);
            }
        }
    }
    cout << endl << "Считано " << count << " объектов из файла" << endl << endl;

    fin.close();
}
void Storage::save_data()
{
    ofstream record("Base.txt", ios::out);

    if (record)
    {
        record << count << endl;
        for (auto&i:Array)
        {
            record << i.name << " " << i.cost << " " << i.amount << " " << i.sectionnumber << " " << i.arriveddate.day << " " << i.arriveddate.mounth << " " << i.arriveddate.year << endl;

        }
        cout << endl << "База сохранена" << endl << endl;
        //record << StorageBase[count - 1].name << " " << StockBase[count - 1].GetAmount() << " " << StorageBase[count - 1].GetCost() << " " << StockBase[count - 1].GetSectionnumber() << " " << StockBase[count - 1].arriveddate.day << " " << StockBase[count - 1].arriveddate.mounth << " " << StockBase[count - 1].arriveddate.year;
    }
    else
    {
        cout << "ОШИБКА ЗАПИСИ ДАННЫХ НА ДИСК" << endl << endl;
    }
    record.close();
}
void Storage::case1_search()
{
    int fday, fmounth, fyear, i = 0, fcount = 0;
    fyear = ControlYear();
    fmounth = ControlMounth();
    fday = ControlDay(fyear,fmounth);

    cout << endl << "Товары с заданной датой " << endl << "НАЗВАНИЕ" << "\t\t" << "ЦЕНА" << "\t\t" << "КОЛИЧЕСТВО" << "\t\t" << "СЕКЦИЯ" << "\t\t" << "ДАТА" << endl;

    for (auto& i : Array)
    {
        if (i.arriveddate.day == fday and i.arriveddate.mounth == fmounth and i.arriveddate.year == fyear)
        {
            cout << i.name << "\t\t" << i.cost << "\t\t" << i.amount << "\t\t" << i.sectionnumber << "\t\t" << i.arriveddate.day << "." << i.arriveddate.mounth << "." << i.arriveddate.year << endl;
            fcount++;
        }
    }

    if (fcount == 0) cout << endl << "Не найдено товаров с заданной датой" << endl;
    cout << endl;
}
void Storage::case2_sort()
{
    std::vector<Storage>tmp;
    for (auto& i : Array)
    {
        tmp.push_back(i);
    }
    sort(tmp.begin(), tmp.end(), Compare_down());
    count--;
    cout << endl << "Отсортированный массив: " << endl;
    cout << "НАЗВАНИЕ" << "\t\t" << "ЦЕНА" << "\t\t" << "КОЛИЧЕСТВО" << "\t\t" << "СЕКЦИЯ" << "\t\t" << "ДАТА" << endl;

    for (auto& i : tmp)
    {
        cout << i.name << "\t\t" << i.cost << "\t\t" << i.amount << "\t\t" << i.sectionnumber << "\t\t" << i.arriveddate.day << "." << i.arriveddate.mounth << "." << i.arriveddate.year << endl;
    }
    cout << endl;
}
void Storage::case3()
{
    Date fdate;
    int fcount = 0;
    cout << endl << "Введите дату:" << endl;
    cin >> fdate;

    cout << endl << "Товары с датой поставки больше, чем заданная:" << endl << "НАЗВАНИЕ" << "\t\t" << "ЦЕНА" << "\t\t" << "КОЛИЧЕСТВО" << "\t\t" << "СЕКЦИЯ" << "\t\t" << "ДАТА" << endl;

    for (auto& i : Array)
    {
        if (i > fdate)
        {
            cout << i.name << "\t\t" << i.cost << "\t\t" << i.amount << "\t\t" << i.sectionnumber << "\t\t" << i.arriveddate.day << "." << i.arriveddate.mounth << "." << i.arriveddate.year << endl;
            fcount++;
        }
    }

    if (fcount == 0) cout << "Не найдено товаров в заданной секции" << endl;
    cout << endl;
}

Storage::Storage()
{
    name = "mane";
    cost = 0.0;
    amount = 0;
    sectionnumber = 0;
    count++;
}
//Storage::~Storage() {
//    delete[] name;
//    //delete[] cost;
//    //delete[] amount;
//    //delete[] sectionnamber;
//    cout << "Почистилос" << endl;
//}
