#pragma once

// swap:
// Swaps the values of two given arguments. Does not return anything.
template <typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

// min:
// Compares the two values passed in its arguments and returns the smallest one.
// If the two of them are equal, then it returns the second one.
template <typename T>
const T &min(const T &a, const T &b) {
	if (a < b) {
		return a;
	}
	return b;
}

// template <typename T>
// T &min(T &a, T &b) {
// 	if (a <= b) {
// 		return a;
// 	}
// 	return b;
// }

// max:
// Compares the two values passed in its arguments and returns the greatest one.
// If the two of them are equal, then it returns the second one.
template <typename T>
const T &max(const T &a, const T &b) {
	if (a <= b) {
		return b;
	}
	return a;
}

// template <typename T>
// T &max(T &a, T &b) {
// 	if (a <= b) {
// 		return b;
// 	}
// 	return a;
// }
