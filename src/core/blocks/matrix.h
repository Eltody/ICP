/*! VUT FIT ICP
 * @file matrix.h
 * @brief Header súbor pre maticové operácie a prácu s blokmi
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include "../blockbase.h"
#include "../graph.h"

/*!
 * @brief Trieda - blok pre 2x2 maticový vstup
 *
 * Construction, computation and destruction of a block.
 */
class MatrixInput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MatrixInput(Graph &g);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixInput() = default;
};

/*!
 * @brief Trieda - blok pre 2x2 maticový výstup
 *
 * Construction, computation and destruction of a block.
 */
class MatrixOutput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MatrixOutput(Graph &g);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixOutput() = default;
};


#endif // MATRIX_IO_H




#ifndef MATRIX3x3_IO_H
#define MATRIX3x3_IO_H
/*!
 * @brief Trieda - blok pre 3x3 maticový vstup
 *
 * Construction, computation and destruction of a block.
 */
class Matrix3x3Input : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    Matrix3x3Input(Graph &g);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Matrix3x3Input() = default;
};

/*!
 * @brief Trieda - blok pre 3x3 maticový výstup
 *
 * Construction, computation and destruction of a block.
 */
class Matrix3x3Output : public BlockBase{
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





#ifndef MATMULVECBLOCK_H
#define MATMULVECBLOCK_H

/*!
 * @brief Trieda - blok pre 2x2 maticové násobenie vektorom
 *
 * Construction, computation and destruction of a block.
 */
class MatMulVecBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MatMulVecBlock(Graph &g);

    //! Multiplies matrix by a vector
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatMulVecBlock() = default;
};

#endif // MATMULVECBLOCK_H




#ifndef MAT3MULVECBLOCK_H
#define MAT3MULVECBLOCK_H

/*!
 * @brief Trieda - blok pre 3x3 maticové násobenie vektorom
 *
 * Construction, computation and destruction of a block.
 */
class Mat3x3MulVecBlock : public BlockBase{
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




#ifndef MATRIXADDBLOCK
#define MATRIXADDBLOCK

/*!
 * @brief Trieda - blok pre 2x2 maticové sčítanie
 *
 * Construction, computation and destruction of a block.
 */
class MatrixAddBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MatrixAddBlock(Graph &g);

    //! Performs the matrix addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixAddBlock() = default;
};

#endif // MATRIXADDBLOCK





#ifndef MATRIX3x3ADDBLOCK
#define MATRIX3x3ADDBLOCK

/*!
 * @brief Trieda - blok pre 3x3 maticové sčítanie
 *
 * Construction, computation and destruction of a block.
 */
class Matrix3x3AddBlock : public BlockBase{
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




#ifndef MATRIXMULBLOCK
#define MATRIXMULBLOCK

/*!
 * @brief Trieda - blok pre 2x2 maticové násobenie
 *
 * Construction, computation and destruction of a block.
 */
class MatrixMulBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MatrixMulBlock(Graph &g);

    //! Performs the matrix multiplication
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixMulBlock() = default;
};

#endif // MATRIXMULBLOCK





#ifndef MATRIX3x3MULBLOCK
#define MATRIX3x3MULBLOCK

/*!
 * @brief Trieda - blok pre 3x3 maticové násobenie
 *
 * Construction, computation and destruction of a block.
 */
class Matrix3x3MulBlock : public BlockBase{
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


//*!**********************************************************//


#ifndef MATRIXSUBBLOCK
#define MATRIXSUBBLOCK

/*!
 * @brief Trieda - blok pre 2x2 maticové odčítanie
 *
 * Construction, computation and destruction of a block.
 */
class MatrixSubBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MatrixSubBlock(Graph &g);

    //! Performs the matrix addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixSubBlock() = default;
};

#endif // MATRIXSUBBLOCK


#ifndef MATRIX3x3SUBBLOCK
#define MATRIX3x3SUBBLOCK

/*!
 * @brief Trieda - blok pre 3x3 maticové odčítanie
 *
 * Construction, computation and destruction of a block.
 */
class Matrix3x3SubBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    Matrix3x3SubBlock(Graph &g);

    //! Performs the matrix addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Matrix3x3SubBlock() = default;
};

#endif // MATRIXSUBBLOCK


#ifndef MATRIXDETERMINANTBLOCK
#define MATRIXDETERMINANTBLOCK

/*!
 * @brief Trieda - blok pre výpočet determinantu matice 2x2
 *
 * Construction, computation and destruction of a block.
 */
class MatrixDeterminantBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MatrixDeterminantBlock(Graph &g);

    //! Performs the matrix determinant
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixDeterminantBlock() = default;
};

#endif // MATRIXDETERMINANTBLOCK

#ifndef MATRIX_DETERMINANT_IO_H
#define MATRIX_DETERMINANT_IO_H

/*!
 * @brief Trieda - blok pre výstup výpočtu determinantu matice 2x2
 *
 * Construction, computation and destruction of a block.
 */
class MatrixDeterminantOutput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MatrixDeterminantOutput(Graph &g);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixDeterminantOutput() = default;
};


/*!
 * @brief Trieda - blok pre vstup výpočtu determinantu matice 2x2
 *
 * Construction, computation and destruction of a block.
 */
class MatrixDeterminantInput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MatrixDeterminantInput(Graph &g);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixDeterminantInput() = default;
};

#endif // MATRIX_DETERMINANT_IO_H
