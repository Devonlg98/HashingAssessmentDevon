// hash.h
#pragma once
#include <iostream>
#include <cstring>
#include <limits>

// template declaration for hash
template<typename T>
size_t hash(const T& val)
{
	// unelegant way of telling users to specialize this template
	T::please_specialize_this_template_for_your_type;
}

// template specialization for int
template<>
size_t hash<int>(const int& val)
{
	// Knuth's hash function
	return val * 2654435761 % std::numeric_limits<size_t>::max();
}

// template specialization for char
template<>
size_t hash<char>(const char& val)
{
	return (int)val * 2654435761 % std::numeric_limits<size_t>::max();
}


//Cstring hash specialization
template<>
size_t hash<char*>(char * const& val)
{
	unsigned int hash = 0;
	for (unsigned int i = 0;i != '\0'; i++)
	{
		hash = (hash * 1313) + val[i];
	}
	return (int)val * 2654435761 % std::numeric_limits<size_t>::max();
}

template<>

size_t hash<std::string>(const std::string &val)
{
	int hash = 0;
	for (unsigned int i = 0; val[i] != '\0'; i++)
	{
		hash = (hash * 1313) + (int)val[i];
	}
	return (int)hash * 2654435761 % std::numeric_limits<size_t>::max();
}


template<typename K, typename V>
class tHashmap
{
	V * data;                       // buffer holding all potential pairs in the hashmap
	size_t dataCapacity;           // size of the above buffers
	K key;
	V val;

public:
	tHashmap();                     // constructs the hashmap with a specific size
	~tHashmap();                    // cleans-up any underlying data

	V& operator[] (const K& key);   // returns the object at the given key
	tHashmap(const tHashmap & orig);
	tHashmap& operator=(const tHashmap& orig);
};




// constructs the hashmap with a specific size
template<typename K, typename V>
inline tHashmap<K, V>::tHashmap()
{
	dataCapacity = 5;
	data = new V[dataCapacity];

}
// cleans-up any underlying data
template<typename K, typename V>
inline tHashmap<K, V>::~tHashmap()
{
	delete[] data;
}
// returns the object at the given key
template<typename K, typename V>
inline V & tHashmap<K, V>::operator[](const K & key)
{
	auto keyValue = hash(key) % dataCapacity;
	return data[keyValue];
}

template<typename K, typename V>
inline tHashmap<K, V>::tHashmap(const tHashmap & orig)
{
	for (int i = 0; data[i] < dataCapacity; i++)
	{
		data[i] = orig.data[i];
	}
}



template<typename K, typename V>
inline tHashmap<K, V> & tHashmap<K, V>::operator=(const tHashmap & orig)
{
	for (int i = 0; data[i] <dataCapacity; i++)
	{
		this.data[i] = orig.data[i];
	}
	return *this;
}

