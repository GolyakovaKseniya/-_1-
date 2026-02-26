#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include <ctime>   
#include <Windows.h>
//FIX_ME: добавить для отчистки буфера 
#include <limits>
//FIX_ME: нельзя использовать using namespace std
//using namespace std;

//чтение с файла
//FIX_ME: неправильное положение фигурных скобок
//FIX_ME: непонятное название функции, параметры с маленькой буквы
//readfile,filename, line, cols
//FIX_ME: указан неточный размер
//int
std::vector<std::vector<int32_t>> ReadBoardFromFile(const std::string& Filename, int32_t& BoardSize);

// вывод с клавиатуры
//FIX_ME: непонятное название функции
//readkey
//FIX_ME: использует два числа, а нужно одно
//(int32_t& Rows, int32_t& Cols)
std::vector<std::vector<int32_t>> ReadBoardFromKeyboard(int32_t& BoardSize);

// random заполнения доски
//FIX_ME: непонятное название функции
//random
//FIX_ME: использует два числа, а нужно одно
//(int32_t& Rows, int32_t& Cols)
std::vector<std::vector<int32_t>> GenerateRandomBoard(int32_t& BoardSize);

// макс сумм
//FIX_ME: непонятное название функции
//MaxSum
int32_t CalculateMaxSum(const std::vector<std::vector<int32_t>>& board, int32_t Rows, int32_t Cols);