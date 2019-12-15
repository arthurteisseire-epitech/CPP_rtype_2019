/*
** EPITECH PROJECT, 2018
** r-type
** File description:
** LibraryLoaderException.cpp
*/

#include "LibraryLoaderException.hpp"

ecs::LibraryLoaderException::LibraryLoaderException(const std::string &message) :
	std::runtime_error("SharedLibraryError : " + message)
{
}
