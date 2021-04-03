#include "../blockbase.h"
#include "../graph.h"

/**
 * @brief The vector input block class
 *
 * Construction, computation and destruction of a block.
 */
class VectorInput : public BlockBase
{
public:
	//! Constructor

	//! @param g Graph object - parent scheme
	VectorInput(Graph &g);
	//! Not used for Input Blocks
	void Compute() override;
	//! Virtual destructor to prevent leaks
	virtual ~VectorInput() = default;
};

/**
 * @brief The vector output block class
 *
 * Construction, computation and destruction of a block.
 */
class VectorOutput : public BlockBase
{
public:
	//! Constructor

	//! @param g Graph object - parent scheme
	VectorOutput(Graph &g);
	//! Not used for Output Blocks
	void Compute() override;
	//! Virtual destructor to prevent leaks
	virtual ~VectorOutput() = default;
};




/**
 * @brief The vector input block class
 *
 * Construction, computation and destruction of a block.
 */
class Vector3DInput : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    Vector3DInput(Graph &g);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Vector3DInput() = default;
};

/**
 * @brief The vector output block class
 *
 * Construction, computation and destruction of a block.
 */
class Vector3DOutput : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    Vector3DOutput(Graph &g);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Vector3DOutput() = default;
};




/**
 * @brief The vector addition block class
 *
 * Construction, computation and destruction of a block.
 */
class VectorAddBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorAddBlock(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorAddBlock() = default;
};


/**
 * @brief The vector subtraction block class
 *
 * Construction, computation and destruction of a block.
 */
class VectorSubBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorSubBlock(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorSubBlock() = default;
};



/**
 * @brief The vector addition block class
 *
 * Construction, computation and destruction of a block.
 */
class VectorAddBlock3D : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorAddBlock3D(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorAddBlock3D() = default;
};




/**
 * @brief The vector dot product block class
 *
 * Construction, computation and destruction of a block.
 */
class VectorDotProductBlock2D : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorDotProductBlock2D(Graph &g);

    //! Computes the vectors' dot product
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorDotProductBlock2D() = default;
};


/**
 * @brief The vector output block class
 *
 * Construction, computation and destruction of a block.
 */
class VectorDotOutput : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorDotOutput(Graph &g);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorDotOutput() = default;
};
