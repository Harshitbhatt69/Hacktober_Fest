// Simple implementation of 2d and 3d arrays 
// Using standard array for 3d is unreadable and c-like arrays don't let you use algorithms libraries. This is here to fix that problem 
// See below for example usage
// Mostly experimental. I will update this over time.
// While std::sort should be able to work it would have to be inside a loop for example. We can make our own std::sort for 2d and 3d arrays.
// I highly encourage you to add stuff too.
//
// TODO:
//    Remove the annoying requirement for having to specify std::array etc when initializing. Maybe a make_array2d and a make_array3d function etc people can use?
//    Add some sorting function.
//    Operator<< overload is for visibility only for now. Make an alternative function that returns std::ostream& instead so people can choose their own implementation of <<.
//    Add 4d arrays.
//    Whatever you find cool and relevant. Vectors, maps, algorithms, operators etc.
//    

// EXAMPLE USAGE.
/*
int main() {
	ARRD::array2d<int, 3, 4> foo{
		std::array<int, 4> //Don't put ','
		{1, 2, 3, 4},
		{2, 4, 6, 8},
		{3, 1, 4, 1}
	};

	ARRD::array3d<int, 2, 3, 4> goo{
		ARRD::array2d<int, 3, 4>
		{},
		{}
	};

	ARRD::array3d<int, 3, 3, 4> hoo{
		foo,
		goo[0],
		{}
	};

	std::cout << "Equivelent:\tint foo [3][4]:\n" << foo << '\n';
	std::cout << "Equivelent:\tint goo [2][3][4]:\n" << goo << '\n';
	std::cout << "Equivelent:\tint hoo [3][3][4]:\n" << hoo << '\n';

	return 0;
}  
*/
  
#ifndef ARRAY_D
#define ARRAY_D

#include <iostream>
#include <array>

namespace ARRD {
	template<typename T, std::size_t row_count, std::size_t col_count>
	using array2d = std::array< std::array<T, col_count>, row_count >;
	
	template<typename T, std::size_t depth
		, std::size_t row_count, std::size_t col_count>
	using array3d = std::array< array2d<T, row_count, col_count>, depth>;
}


template<typename T, std::size_t row_count, std::size_t col_count>
std::ostream& operator<<(std::ostream& os
	, const ARRD::array2d<T, row_count, col_count>& arr)
{
	for (auto row : arr) {
		for (T col : row) {
			os << col << ' ';
		}
		os << '\n';
	}
	return os << '\n';
}

template<typename T, std::size_t depth
	, std::size_t row_count, std::size_t col_count>
std::ostream& operator<<(std::ostream& os
	, const ARRD::array3d<T, depth, row_count, col_count>& arr)
{
	for (const auto& arr_2d : arr) {
		os << arr_2d;
	}
	return os;
}

#endif
