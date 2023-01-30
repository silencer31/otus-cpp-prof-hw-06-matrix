#pragma once

template<typename, int>
class Matrix;

#include <map>
#include <tuple>
#include <algorithm>

using coordinates = std::pair<int, int>;

#include "cell_handler.h"

/**
* @brief Шаблонный класс, представляющий из себя бесконечную разреженную матрицу.
*/
template<typename T, int default_value = 0>
class Matrix {
private:
	std::map<coordinates, CellValue<T, default_value>> matrix_array; // коллекция с присвоенными значениями.

	using matrix_iterator = typename std::map<coordinates, CellValue<T, default_value>>::iterator;

public:
	Matrix() = default;
	~Matrix() = default;

	/**
	* Перегрузка оператора [].
	*/
	CellHandler<T, default_value> operator[](int row)
	{
		return CellHandler<T, default_value>(*this, row);
	}

	/**
	* @return Получить все присвоенные значения.
	*/
	std::map<coordinates, CellValue<T, default_value>>& get_matrix_values() {
		return matrix_array;
	}

	/**
	* @return Итератор на первую занятую ячейку.
	*/
	matrix_iterator begin() {
		return matrix_array.begin();
	}

	/**
	* @return Итератор на конец коллекции.
	*/
	matrix_iterator end() {
		return matrix_array.end();
	}

	/**
	* @return Итератор на элемент с заданной позицией.
	*/
	matrix_iterator find( const coordinates& position ) {
		return matrix_array.find(position);
	}

	/**
	* Удаление элемента.
	*/
	matrix_iterator erase(const matrix_iterator& m_iter) {
		return matrix_array.erase(m_iter);
	}

	/**
	* Вставка элемента.
	*/
	auto insert(const coordinates& position, const CellValue<T, default_value>& cell_value) {
		return matrix_array.insert( std::make_pair(position, cell_value) );
	}

	/**
	* @return Получить количество присвоенных значений/занятых ячеек.
	*/
	std::size_t size() {
		return matrix_array.size();
	}

	/**
	* @return Кортеж, содержащий координаты и значение ячейки.
	*/
	static auto make_tuple(std::pair<coordinates, CellValue<T, default_value>> it) {
		return std::make_tuple(it.first.first, it.first.second, it.second.get_value());
	}
};