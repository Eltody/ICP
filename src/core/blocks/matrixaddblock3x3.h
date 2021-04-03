/** ICP Project 2017/2018: BlockEditor
 * @file matrixaddblock.h
 * @brief Matrix addition block header
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#ifndef MATRIX3x3ADDBLOCK
#define MATRIX3x3ADDBLOCK

#include "../blockbase.h"
#include "../graph.h"

/**
 * @brief The matrix addition block class
 *
 * Construction, computation and destruction of a block.
 */
class Matrix3x3AddBlock : public BlockBase
{
public:
	//! Constructor

	//! @param g Graph object - parent scheme
    Matrix3x3AddBlock(Graph &g);
	
	//! Performs the matrix addition
	void Compute() override;
	//! Virtual destructor to prevent leaks
    virtual ~Matrix3x3AddBlock() = default;
};

#endif // MATRIXADDBLOCK

