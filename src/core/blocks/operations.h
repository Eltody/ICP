/*! VUT FIT ICP
 * @file operations.h
 * @brief Header súbor pre matematické operácie a prácu s blokmi
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */
#include "../blockbase.h"
#include "../graph.h"

/*!
 * @brief Trieda - blok pre číselný vstup
 *
 * Construction, computation and destruction of a block.
 */
class MathInput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathInput(Graph &g);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathInput() = default;
};

/*!
 * @brief Trieda - blok pre číselný výstup
 *
 * Construction, computation and destruction of a block.
 */
class MathOutput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathOutput(Graph &g);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathOutput() = default;
};


/*!
 * @brief Trieda - blok pre sčítanie dvoch čísel
 *
 * Construction, computation and destruction of a block.
 */
class MathAddBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathAddBlock(Graph &g);

    //! Performs the mathematical addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathAddBlock() = default;
};


/*!
 * @brief Trieda - blok pre odčítanie dvoch čísel
 *
 * Construction, computation and destruction of a block.
 */
class MathSubBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathSubBlock(Graph &g);

    //! Performs the mathematical subtraction
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathSubBlock() = default;
};


/*!
 * @brief Trieda - blok pre násobenie dvoch čísel
 *
 * Construction, computation and destruction of a block.
 */
class MathMulBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathMulBlock(Graph &g);

    //! Performs the mathematical multiplication
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathMulBlock() = default;
};


/*!
 * @brief Trieda - blok pre delenie dvoch čísel
 *
 * Construction, computation and destruction of a block.
 */
class MathDivBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathDivBlock(Graph &g);

    //! Performs the mathematical division
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathDivBlock() = default;
};


/*!
 * @brief Trieda - blok odmocnenie čísla
 *
 * Construction, computation and destruction of a block.
 */
class MathSqrtBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathSqrtBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathSqrtBlock() = default;
};


/*!
 * @brief Trieda - blok pre absolútnu hodnotu čísla
 *
 * Construction, computation and destruction of a block.
 */
class MathAbsBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathAbsBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathAbsBlock() = default;
};


/*!
 * @brief Trieda - blok pre zistenie väčšieho z dvoch čísel
 *
 * Construction, computation and destruction of a block.
 */
class MathGTBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathGTBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathGTBlock() = default;
};


/*!
 * @brief Trieda - blok pre zistenie menšieho z dvoch čísel
 *
 * Construction, computation and destruction of a block.
 */
class MathLTBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathLTBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathLTBlock() = default;
};


/*!
 * @brief Trieda - blok pre výpočet sínusu čísla
 *
 * Construction, computation and destruction of a block.
 */
class MathSinBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathSinBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathSinBlock() = default;
};


/*!
 * @brief Trieda - blok pre výpočet cosínusu čísla
 *
 * Construction, computation and destruction of a block.
 */
class MathCosBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathCosBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathCosBlock() = default;
};


/*!
 * @brief Trieda - blok pre inkrementáciu čísla o 1
 *
 * Construction, computation and destruction of a block.
 */
class MathIncBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathIncBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathIncBlock() = default;
};


/*!
 * @brief Trieda - blok pre dekrementáciu čísla o 1
 *
 * Construction, computation and destruction of a block.
 */
class MathDecBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    MathDecBlock(Graph &g);

    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathDecBlock() = default;
};


//----------MATICE----------


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


//----------VEKTORY----------


/*!
 * @brief Trieda - blok pre 2D vektorový vstup
 *
 * Construction, computation and destruction of a block.
 */
class VectorInput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorInput(Graph &g);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorInput() = default;
};


/*!
 * @brief Trieda - blok pre 2D vektorový výstup
 *
 * Construction, computation and destruction of a block.
 */
class VectorOutput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorOutput(Graph &g);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorOutput() = default;
};


/*!
 * @brief Trieda - blok pre 3D vektorový vstup
 *
 * Construction, computation and destruction of a block.
 */
class Vector3DInput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    Vector3DInput(Graph &g);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Vector3DInput() = default;
};


/*!
 * @brief Trieda - blok pre 3D vektorový výstup
 *
 * Construction, computation and destruction of a block.
 */
class Vector3DOutput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    Vector3DOutput(Graph &g);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Vector3DOutput() = default;
};


/*!
 * @brief Trieda - blok pre 2D sčítanie dvoch vektorov
 *
 * Construction, computation and destruction of a block.
 */
class VectorAddBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorAddBlock(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorAddBlock() = default;
};


/*!
 * @brief Trieda - blok pre 2D odčítanie dvoch vektorov
 *
 * Construction, computation and destruction of a block.
 */
class VectorSubBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorSubBlock(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorSubBlock() = default;
};


/*!
 * @brief Trieda - blok pre 3D sčítanie dvoch vektorov
 *
 * Construction, computation and destruction of a block.
 */
class VectorAddBlock3D : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorAddBlock3D(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorAddBlock3D() = default;
};


/*!
 * @brief Trieda - blok pre 3D odčítanie dvoch vektorov
 *
 * Construction, computation and destruction of a block.
 */
class VectorSubBlock3D : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorSubBlock3D(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorSubBlock3D() = default;
};


/*!
 * @brief Trieda - blok pre 2D skalárny súčin
 *
 * Construction, computation and destruction of a block.
 */
class VectorDotProductBlock2D : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorDotProductBlock2D(Graph &g);

    //! Computes the vectors' dot product
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorDotProductBlock2D() = default;
};


/*!
 * @brief Trieda - blok pre výstup 2D skalárneho súčinu
 *
 * Construction, computation and destruction of a block.
 */
class VectorDotOutput : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorDotOutput(Graph &g);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorDotOutput() = default;
};


/*!
 * @brief Trieda - blok pre násobenie 2D vektoru konštantou
 *
 * Construction, computation and destruction of a block.
 */
class VectorMulConstBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorMulConstBlock(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorMulConstBlock() = default;
};


/*!
 * @brief Trieda - blok pre násobenie 3D vektoru konštantou
 *
 * Construction, computation and destruction of a block.
 */
class VectorMulConstBlock3D : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    VectorMulConstBlock3D(Graph &g);

    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorMulConstBlock3D() = default;
};
