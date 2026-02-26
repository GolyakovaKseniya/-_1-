#include "Header.h"

double CountValidNumbers(int32_t DigitCount, int32_t NumberBase)
{
	// nz = числа в которых нет двух подряд идущих нулей и они не оканчиваются на 0
	// oz = числа в которых нет двух подряд идущих нулей и они оканчиваются на 0
	// tz = числа в которых есть два подряд идущих нуля
	// из числа класса nz может получиться число либо класса нз либо класса оз
	// из числа класса оз может получиться число либо класса нз либо класса тз
	// их числа класса тз может получиться число класса тз
	// nzn = nzn-1*(k-1) +oz(k-1); ozn = nzn-1; tzn = k*tzn-1+ozn-1;

	//FIX_ME: неинформативные имена переменных
	//double nz, _nz, oz, _oz, tz, _tz;
	double ValidNoEndZero, ValidEndZero, InvalidWithZeros;
	ValidNoEndZero = NumberBase - 1;
	//FIX_ME: неправильные начальные данные
	/*validEndZero = 1;*/
	ValidEndZero = 0;
	InvalidWithZeros = 0;
	double PreviousNoEndZero, PreviousEndZero, PreviousInvalid;

	//FIX_ME: использование переменной с плавающей точкой для счетчика цикла
	//for (i = 2; i <= n; i++)
	//FIX_ME: постфиксная запись ++
	//i++
	for (int i = 2; i <= DigitCount; ++i)
	{
		PreviousNoEndZero = ValidNoEndZero;
		PreviousEndZero = ValidEndZero;
		PreviousInvalid = InvalidWithZeros;

		ValidNoEndZero = PreviousNoEndZero * (NumberBase - 1) + PreviousEndZero * (NumberBase - 1);
		ValidEndZero = PreviousNoEndZero;
		InvalidWithZeros = PreviousInvalid * NumberBase + PreviousEndZero;
	}
	//FIX_ME: неинформативные имена переменных
	//result
	double TotalValidNumbers = ValidNoEndZero + ValidEndZero;

	return TotalValidNumbers;
}

//FIX_ME: ошибка в граничных значениях
//if (numberBase < 2 || numberBase > 10 || digitCount < 1 || digitCount >= 20 || numberBase + digitCount >= 26)
//FIX_ME: неправильное положение фигурной скобки после цикла
//if () {
bool ValidateInput(int32_t DigitCount, int32_t NumberBase)
{
	if (NumberBase < 2 || NumberBase > 10 || DigitCount <= 1 || DigitCount >= 20 || NumberBase + DigitCount >= 26)
	{
		return false;
	}
	return true;
}

//FIX_ME: отсутствует проверка на ввод целых чисел
bool ReadIntFromConsole(int32_t& OutValue)
{
	while (true)
	{
		// Пробуем прочитать число
		if (std::cin >> OutValue)
		{
			// Проверяем, что после числа нет лишних символов
			if (std::cin.peek() == '\n')
			{
				return true; // всё хорошо, выходим из цикла
			}
			else
			{
				std::cout << "Ошибка! После числа не должно быть лишних символов." << std::endl;
				// Очищаем буфер до конца строки
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}
		else
		{
			std::cout << "Ошибка! Необходимо ввести целое число." << std::endl;
			std::cin.clear(); // сбрасываем флаг ошибки
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // очищаем буфер
		}
	}
}