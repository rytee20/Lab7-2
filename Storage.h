#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef KK_HEADER_H
#define KK_HEADER_H

#include <iostream>
#include <fstream>
//#include <sstream>
#include <string>
#include <locale>
#include <list>
#include <vector>
#include <algorithm>
#include "Date.h"

using namespace std;

int controlCommand();

class Storage
{
    friend class Compare_down;

private:

    string name;
    double cost;
    int amount;
    int sectionnumber;

public:

    static int count;
    Date arriveddate;
    list<Storage> Array;

    Storage& operator=(const Storage& equal);
    friend bool operator>(Storage& Obj, Date& fdate);
    friend istream& operator>> (istream& in, Storage& equal);

    string GetName();
    double GetCost();
    int GetAmount();
    int GetSectionnumber();

    void SetName(string new_name);
    void SetCost(double new_cost);
    void SetAmount(int new_amount);
    void SetSectionnumber(int new_sectionnumber);

    int ControlPlase();
    void add_element();
    void delete_element();
    void show_data();
    void read_data();
    void save_data();
    void case1_search();
    void case2_sort();
    void case3();

    //friend void SearchProductBySection(Storage* Obj, int fcount);
    //friend void SortByAmountDescending(Storage* Obj, int fcount);
    //friend int CountFor3thCase(Storage* Obj1, Date& fdate, int fcount);
    //friend void For3thCase(Storage* Obj1, Storage*& Obj2, Date& fdate, int fcount);

    //friend void PrintBase(Storage* Obj, int fcount);
    //friend void SaveBase(Storage* Obj, int fcount);
    //friend void СreateBase(Storage* Obj, int fcount);
    //friend void ReadBase(Storage*& Obj, int fcount);

    //void add_data(); // пережиток 4ой лабы

    Storage();
   // ~Storage();
};

#endif KK_HEADER_H
