/*! VUT FIT ICP
 * @file type.h
 * @brief Header súbor pre prácu s typovými hodnotami
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#pragma once
#include <map>
#include <string>
#include <initializer_list>
#include <iostream>
#include <functional>

class Ports;
class Type;

//! @brief TypeValue je komponent Type
class TypeValue{
    friend class Type;
private:
	double data;
    Type &type;
    TypeValue(Type &type, double value = 0.0);
public:
	operator const double &() const;
	TypeValue & operator=(const double &value);
	friend bool operator== (const TypeValue &a, const TypeValue &b);
};

class Type{
	friend class TypeValue;

private:
	bool null_data;
	std::map<std::string, TypeValue> data;
	Ports *port;

public:
    Type(std::initializer_list<std::string> components);
    Type(const Type &other);
    Type(const Type &other, Ports *port);
    Type & operator=(const Type &other);
    Type(Type &&other) = delete;
	TypeValue & operator[](const std::string &s);

	const std::map<std::string, TypeValue> Data();
	bool isNull() const;
	void setNull();

    //! porovnanie typu
    bool type_of(const Type &other) const;

    //! porovnanie hodnoty
    friend bool operator== (const Type &a, const Type &b);
	operator std::string();
};
