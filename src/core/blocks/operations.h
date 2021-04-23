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
 */
class MathInput : public BlockBase{
public:
    MathInput(Graph &graph_obj);
    void Compute() override;
    virtual ~MathInput() = default; // destruktor
};

/*!
 * @brief Trieda - blok pre číselný výstup
 */
class MathOutput : public BlockBase{
public:
    MathOutput(Graph &graph_obj);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathOutput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre sčítanie dvoch čísel
 */
class MathAddBlock : public BlockBase{
public:
    MathAddBlock(Graph &graph_obj);
    //! Performs the mathematical addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathAddBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre odčítanie dvoch čísel
 */
class MathSubBlock : public BlockBase{
public:
    MathSubBlock(Graph &graph_obj);
    //! Performs the mathematical subtraction
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathSubBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre násobenie dvoch čísel
 */
class MathMulBlock : public BlockBase{
public:
    MathMulBlock(Graph &graph_obj);
    //! Performs the mathematical multiplication
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathMulBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre delenie dvoch čísel
 */
class MathDivBlock : public BlockBase{
public:
    MathDivBlock(Graph &graph_obj);
    //! Performs the mathematical division
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathDivBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok odmocnenie čísla
 */
class MathSqrtBlock : public BlockBase{
public:
    MathSqrtBlock(Graph &graph_obj);
    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathSqrtBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre absolútnu hodnotu čísla
 */
class MathAbsBlock : public BlockBase{
public:
    MathAbsBlock(Graph &graph_obj);
    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathAbsBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre zistenie väčšieho z dvoch čísel
 */
class MathGTBlock : public BlockBase{
public:
    MathGTBlock(Graph &graph_obj);
    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathGTBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre zistenie menšieho z dvoch čísel
 */
class MathLTBlock : public BlockBase{
public:
    MathLTBlock(Graph &graph_obj);
    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathLTBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre výpočet sínusu čísla
 */
class MathSinBlock : public BlockBase{
public:
    MathSinBlock(Graph &graph_obj);
    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathSinBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre výpočet cosínusu čísla
 */
class MathCosBlock : public BlockBase{
public:
    MathCosBlock(Graph &graph_obj);
    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathCosBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre inkrementáciu čísla o 1
 */
class MathIncBlock : public BlockBase{
public:
    MathIncBlock(Graph &graph_obj);
    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathIncBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre dekrementáciu čísla o 1
 */
class MathDecBlock : public BlockBase{
public:
    MathDecBlock(Graph &graph_obj);
    //! Performs the square root
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MathDecBlock() = default; // destruktor
};


//----------MATICE----------


/*!
 * @brief Trieda - blok pre 2x2 maticový vstup
 */
class MatrixInput : public BlockBase{
public:
    MatrixInput(Graph &graph_obj);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixInput() = default; // destruktor
};

/*!
 * @brief Trieda - blok pre 2x2 maticový výstup
 */
class MatrixOutput : public BlockBase{
public:
    MatrixOutput(Graph &graph_obj);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixOutput() = default; // destruktor
};

/*!
 * @brief Trieda - blok pre 3x3 maticový vstup
 */
class Matrix3x3Input : public BlockBase{
public:
    Matrix3x3Input(Graph &graph_obj);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Matrix3x3Input() = default; // destruktor
};

/*!
 * @brief Trieda - blok pre 3x3 maticový výstup
 */
class Matrix3x3Output : public BlockBase{
public:
    Matrix3x3Output(Graph &graph_obj);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Matrix3x3Output() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2x2 maticové násobenie vektorom
 */
class MatMulVecBlock : public BlockBase{
public:
    MatMulVecBlock(Graph &graph_obj);
    //! Multiplies matrix by a vector
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatMulVecBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3x3 maticové násobenie vektorom
 */
class Mat3x3MulVecBlock : public BlockBase{
public:
    //! Constructor

    //! @param g Graph object - parent scheme
    Mat3x3MulVecBlock(Graph &graph_obj);

    //! Multiplies matrix by a vector
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Mat3x3MulVecBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2x2 maticové sčítanie
 */
class MatrixAddBlock : public BlockBase{
public:
    MatrixAddBlock(Graph &graph_obj);
    //! Performs the matrix addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixAddBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3x3 maticové sčítanie
 */
class Matrix3x3AddBlock : public BlockBase{
public:
    Matrix3x3AddBlock(Graph &graph_obj);
    //! Performs the matrix addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Matrix3x3AddBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2x2 maticové násobenie
 */
class MatrixMulBlock : public BlockBase{
public:
    MatrixMulBlock(Graph &graph_obj);
    //! Performs the matrix multiplication
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixMulBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3x3 maticové násobenie
 */
class Matrix3x3MulBlock : public BlockBase{
public:
    Matrix3x3MulBlock(Graph &graph_obj);
    //! Performs the matrix multiplication
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Matrix3x3MulBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2x2 maticové odčítanie
 */
class MatrixSubBlock : public BlockBase{
public:
    MatrixSubBlock(Graph &graph_obj);
    //! Performs the matrix addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixSubBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3x3 maticové odčítanie
 */
class Matrix3x3SubBlock : public BlockBase{
public:
    Matrix3x3SubBlock(Graph &graph_obj);
    //! Performs the matrix addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Matrix3x3SubBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre výpočet determinantu matice 2x2
 */
class MatrixDeterminantBlock : public BlockBase{
public:
    MatrixDeterminantBlock(Graph &graph_obj);
    //! Performs the matrix determinant
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixDeterminantBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre výstup výpočtu determinantu matice 2x2
 */
class MatrixDeterminantOutput : public BlockBase{
public:
    MatrixDeterminantOutput(Graph &graph_obj);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixDeterminantOutput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre vstup výpočtu determinantu matice 2x2
 */
class MatrixDeterminantInput : public BlockBase{
public:
    MatrixDeterminantInput(Graph &graph_obj);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~MatrixDeterminantInput() = default; // destruktor
};


//----------VEKTORY----------


/*!
 * @brief Trieda - blok pre 2D vektorový vstup
 */
class VectorInput : public BlockBase{
public:
    VectorInput(Graph &graph_obj);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorInput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2D vektorový výstup
 */
class VectorOutput : public BlockBase{
public:
    VectorOutput(Graph &graph_obj);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorOutput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3D vektorový vstup
 */
class Vector3DInput : public BlockBase{
public:
    Vector3DInput(Graph &graph_obj);
    //! Not used for Input Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Vector3DInput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3D vektorový výstup
 */
class Vector3DOutput : public BlockBase{
public:
    Vector3DOutput(Graph &graph_obj);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~Vector3DOutput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2D sčítanie dvoch vektorov
 */
class VectorAddBlock : public BlockBase{
public:
    VectorAddBlock(Graph &graph_obj);
    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorAddBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2D odčítanie dvoch vektorov
 */
class VectorSubBlock : public BlockBase{
public:
    VectorSubBlock(Graph &graph_obj);
    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorSubBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3D sčítanie dvoch vektorov
 */
class VectorAddBlock3D : public BlockBase{
public:
    VectorAddBlock3D(Graph &graph_obj);
    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorAddBlock3D() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3D odčítanie dvoch vektorov
 */
class VectorSubBlock3D : public BlockBase{
public:
    VectorSubBlock3D(Graph &graph_obj);
    //! Performs the vector addition
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorSubBlock3D() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2D skalárny súčin
 */
class VectorDotProductBlock2D : public BlockBase{
public:
    VectorDotProductBlock2D(Graph &graph_obj);
    //! Computes the vectors' dot product
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorDotProductBlock2D() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre výstup 2D skalárneho súčinu
 */
class VectorDotOutput : public BlockBase{
public:
    VectorDotOutput(Graph &graph_obj);
    //! Not used for Output Blocks
    void Compute() override;
    //! Virtual destructor to prevent leaks
    virtual ~VectorDotOutput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre násobenie 2D vektoru konštantou
 */
class VectorMulConstBlock : public BlockBase{
public:
    VectorMulConstBlock(Graph &graph_obj);
    //! Performs the vector addition
    void Compute() override;
    virtual ~VectorMulConstBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre násobenie 3D vektoru konštantou
 * @param Graph object g
 */
class VectorMulConstBlock3D : public BlockBase{
public:
    VectorMulConstBlock3D(Graph &graph_obj);
    //! Performs the vector addition
    void Compute() override;
    virtual ~VectorMulConstBlock3D() = default; // destruktor
};
