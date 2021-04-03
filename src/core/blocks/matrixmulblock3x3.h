/** ICP Project 2017/2018: BlockEditor
 * @file matrixmulblock.h
 * @brief Matrix multiplication block header
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#ifndef MATRIX3x3MULBLOCK
#define MATRIX3x3MULBLOCK

#include "../blockbase.h"
#include "../graph.h"

/**
 * @brief The matrix multiplication block class
 *
 * Construction, computation and destruction of a block.
 */
class Matrix3x3MulBlock : public BlockBase
{
public:
	//! Constructor

	//! @param g Graph object - parent scheme
    Matrix3x3MulBlock(Graph &g);
	
	//! Performs the matrix multiplication
	void Compute() override;
	//! Virtual destructor to prevent leaks
    virtual ~Matrix3x3MulBlock() = default;
};

#endif // MATRIXMULBLOCK

