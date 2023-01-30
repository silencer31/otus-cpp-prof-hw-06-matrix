#include "cell_value.h"

/**
* @brief Шаблонный класс, контролирующий получение или добавление элемента.
*/
template<typename T, int default_value = 0>
class CellHandler {
public:
    explicit CellHandler( Matrix<T, default_value>& mtx, int row ) :
        matrix(mtx),
        new_cell(CellValue<T, default_value>( mtx, default_value )),
        row_number_y(row)
    {}

    /**
    * Получаем доступ к ячейке при помощи оператора [].
    */
    CellValue<T, default_value>& operator[](int column)
    {
        auto it = matrix.find( std::make_pair(row_number_y, column) );

        if (it != matrix.end()) {
            it->second.set_row_and_column(row_number_y, column);
            return it->second;
        }
        else {
            new_cell.set_row_and_column(row_number_y, column);
            return new_cell;
        }
    }

private:
    Matrix<T, default_value>& matrix;
    CellValue<T, default_value> new_cell;
    int row_number_y{};
};