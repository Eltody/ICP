#include "../blockbase.h"
#include "../graph.h"

/**
 * @brief The scalar input block class
 *
 * Construction, computation and destruction of a block.
 */
class ScalarInput : public BlockBase
{
public:
	//! Constructor

	//! @param g Graph object - parent scheme
	ScalarInput(Graph &g);
	//! Not used for Input Blocks
	void Compute() override;
	//! Virtual destructor to prevent leaks
	virtual ~ScalarInput() = default;
};

/**
 * @brief The scalar output block class
 *
 * Construction, computation and destruction of a block.
 */
class ScalarOutput : public BlockBase
{
public:
	//! Constructor

	//! @param g Graph object - parent scheme
	ScalarOutput(Graph &g);
	//! Not used for Output Blocks
	void Compute() override;
	//! Virtual destructor to prevent leaks
	virtual ~ScalarOutput() = default;
};


/**
 * @brief The scalar addition block class
 *
 * Construction, computation and destruction of a block.
 */
class ScalarAddBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    ScalarAddBlock(Graph &g);

    //! Performs the scalar addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~ScalarAddBlock() = default;
};



/**
 * @brief The scalar multiplication block class
 *
 * Construction, computation and destruction of a block.
 */
class ScalarMulBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    ScalarMulBlock(Graph &g);

    //! Performs the scalar multiplication
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~ScalarMulBlock() = default;
};



/**
 * @brief The scalar subtraction block class
 *
 * Construction, computation and destruction of a block.
 */
class ScalarSubBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    ScalarSubBlock(Graph &g);

    //! Performs the scalar subtraction
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~ScalarSubBlock() = default;
};


//*********************************************//


/**
 * @brief The mathematical input block class
 *
 * Construction, computation and destruction of a block.
 */
class MathInput : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathInput(Graph &g);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathInput() = default;
};

/**
 * @brief The mathematical output block class
 *
 * Construction, computation and destruction of a block.
 */
class MathOutput : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathOutput(Graph &g);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathOutput() = default;
};


/**
 * @brief The mathematical addition block class
 *
 * Construction, computation and destruction of a block.
 */
class MathAddBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathAddBlock(Graph &g);

    //! Performs the mathematical addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathAddBlock() = default;
};
