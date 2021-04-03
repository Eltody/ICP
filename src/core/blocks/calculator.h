#include "../blockbase.h"
#include "../graph.h"

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


/**
 * @brief The mathematical subtraction block class
 *
 * Construction, computation and destruction of a block.
 */
class MathSubBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathSubBlock(Graph &g);

    //! Performs the mathematical subtraction
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathSubBlock() = default;
};


/**
 * @brief The mathematical multiplication block class
 *
 * Construction, computation and destruction of a block.
 */
class MathMulBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathMulBlock(Graph &g);

    //! Performs the mathematical multiplication
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathMulBlock() = default;
};


/**
 * @brief The mathematical division block class
 *
 * Construction, computation and destruction of a block.
 */
class MathDivBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathDivBlock(Graph &g);

    //! Performs the mathematical division
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathDivBlock() = default;
};


/**
 * @brief The square root block class
 *
 * Construction, computation and destruction of a block.
 */
class MathSqrtBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathSqrtBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathSqrtBlock() = default;
};


/**
 * @brief The absolute value block class
 *
 * Construction, computation and destruction of a block.
 */
class MathAbsBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathAbsBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathAbsBlock() = default;
};


/**
 * @brief Greater value than another block class
 *
 * Construction, computation and destruction of a block.
 */
class MathGTBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathGTBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathGTBlock() = default;
};


/**
 * @brief Less value than another block class
 *
 * Construction, computation and destruction of a block.
 */
class MathLTBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathLTBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathLTBlock() = default;
};


/**
 * @brief Less value than another block class
 *
 * Construction, computation and destruction of a block.
 */
class MathSinBlock : public BlockBase
{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathSinBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathSinBlock() = default;
};
