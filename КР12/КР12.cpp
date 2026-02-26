#include "Header.h"

int main()
{
    int32_t Choice;
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    //FIX_ME: нет возможности дать пользователю ввести данные еще раз при возникновении ошибки ввода
    while (true)
    {
        std::cout << "Выберите способ ввода данных, только 1:" << std::endl;
        std::cout << "1. Прочитать из файла" << std::endl;
        std::cout << "2. Ввести с клавиатуры" << std::endl;
        std::cout << "3. Заполнить random числами" << std::endl;
        std::cout << "4. Выйти из программы" << std::endl;

        std::cout << "Какой choise вы делаете? : ";
        //FIX_ME: нет проверки на корректность введенного числа
        //std::cin >> choice;
        std::cin >> Choice;
        if (std::cin.fail())
        {
            std::cout << "Ошибка: число должно быть от 1 до 4" << std::endl;
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            continue;
        }
        if (Choice > 4 || Choice < 1)
        {
            std::cout << "Ошибка: число должно быть от 1 до 4" << std::endl;
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            continue;
        }
        //FIX_ME: используются две переменные вместо одной
        //int rows, cols
        int32_t Rows = 0;
        int32_t Cols = 0;
        int32_t Size = 0;
        std::vector<std::vector<int32_t>> Board;

        //FIX_ME: нет проверки на пустоту доски
       /* rows = size;
        cols = size;
        break;*/
        switch (Choice)
        {
        case 1:
        {
            std::string Filename = "file.txt";

            Board = ReadBoardFromFile(Filename, Size);
            if (Board.empty())
            {
                std::cout << "Ошибка загрузки файла. Попробуйте другой способ.\n";
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                return 1;
            }
            Rows = Size;
            Cols = Size;
            break;
        }
        case 2:
        {
            Board = ReadBoardFromKeyboard(Size);
            if (Board.empty())
            {
                std::cout << "Ошибка загрузки файла. Попробуйте другой способ.\n";
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                return 1;
            }
            Rows = Size;
            Cols = Size;
            break;
        }
        case 3:
        {
            Board = GenerateRandomBoard(Size);
            if (Board.empty())
            {
                std::cout << "Ошибка загрузки файла. Попробуйте другой способ.\n";
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                return 1;
            }
            Rows = Size;
            Cols = Size;
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            std::cout << "Упс, попробуйте еще раз!" << std::endl;
            continue;
        }
        }

        std::cout << "ПОЛЕ ЧУДЕС:" << std::endl;

        for (int32_t i = 0; i < Rows; ++i)
        {
            for (int32_t j = 0; j < Cols; ++j)
            {
                std::cout << Board[i][j] << " ";
            }
            std::cout << std::endl;
        }

        int32_t MaximumSum = CalculateMaxSum(Board, Rows, Cols);

        std::cout << "Turtle собрала максимальную сумму: " << MaximumSum << std::endl;

        //FIX_ME: непонятное название переменной
        //output
        std::ofstream OutputFile("vivod.txt");
        //FIX_ME: неправильный ввод в файл
        /*output << maxSum;
        output.close();
        std::cout << "Результат записан в файл vivod.txt но также показан выше" << std::endl;*/

        if (OutputFile.is_open())
        {
            OutputFile << MaximumSum;
            OutputFile.close();
            std::cout << "Результат записан в файл vivod.txt" << std::endl;
        }
        else
        {
            std::cout << "Ошибка при записи в файл" << std::endl;
        }
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        std::cout << std::endl;
    }
    return 0;
}