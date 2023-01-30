#pragma once

/**
* @brief Ўаблонный класс, представл€ющий из себ€ одну €чейку матрицы с еЄ значением.
*/
template<typename T, int default_value = 0>
class CellValue {
public:
	explicit CellValue(Matrix<T, default_value>& mtx, int value) :
		matrix(mtx), cell_value(value) 
	{}

    /**
    * @return ѕолучить значение €чейки.
    */
	T get_value() {
		return cell_value;
	}

    /**
    * ”становка номер строки и столбца.
    */
    void set_row_and_column(int row, int column) {
        row_number_y = row;
        col_number_x = column;
    }

    auto operator=(int const& value) {
        coordinates position = std::make_pair(row_number_y, col_number_x);

        if (value == default_value) {
            auto it = matrix.find(position);

            if (it != matrix.end()) {
                matrix.erase(it);
            }
        }
        else {
            matrix.insert(position, CellValue(matrix, value));
        }

        return nullptr;
    }

    friend bool operator==(CellValue<T, default_value>& lhs, T const& rhs) {
        return lhs.get_value() == rhs;
    }

    friend std::ostream& operator<<(std::ostream& os, CellValue<T, default_value> const& obj) {
        os << ((obj.cell_value == default_value) ? default_value : obj.cell_value);
        return os;
    }

private:
    int row_number_y{};
    int col_number_x{};
	
		
	Matrix<T, default_value>& matrix;
    T cell_value = default_value;
};