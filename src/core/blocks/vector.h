/*! VUT FIT ICP
 * @file vector.h
 * @brief Header súbor pre vektorové operácie a prácu s blokmi
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */
#include "../blockbase.h"
#include "../graph.h"

/*!
 * @brief Trieda - blok pre 2D vektorový vstup
 *
 * Construction, computation and destruction of a block.
 */
class VectorInput : public BlockBase{
public:
	//! Constructor

	//! @param g Graph object - parent scheme
	VectorInput(Graph &g);
	//! Not used for Input Blocks
	void Compute() override;
	//! Virtual destructor to prevent leaks
	virtual ~VectorInput() = default;
};

/*!
 * @brief Trieda - blok pre 2D vektorový výstup
 *
 * Construction, computation and destruction of a block.
 */
class VectorOutput : public BlockBase{
public:
	//! Constructor

	//! @param g Graph object - parent scheme
	VectorOutput(Graph &g);
	//! Not used for Output Blocks
	void Compute() override;
	//! Virtual destructor to prevent leaks
	virtual ~VectorOutput() = default;
};




/*!
 * @brief Trieda - blok pre 3D vektorový vstup
 *
 * Construction, computation and destruction of a block.
 */
class Vector3DInput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    Vector3DInput(Graph &g);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Vector3DInput() = default;
};

/*!
 * @brief Trieda - blok pre 3D vektorový výstup
 *
 * Construction, computation and destruction of a block.
 */
class Vector3DOutput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    Vector3DOutput(Graph &g);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Vector3DOutput() = default;
};




/*!
 * @brief Trieda - blok pre 2D sčítanie dvoch vektorov
 *
 * Construction, computation and destruction of a block.
 */
class VectorAddBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorAddBlock(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorAddBlock() = default;
};


/*!
 * @brief Trieda - blok pre 2D odčítanie dvoch vektorov
 *
 * Construction, computation and destruction of a block.
 */
class VectorSubBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorSubBlock(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorSubBlock() = default;
};



/*!
 * @brief Trieda - blok pre 3D sčítanie dvoch vektorov
 *
 * Construction, computation and destruction of a block.
 */
class VectorAddBlock3D : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorAddBlock3D(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorAddBlock3D() = default;
};


/*!
 * @brief Trieda - blok pre 3D odčítanie dvoch vektorov
 *
 * Construction, computation and destruction of a block.
 */
class VectorSubBlock3D : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorSubBlock3D(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorSubBlock3D() = default;
};


/*!
 * @brief Trieda - blok pre 2D skalárny súčin
 *
 * Construction, computation and destruction of a block.
 */
class VectorDotProductBlock2D : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorDotProductBlock2D(Graph &g);

    //! Computes the vectors' dot product
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorDotProductBlock2D() = default;
};


/*!
 * @brief Trieda - blok pre výstup 2D skalárneho súčinu
 *
 * Construction, computation and destruction of a block.
 */
class VectorDotOutput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorDotOutput(Graph &g);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorDotOutput() = default;
};


/*!
 * @brief Trieda - blok pre násobenie 2D vektoru konštantou
 *
 * Construction, computation and destruction of a block.
 */
class VectorMulConstBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorMulConstBlock(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorMulConstBlock() = default;
};


/*!
 * @brief Trieda - blok pre násobenie 3D vektoru konštantou
 *
 * Construction, computation and destruction of a block.
 */
class VectorMulConstBlock3D : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorMulConstBlock3D(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorMulConstBlock3D() = default;
};
