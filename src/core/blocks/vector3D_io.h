/** ICP Project 2017/2018: BlockEditor
 * @file vector_io.h
 * @brief Vector IO block header
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#ifndef VECTOR3DINPUT_H
#define VECTOR3DINPUT_H

#include "../blockbase.h"
#include "../graph.h"

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

#endif // VECTORADDBLOCK_H
