#include "Header.h"

//FIX_ME: неинформативное название функции
//calc
//FIX_ME: неинформативное название переменной
//str
// FIX_ME: излишнее объявление функции
//int CalculateExpression(std::string expression);

//FIX_ME: неинформативное название функции
//element
//FIX_ME: неинформативное название переменной
//str
int ParseElement(const std::string& Expression)
{
	//FIX_ME: Работа с индексами без проверки границ
	//if (str[0] == '(' && str[str.size() - 1] == ')')
	//FIX_ME: отсутствуют фигурные скобки при цикле for
	if (Expression.front() == '(' && Expression.back() == ')')
	{
		return CalculateExpression(Expression.substr(1, Expression.length() - 2));
	}

	//FIX_ME: нет проверки на пустоту
	if (Expression.empty())
	{
		return 0;
	}

	//FIX_ME: Использование stoi без обработки исключений
	//return stoi(expression);
	try
	{
		return std::stoi(Expression);
	}
	catch (const std::exception&)
	{
		// Если не удалось преобразовать в число, возвращаем 0
		return 0;
	}
}

//FIX_ME: неинформативное название функции
//term
//FIX_ME: неинформативное название переменной
//str
int ParseTerm(std::string Expression)
{
	int Level = 0;
	//FIX_ME: неинформативное название переменной
	//int pos = -1;
	int MultiplicationPos = -1;

	//FIX_ME: Поиск операции умножения без учета приоритета скобок
	//FIX_ME: постфксная запись ++
	//i++
	//FIX_ME: отсутствуют фигурные скобки при цикле for
	/*while (i >= 0)
	{
		if (expression[i] == ')')
			level++;
		if (expression[i] == '(')
			level--;
		if (level == 0 && expression[i] == '*')
		{
			multiplicationPos = i;
			break;
		}
		i--;
	}*/
	// Ищем последнюю операцию умножения вне скобок
	for (int i = static_cast<int>(Expression.length()) - 1; i >= 0; --i)
	{
		if (Expression[i] == ')')
		{
			++Level;
		}
		else if (Expression[i] == '(')
		{
			--Level;
		}
		else if (Level == 0 && Expression[i] == '*')
		{
			MultiplicationPos = i;
			break;
		}
	}
	//FIX_ME: отсутствуют фигурные скобки при цикле for
	/*if (multiplicationPos == -1)
		return ParseElement(expression);*/
	if (MultiplicationPos == -1)
	{
		return ParseElement(Expression);
	}
	return ParseTerm(Expression.substr(0, MultiplicationPos)) * ParseElement(Expression.substr(MultiplicationPos + 1));
}

//FIX_ME: неинформативное название переменной
//str
int CalculateExpression(std::string Expression)
{
	/*int i = expression.size() - 1;*/
	int Level = 0;
	//FIX_ME: неинформативное название переменной
	//int pos = -1;
	int OperationPos = -1;

	//FIX_ME: Поиск операции умножения без учета приоритета скобок
	/*while (i >= 0)
	{
		if (expression[i] == ')')
			level++;
		if (expression[i] == '(')
			level--;
		if (level == 0 && (expression[i] == '-' || expression[i] == '+'))
		{
			operationPos = i;
			break;
		}
		i--;
	}*/
	for (int i = static_cast<int>(Expression.length()) - 1; i >= 0; --i)
	{
		if (Expression[i] == ')')
		{
			++Level;
		}
		else if (Expression[i] == '(')
		{
			--Level;
		}
		else if (Level == 0 && (Expression[i] == '-' || Expression[i] == '+'))
		{
			OperationPos = i;
			break;
		}
	}

	//FIX_ME: отсутствуют фигурные скобки при цикле for
	/*if (operationPos == -1)
		return ParseTerm(expression);*/
	if (OperationPos == -1)
	{
		return ParseTerm(Expression);
	}
	//FIX_ME: неинформативное название переменной
	//FIX_ME: Прямое использование индекса без проверки
	//char ch = expression[operationPos];
	char Operation = Expression[OperationPos];
	std::string LeftPart = Expression.substr(0, OperationPos);
	std::string RightPart = Expression.substr(OperationPos + 1);

	//FIX_ME: отсутствуют фигурные скобки при цикле for
	//FIX_ME: Необработанные случаи операций
	/*if (operation == '+')
		return CalculateExpression(expression.substr(0, operationPos)) + ParseTerm(expression.substr(operationPos + 1));
	if (operation == '-')
		return CalculateExpression(expression.substr(0, operationPos)) - ParseTerm(expression.substr(operationPos + 1));*/
	if (Operation == '+')
	{
		return CalculateExpression(LeftPart) + ParseTerm(RightPart);
	}
	else if (Operation == '-')
	{
		return CalculateExpression(LeftPart) - ParseTerm(RightPart);
	}

	return 0;
}

//FIX_ME: отсутствует проверка корректности выражения
bool IsValidateExpression(const std::string& Expression, std::string& ErrorMessage)
{
	// Проверка на пустую строку
	if (Expression.empty())
	{
		ErrorMessage = "Ошибка! Выражение не может быть пустым.";
		return false;
	}

	// Проверка на недопустимые символы
	for (char Character : Expression)
	{
		if (!isdigit(Character) && Character != '+' && Character != '-' && Character != '*' && Character != '(' && Character != ')')
		{
			ErrorMessage = "Ошибка! Выражение содержит недопустимый символ: '";
			ErrorMessage += Character;
			return false;
		}
	}

	// Проверка на пустые скобки
	if (Expression.find("()") != std::string::npos)
	{
		ErrorMessage = "Ошибка! Обнаружены пустые скобки '()'.";
		return false;
	}

	// Проверка на два оператора подряд
	for (size_t i = 0; i < Expression.length() - 1; ++i)
	{
		char Current = Expression[i];
		char Next = Expression[i + 1];

		bool bCurrentIsOperator = (Current == '+' || Current == '-' || Current == '*');
		bool bNextIsOperator = (Next == '+' || Next == '-' || Next == '*');

		// Два оператора подряд - ошибка
		if (bCurrentIsOperator && bNextIsOperator)
		{
			ErrorMessage = "Ошибка! Два оператора подряд: '";
			ErrorMessage += Current;
			ErrorMessage += Next;
			ErrorMessage += "'.";
			return false;
		}

		// Специальная проверка для умножения после скобки
		if (Current == '(' && Next == '*')
		{
			ErrorMessage = "Ошибка! Умножение не может стоять после открывающей скобки.";
			return false;
		}

		// Специальная проверка для умножения перед скобкой
		if (Current == '*' && Next == ')')
		{
			ErrorMessage = "Ошибка! Умножение не может стоять перед закрывающей скобкой.";
			return false;
		}
	}

	// Проверка первого символа
	char FirstChar = Expression.front();
	if (FirstChar == '*' || FirstChar == '+' || FirstChar == ')' || FirstChar == '-')
	{
		ErrorMessage = "Ошибка! Выражение не может начинаться с ";
		ErrorMessage += FirstChar;
		return false;
	}

	// Проверка последнего символа
	char LastChar = Expression.back();
	if (LastChar == '+' || LastChar == '-' || LastChar == '*' || LastChar == '(')
	{
		ErrorMessage = "Ошибка! Выражение не может заканчиваться на ";
		ErrorMessage += LastChar;
		return false;
	}

	// Проверка баланса скобок
	int Balance = 0;
	for (char Character : Expression)
	{
		if (Character == '(')
		{
			++Balance;
		}
		else if (Character == ')')
		{
			--Balance;
		}

		if (Balance < 0)
		{
			ErrorMessage = "Ошибка! Неправильный порядок скобок: закрывающая скобка без открывающей.";
			return false;
		}
	}

	if (Balance != 0)
	{
		ErrorMessage = "Ошибка! Несбалансированные скобки. Количество '(' != ')'. Открыто: " + std::to_string(Balance) + " скобок.";
		return false;
	}

	return true;
}