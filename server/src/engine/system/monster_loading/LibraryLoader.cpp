/*
** EPITECH PROJECT, 2018
** r-type
** File description:
** LibraryLoader.cpp
*/

#include <sys/stat.h>
#include "LibraryLoader.hpp"
#include "LibraryLoaderException.hpp"

ecs::LibraryLoader::LibraryLoader() :
	_lib(nullptr)
{
}

ecs::LibraryLoader::~LibraryLoader()
{
	if (_lib)
		dlclose(_lib);
}

bool ecs::LibraryLoader::isFile(const std::string &name) const
{
	struct stat buffer{};

	return (stat(name.c_str(), &buffer) == 0);
}

void ecs::LibraryLoader::load(const std::string &libname)
{
	if (_lib)
		dlclose(_lib);
	if (!isFile(libname))
		throw LibraryLoaderException(libname + " does not exist");
	_lib = dlopen(libname.c_str(), RTLD_LAZY);
	if (!_lib)
		throw LibraryLoaderException(dlerror());
}

void *ecs::LibraryLoader::findSym(const std::string &symname)
{
	if (_lib == nullptr)
		throw LibraryLoaderException("No library loaded yet, can't load any symbol");
	return dlsym(_lib, symname.c_str());
}
