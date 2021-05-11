/*! VUT FIT ICP
 * @file blockbase.h
 * @brief Header súbor pre kontrolu a prácu s portami
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */
#pragma once
#include <string>
#include <vector>
#include <initializer_list>
#include "BlockPort.h"
#include "BlockManager.h"
#include "Blocks.h"

class Manager;

/**
 * @brief Definícia základného bloku
 * Všetky bloky dedia funkcie z tejto triedy a implemenetujú výpočty
 */
class BlockBase {
private:
    /**
     * @brief Vektor vstupných portov
	 */
    std::vector<InPort> inputs;
    /**
     * @brief Vektor výstupných portov
	 */
    std::vector<OutPort> outputs;
protected:
    BlockBase(Manager &g, BlockType type, std::string name);
	BlockBase(Manager &g, BlockType type, std::string name,
			  std::initializer_list<InPort> inputs,
			  std::initializer_list<OutPort> outputs);
public:
    /**
     * @brief Referencia parent Manager object
	 */
	Manager &graph;
    /**
     * @brief Typ bloku
	 */
	const BlockType type;
    /**
     * @brief Názov bloku
	 */
	const std::string name;
    /**
     * @brief Získanie unikátneho ID bloku
     * @return Vracia ID bloku
	 */
	int getID() const;
    /**
     * @brief Získanie unikátneho ID portu
     * @param Ports InPort
     * @return Vracia ID input portu
     */
	virtual int getPortID(const InPort &port) const;
    /**
     * @brief Získanie unikátneho ID portu
     * @param Ports OutPort
     * @return Vracia ID output portu
	 */
	virtual int getPortID(const OutPort &port) const;
    /**
     * @brief Získanie adresy portu
     * @param Ports ID vstupného portu
     * @return Vracia adresu vstupného portu
	 */
	virtual InPort & Input(std::size_t id);
    /**
     * @brief Počet vstupov
     * @return Vráti počet vstupov
	 */
	virtual std::size_t InputCount();
    /**
     * @brief Získanie adresy portu
     * @param Ports ID výstupného portu
     * @return Vracia adresu výstupného portu
	 */
	virtual OutPort & Output(std::size_t id);
    /**
     * @brief Počet výstupov
     * @return Vracia počet výstupov
	 */
	virtual std::size_t OutputCount();

    /**
     * @brief Kontrola či sú všetky porty nenulové
     * @return Vracia true, ak sú všetky porty nenulové
	 */
	bool HasAllValues();
    /**
     * @brief Kontrola či sú všetky vstupy pripojené na bloky
     * @return Vracia true ak všetky sú všetky vstupy pripojené
	 */
	bool InputsAreConnected();
	virtual bool Computable();
    /**
     * @brief Nastavenie všetkých hodnôt výstupných portov na Null
	 */
	void Reset();

	virtual void Compute() = 0;

    // Deštruktor
	virtual ~BlockBase() = default;
};
