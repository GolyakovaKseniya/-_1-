#include "Header.h"

//чтение с файла
//FIX_ME: неправильное положение фигурных скобок
//FIX_ME: непонятное название функции, параметры с маленькой буквы
//readfile,filename, line, cols
//FIX_ME: указан неточный размер
//int
std::vector<std::vector<int32_t>> ReadBoardFromFile(const std::string& Filename, int32_t& BoardSize)
{
    //FIX_ME: непонятное название переменной
    //input
    std::ifstream inputFile(Filename);

    //FIX_ME: не этично
    //std::cout << "Ошибка при открытии файла, не моя проблема" << std::endl;
    //FIX_ME: грубый exit вместо обработки ошибки
    //exit(1);
    if (!inputFile.is_open())
    {
        std::cout << "Ошибка при открытии файла" << std::endl;
        return {};
    }

    //FIX_ME: читает два числа, а нужно одно
    //input >> Rows >> Cols;
    inputFile >> BoardSize;

    //FIX_ME: нет проверки условия 1 < N < 80 и корректности ввода
    if (BoardSize <= 1 || BoardSize >= 80 || inputFile.fail())
    {
        std::cout << "Ошибка: размер доски должен быть 1 < N < 80" << std::endl;
        return {};
    }

    std::vector<std::vector<int32_t>> board(BoardSize, std::vector<int32_t>(BoardSize)); //собирает доску

    //FIX_ME: неправильный проход по доске
    //for (int32_t i = 0; i < Rows; i++) 
    //for (int32_t j = 0; j < Cols; j++) 
    //FIX_ME: постфиксный ++
    //i++
    for (int32_t Row = 0; Row < BoardSize; ++Row)
    {
        for (int32_t Cols = 0; Cols < BoardSize; ++Cols)
        {
            inputFile >> board[Row][Cols];

            //FIX_ME: нет проверки на корректность чтения числа в матрице
            if (inputFile.fail())
            {
                std::cout << "Ошибка чтения числа в строке " << Row + 1 << ", столбец " << Cols + 1 << ".\n";
                return {};
            }

            //FIX_ME: нет проверки на валидность числа 
            if (board[Row][Cols] < 0 || board[Row][Cols] > 100)
            {
                std::cout << "Число должно быть от 0 до 100. Ошибка в строке " << Row + 2 << ".\n";
                return {};
            }
        }
    }

    //FIX_ME: перед закрытием файла нет проверки на наличие в нем лишних данных 
    //inputFile.close();
    //return board;
    char extra;
    inputFile >> extra;
    if (!inputFile.fail())
    {
        std::cout << "Ошибка: в файле есть лишние данные после матрицы.\n";
        return {};
    }

    inputFile.close();
    return board;
}

// вывод с клавиатуры
//FIX_ME: непонятное название функции
//readkey
//FIX_ME: использует два числа, а нужно одно
//(int32_t& Rows, int32_t& Cols)
std::vector<std::vector<int32_t>> ReadBoardFromKeyboard(int32_t& BoardSize)
{
    std::cout << "Введите сколько будет строк и столбцов в поле для черепашки: ";
    std::cin >> BoardSize;

    //FIX_ME: нет проверки условия 1 < N < 80
    if (BoardSize <= 1 || BoardSize >= 80 || std::cin.fail())
    {
        std::cout << "Ошибка: размер доски должен быть 1 < N < 80" << std::endl;
        return {};
    }

    std::vector<std::vector<int32_t>> board(BoardSize, std::vector<int32_t>(BoardSize));
    std::cout << "Введите элементы поля (по строкам и через пробел):" << std::endl;

    //FIX_ME: непонятный комментарий
    // // собирает доску

    for (int32_t i = 0; i < BoardSize; ++i)
    {
        bool bRowValid = false;
        while (!bRowValid)
        {
            bRowValid = true;
            for (int32_t j = 0; j < BoardSize; ++j)
            {
                //FIX_ME: нет проверки корректности ввода целых чисел
                //std::cin >> board[i][j];
                std::cin >> board[i][j];

                if (std::cin.fail())
                {
                    std::cout << "\nОшибка! Нужно вводить только целые числа. Начните строку заново.\n";
                    std::cin.clear();
                    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                    bRowValid = false;
                    break;
                }
                else if (board[i][j] < 0 || board[i][j] > 100)
                {
                    std::cout << "\nЧисло должно быть от 0 до 100. Повторите ввод строки.\n";
                    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                    bRowValid = false;
                    break;
                }
            }
        }
    }
    return board;
}

// random заполнения доски
//FIX_ME: непонятное название функции
//random
//FIX_ME: использует два числа, а нужно одно
//(int32_t& Rows, int32_t& Cols)
std::vector<std::vector<int32_t>> GenerateRandomBoard(int32_t& BoardSize)
{

    std::cout << "Введите сколько будет строк и столбцов в поле для черепашки: ";
    std::cin >> BoardSize;

    //FIX_ME: нет проверки условия 1 < N < 80
    if (BoardSize <= 1 || BoardSize >= 80 || std::cin.fail())
    {
        std::cout << "Ошибка: размер доски должен быть 1 < N < 80" << std::endl;
        return{};
    }

    std::vector<std::vector<int32_t>> board(BoardSize, std::vector<int32_t>(BoardSize));
    std::srand(static_cast<unsigned int>(std::time(0))); //  генератор случайных чисел

    for (int32_t i = 0; i < BoardSize; ++i)
    { //заполнеине поля чудес
        for (int32_t j = 0; j < BoardSize; ++j)
        {
            board[i][j] = std::rand() % 101; // число от 0 до 100
        }
    }
    return board;
}

// макс сумм
//FIX_ME: непонятное название функции
//MaxSum
int32_t CalculateMaxSum(const std::vector<std::vector<int32_t>>& board, int32_t Rows, int32_t Cols)
{
    //FIX_ME: непонятное название
    //dp
    std::vector<std::vector<int32_t>> DynamicTable(Rows, std::vector<int32_t>(Cols, 0));

    DynamicTable[0][Cols - 1] = board[0][Cols - 1];//нач точка, правый верхний угол

    //FIX_ME: переместить --
    //j--
    for (int32_t j = Cols - 2; j >= 0; --j)
    {//первая строка, влево
        DynamicTable[0][j] = DynamicTable[0][j + 1] + board[0][j];
    }

    for (int32_t i = 1; i < Rows; ++i)
    {// первый столбец, вниз
        DynamicTable[i][Cols - 1] = DynamicTable[i - 1][Cols - 1] + board[i][Cols - 1];
    }

    for (int32_t i = 1; i < Rows; ++i)
    {// остальная таблица
        for (int32_t j = Cols - 2; j >= 0; --j)
        {
            DynamicTable[i][j] = board[i][j] + max(DynamicTable[i - 1][j], DynamicTable[i][j + 1]);
        }
    }

    return DynamicTable[Rows - 1][0];//макс сумм, левый нижний угол
}
