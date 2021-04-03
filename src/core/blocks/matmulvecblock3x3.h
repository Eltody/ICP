/** ICP Project 2017/2018: BlockEditor
 * @file matmulvecblock.h
 * @brief Matrix and vector multiplication block header
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#ifndef MAT3MULVECBLOCK_H
#define MAT3MULVECBLOCK_H

#include "../blockbase.h"
#include "../graph.h"

/**
 * @brief The matrix by vector multiplication block class
 *
 * Construction, computation and destruction of a block.
 */
class Mat3x3MulVecBlock : public BlockBase
{
public:
	//! Constructor

	//! @param g Graph object - parent scheme
    Mat3x3MulVecBlock(Graph &g);
	
	//! Multiplies matrix by a vector
	void Compute() override;
	//! Virtual destructor to prevent leaks
    virtual ~Mat3x3MulVecBlock() = default;
};

#endif // MATMULVECBLOCK_H
