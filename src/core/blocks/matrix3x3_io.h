/** ICP Project 2017/2018: BlockEditor
 * @file matrix_io.h
 * @brief Matrix IO block header
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#ifndef MATRIX3x3_IO_H
#define MATRIX3x3_IO_H

#include "../blockbase.h"
#include "../graph.h"

/**
 * @brief The matrix input block class
 *
 * Construction, computation and destruction of a block.
 */
class Matrix3x3Input : public BlockBase
{
public:
	//! Constructor

	//! @param g Graph object - parent scheme
    Matrix3x3Input(Graph &g);
	//! Not used for Input Blocks
	void Compute() override;
	//! Virtual destructor to prevent leaks
    virtual ~Matrix3x3Input() = default;
};

/**
 * @brief The matrix output block class
 *
 * Construction, computation and destruction of a block.
 */
class Matrix3x3Output : public BlockBase
{
public:
	//! Constructor

	//! @param g Graph object - parent scheme
    Matrix3x3Output(Graph &g);
	//! Not used for Output Blocks
	void Compute() override;
	//! Virtual destructor to prevent leaks
    virtual ~Matrix3x3Output() = default;
};


#endif // MATRIX_IO_H
