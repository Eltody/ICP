/*! VUT FIT ICP
 * @file port.h
 * @brief Header súbor pre prácu s portami
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#pragma once
#include <string>
#include "BlockType.h"

class BlockBase;

//! Class defining plain port
class Ports{
protected:
	//! Data type
    Type data;
    std::function<void(Ports &)> connUpdate, valUpdate;
public:
	//! Parent block reference
	const BlockBase &block;
	//! Human readable block name
	const std::string name;

	//! Copy constructor
    Ports(const Ports &other);
	/**
	 * @brief Constructor
	 * @param b Block where to create the new port
     * @param t Type of the port
	 * @param name Name of the port's label
	 */
    Ports(const BlockBase & b, const Type &t, std::string name);
	//! Returns port's value
    virtual Type & Value() = 0;
	//! Operator [] overloading for using data type specific strings to access values of the port
	TypeValue & operator[](const std::string &s);

	//! Fires onValueChange callback for this port
	virtual void eventValueChange();
	//! Fires onConnectionChange callback
	void eventConnectionChange();
	//! Sets what to do on connection change
    void onConnectionChange(std::function<void(Ports &)> callback);
	//! Sets what to do on value change
    void onValueChange(std::function<void(Ports &)> callback);
};

//! Input port class
class InPort : public Ports{
public:
	//! Get input port ID
	//! @return ID of the port
	int getID() const;
	//! Input port copy constructor
	InPort(const InPort & other, const BlockBase & b);
	/**
	 * @brief Input port constructor
	 * @param b Block where the port is created
     * @param t Type of the port
	 * @param name Name of the port's label
	 */
    InPort(const BlockBase & b, const Type &t, std::string name);
	//! Returns port's value
    Type & Value() override;
};

//! Input port class
class OutPort : public Ports{
public:
	//! Fires onValueChange callback for this port and all connected ports
	void eventValueChange() override;
	//! Get output port ID
	//! @return ID of the port
	int getID() const;
	//! Input port copy constructor
	OutPort(const OutPort & other, const BlockBase & b);
	/**
	 * @brief Input port constructor
	 * @param b Block where the port is created
     * @param t Type of the port
	 * @param name Name of the port's label
	 */
    OutPort(const BlockBase & b, const Type &t, std::string name);
	//! Returns port's value
    Type & Value() override;
};
