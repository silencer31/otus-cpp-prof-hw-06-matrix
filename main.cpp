#include <iostream>
#include <cassert>

#include "matrix.h"

int main(int, char const**)
{
    int const def_value = 0;
    
    Matrix<int, def_value> matrix;
    assert(matrix.size() == 0);

    auto a = matrix[0][0];
    assert(a == -1);
    assert(matrix.size() == 0);
    
    matrix[100][100] = 314;
    assert(matrix[100][100] == 314);
    assert(matrix.size() == 1);
   
    // выведется одна строка
    // 100100314
    int x;
    int y;
    int v;

    for (auto &cell : matrix)
    { 
         //std::tie(x, y, v) = c;
        std::tie(x, y, v) = Matrix<int, def_value>::make_tuple(cell);

        std::cout << x << y << v << std::endl;
    }
    
    std::cout << std::endl;
       

    // Заполняем главную диагональ значениями от 0 до 9 и второстепенную диагональ значениями от 9 до 0.
    for (x = 0; x < 10; ++x) {
        matrix[x][x] = x;
        matrix[x][9 - x] = 9 - x;
    }

    // Вывод фрагмента матрицы от [1,1] до [8,8].
    for (x = 1; x < 9; ++x) {
        for (y = 1; y < 9; ++y) {
            std::cout << ' ' << matrix[x][y];
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    // Вывод количества занятых ячеек.
    // Будет не 18, а 19, т.к. выше есть присвоение matrix[100][100] = 314
    std::cout << "matrix non-default values number: " << matrix.size() << std::endl;
    std::cout << std::endl;

    // Вывод всех занятых ячеек вместе со своими позициями
    for (auto& cell : matrix)
    {
        //std::tie(x, y, v) = c;
        std::tie(x, y, v) = Matrix<int, def_value>::make_tuple(cell);

        std::cout << '[' << x << "][" << y << ']' << " = " << v << std::endl;
    }


    return 0;
}