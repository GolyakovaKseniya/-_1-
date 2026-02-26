#pragma once

#include <iostream>
#include <string>
//FIX_ME: запрещено использовать using namespace std;
//using namespace std;

//FIX_ME: неинформативное название функции
//calc
//FIX_ME: неинформативное название переменной
//str
int CalculateExpression(std::string Expression);
//FIX_ME: неинформативное название функции
//element
//FIX_ME: неинформативное название переменной
//str
int ParseElement(const std::string& Expression);

//FIX_ME: неинформативное название функции
//term
//FIX_ME: неинформативное название переменной
//str
int ParseTerm(std::string Expression);

//FIX_ME: неинформативное название переменной
//str
int CalculateExpression(std::string Expression);

//FIX_ME: отсутствует проверка корректности выражения
bool IsValidateExpression(const std::string& Expression, std::string& ErrorMessage);