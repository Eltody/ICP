/*! VUT FIT ICP
 * @file calculator.h
 * @brief Header súbor pre matematické operácie a prácu s blokmi
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#include "../blockbase.h"
#include "../graph.h"

/*!
 * @brief Trieda - blok pre číselný vstup
 *
 * Construction, computation and destruction of a block.
 */
class MathInput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathInput(Graph &g);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathInput() = default;
};

/*!
 * @brief Trieda - blok pre číselný výstup
 *
 * Construction, computation and destruction of a block.
 */
class MathOutput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathOutput(Graph &g);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathOutput() = default;
};


/*!
 * @brief Trieda - blok pre sčítanie dvoch čísel
 *
 * Construction, computation and destruction of a block.
 */
class MathAddBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathAddBlock(Graph &g);

    //! Performs the mathematical addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathAddBlock() = default;
};


/*!
 * @brief Trieda - blok pre odčítanie dvoch čísel
 *
 * Construction, computation and destruction of a block.
 */
class MathSubBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathSubBlock(Graph &g);

    //! Performs the mathematical subtraction
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathSubBlock() = default;
};


/*!
 * @brief Trieda - blok pre násobenie dvoch čísel
 *
 * Construction, computation and destruction of a block.
 */
class MathMulBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathMulBlock(Graph &g);

    //! Performs the mathematical multiplication
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathMulBlock() = default;
};


/*!
 * @brief Trieda - blok pre delenie dvoch čísel
 *
 * Construction, computation and destruction of a block.
 */
class MathDivBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathDivBlock(Graph &g);

    //! Performs the mathematical division
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathDivBlock() = default;
};


/*!
 * @brief Trieda - blok odmocnenie čísla
 *
 * Construction, computation and destruction of a block.
 */
class MathSqrtBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathSqrtBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathSqrtBlock() = default;
};


/*!
 * @brief Trieda - blok pre absolútnu hodnotu čísla
 *
 * Construction, computation and destruction of a block.
 */
class MathAbsBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathAbsBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathAbsBlock() = default;
};


/*!
 * @brief Trieda - blok pre zistenie väčšieho z dvoch čísel
 *
 * Construction, computation and destruction of a block.
 */
class MathGTBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathGTBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathGTBlock() = default;
};


/*!
 * @brief Trieda - blok pre zistenie menšieho z dvoch čísel
 *
 * Construction, computation and destruction of a block.
 */
class MathLTBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathLTBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathLTBlock() = default;
};


/*!
 * @brief Trieda - blok pre výpočet sínusu čísla
 *
 * Construction, computation and destruction of a block.
 */
class MathSinBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathSinBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathSinBlock() = default;
};


/*!
 * @brief Trieda - blok pre výpočet cosínusu čísla
 *
 * Construction, computation and destruction of a block.
 */
class MathCosBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathCosBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathCosBlock() = default;
};


/*!
 * @brief Trieda - blok pre inkrementáciu čísla o 1
 *
 * Construction, computation and destruction of a block.
 */
class MathIncBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathIncBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathIncBlock() = default;
};


/*!
 * @brief Trieda - blok pre dekrementáciu čísla o 1
 *
 * Construction, computation and destruction of a block.
 */
class MathDecBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathDecBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathDecBlock() = default;
};
