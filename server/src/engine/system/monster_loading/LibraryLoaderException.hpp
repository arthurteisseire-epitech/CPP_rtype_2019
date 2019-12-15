/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** LibraryLoaderException.hpp
*/

#ifndef ARCADE_LIBRARYLOADEREXCEPTION_HPP
#define ARCADE_LIBRARYLOADEREXCEPTION_HPP

#include <stdexcept>

namespace arc {
	class LibraryLoaderException : public std::runtime_error {
	public:
		explicit LibraryLoaderException(const std::string &message);
		~LibraryLoaderException() override = default;
	};
}

#endif
