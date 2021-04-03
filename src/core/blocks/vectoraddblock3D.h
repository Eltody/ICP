/** ICP Project 2017/2018: BlockEditor
 * @file vectoraddblock.h
 * @brief Vector addition block header
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#ifndef VECTORADDBLOCK3D_H
#define VECTORADDBLOCK3D_H

#include "../blockbase.h"
#include "../graph.h"

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

#endif // VECTORADDBLOCK_H
