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

//! Trieda definujuca vytvoreny port
class Ports{
protected:
    Type data;
    std::function<void(Ports &)> connUpdate, valUpdate;

public:
	const BlockBase &block;
	const std::string name;
    Ports(const Ports &other);
	/**
     * @brief Constructor Konštruktor
     * @param b Blok, kde sa vytvorí nový port
     * @param t Typ portu
     * @param name Názov portu
	 */
    Ports(const BlockBase & b, const Type &t, std::string name);
    //! Vráti hodnotu portu
    virtual Type & Value() = 0;
	TypeValue & operator[](const std::string &s);

	virtual void eventValueChange();
	void eventConnectionChange();
    void onConnectionChange(std::function<void(Ports &)> callback);
    void onValueChange(std::function<void(Ports &)> callback);
};

//! Trieda vstupného portu
class InPort : public Ports{
public:
    //! Získaj vstupný ID port
    //! @return Vracia sa ID portu
	int getID() const;
	InPort(const InPort & other, const BlockBase & b);
	/**
     * @brief Konštruktor vstupného portu
     * @param b Blok kde bude port vytvorený
     * @param t Typ portu
     * @param name Názov portu
	 */
    InPort(const BlockBase & b, const Type &t, std::string name);
    //! Vráti hodnotu portu
    Type & Value() override;
};

//! Trieda pre výstupný port
class OutPort : public Ports{
public:
    //! Spusti callback pre tento a všetky pripojené porty
	void eventValueChange() override;
    //! Získa ID výstupného portu
    //! @return Vracia sa ID portu
	int getID() const;
    //! Konštruktor
	OutPort(const OutPort & other, const BlockBase & b);
	/**
     * @brief Konštruktor vstupného portu
     * @param b Blok kde bude port vytvorený
     * @param t Typ portu
     * @param name Názov portu
	 */
    OutPort(const BlockBase & b, const Type &t, std::string name);
    //! Vracia hodnotu portu
    Type & Value() override;
};
