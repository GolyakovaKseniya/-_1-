#include "Header.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//FIX_ME: неинформативные имена переменных
	//n, k
	int32_t DigitCount, NumberBase;
	std::cout << "Среди чисел в системе счисления с основанием K (2<=K<=10) определить " << std::endl;
	std::cout << "сколько имеется чисел из N(1<N<20, K + N<26) разрядов таких," << std::endl;
	std::cout << "что в их записи не содержится два и более подряд идущих нулей." << std::endl;
	std::cout << "Вам необходимо ввести  два числа - число разрядов и систему счисления." << std::endl;
	std::cout << "-------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	//FIX_ME: нет проверки на корректность ввода числа разрядов
	/*std::cout << "Введите число N - число разрядов в числе: ";
	std::cin >> digitCount;*/
	std::cout << "Введите число N - число разрядов в числе: ";
	if (!ReadIntFromConsole(DigitCount))
	{
		return 1;
	}

	//FIX_ME: нет проверки на корректность ввода числа системы счисления
	/*std::cout << "Введите число K - систему счисления: ";
	std::cin >> numberBase;*/
	std::cout << "Введите число K - систему счисления: ";
	if (!ReadIntFromConsole(NumberBase))
	{
		return 1;
	}

	//FIX_ME: ошибка в граничных значениях
	//if (numberBase < 2 || numberBase > 10 || digitCount < 1 || digitCount >= 20 || numberBase + digitCount >= 26)
	//FIX_ME: неправильное положение фигурной скобки после цикла
	//if () {
	if (!ValidateInput(DigitCount, NumberBase))
	{
		std::cout << "Некорректные входные данные!" << std::endl;
		return 1;
	}

	double totalValidNumbers = CountValidNumbers(DigitCount, NumberBase);

	//FIX_ME: отсутствует форматирование вывода вещественного числа
	//std::cout << "Количество чисел, в которых нет два и более подряд идущих нулей: " << totalValidNumbers << std::endl;
	std::cout << std::fixed << std::setprecision(0);
	std::cout << "Количество чисел, в которых нет два и более подряд идущих нулей: " << totalValidNumbers << std::endl;

	return 0;
}