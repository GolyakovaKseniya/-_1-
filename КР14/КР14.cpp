#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	//FIX_ME: неинформативное название переменной
	//str
	std::string InputExpression;

	bool bValidInput = false;

	while (!bValidInput)
	{
		//FIX_ME: Использование getline без проверки на ошибки ввода
		//getline(cin, str);
		std::cout << "Введите выражение: ";
		std::getline(std::cin, InputExpression);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка ввода! Попробуйте снова." << std::endl;
			continue;
		}
		std::string CleanInput;

		//FIX_ME: нет проверки на отсутствие скобок в выражении
		for (char Character : InputExpression)
		{
			if (!std::isspace(static_cast<unsigned char>(Character)))
			{
				CleanInput += Character;
			}
		}

		//FIX_ME: нет проверки на пустоту
		if (CleanInput.empty())
		{
			std::cout << "Ошибка! Выражение не может быть пустым. Попробуйте снова." << std::endl;
			continue;
		}

		//FIX_ME: Проверка на слишком длинное выражение
		if (CleanInput.length() > 100)
		{
			std::cout << "Ошибка! Выражение слишком длинное (максимум 100 символов). Попробуйте снова." << std::endl;
			continue;
		}

		//FIX_ME: Проверка корректности выражения
		std::string ErrorMessage;
		if (!IsValidateExpression(CleanInput, ErrorMessage))
		{
			std::cout << ErrorMessage << " Попробуйте снова." << std::endl;
			continue;
		}

		// Ввод корректен
		InputExpression = CleanInput;
		bValidInput = true;
	}

	try
	{
		//FIX_ME: неинформативное название переменной
		//int r = CalculateExpression(expression);
		int Result = CalculateExpression(InputExpression);

		std::cout << "Ответ: " << Result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Ошибка при вычислении: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}