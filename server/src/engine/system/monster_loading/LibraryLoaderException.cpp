/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** LibraryLoaderException.cpp
*/

#include "LibraryLoaderException.hpp"

arc::LibraryLoaderException::LibraryLoaderException(const std::string &message) :
	std::runtime_error("SharedLibraryError : " + message)
{
}
