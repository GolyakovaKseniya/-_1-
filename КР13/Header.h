#pragma once
//FIX_ME: лишние пробелы
//# include <iostream>
//# include <windows.h>
//# include <vector>
#include <iostream>
#include <windows.h>
#include <vector>
//FIX_ME: добавим библиотеку iomanip для setprecision
#include <iomanip>

//FIX_ME: запрещено использовать using namespace std
//using namespace std;

//FIX_ME: неинформативные имена переменных
//double nz, _nz, oz, _oz, tz, _tz;
double CountValidNumbers(int32_t DigitCount, int32_t NumberBase);

//FIX_ME: ошибка в граничных значениях
//if (numberBase < 2 || numberBase > 10 || digitCount < 1 || digitCount >= 20 || numberBase + digitCount >= 26)
bool ValidateInput(int32_t DigitCount, int32_t NumberBase);

//FIX_ME: нет проверки на корректность ввода числа разрядов
bool ReadIntFromConsole(int32_t& OutValue);