/*! VUT FIT ICP
 * @file operations.h
 * @brief Header súbor pre matematické operácie a prácu s blokmi
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#include "../blockbase.h"
#include "../BlockManager.h"

/*!
 * @brief Trieda - blok pre číselný vstup
 * @param Manager object graph_obj
 */
class MathInput : public BlockBase{
public:
    MathInput(Manager &graph_obj);
    void Compute() override;
    virtual ~MathInput() = default; // destruktor
};

/*!
 * @brief Trieda - blok pre číselný výstup
 * @param Manager object graph_obj
 */
class MathOutput : public BlockBase{
public:
    MathOutput(Manager &graph_obj);
    void Compute() override;
    virtual ~MathOutput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre sčítanie dvoch čísel
 * @param Manager object graph_obj
 */
class MathAddBlock : public BlockBase{
public:
    MathAddBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MathAddBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre odčítanie dvoch čísel
 * @param Manager object graph_obj
 */
class MathSubBlock : public BlockBase{
public:
    MathSubBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MathSubBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre násobenie dvoch čísel
 * @param Manager object graph_obj
 */
class MathMulBlock : public BlockBase{
public:
    MathMulBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MathMulBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre delenie dvoch čísel
 * @param Manager object graph_obj
 */
class MathDivBlock : public BlockBase{
public:
    MathDivBlock(Manager &graph_obj);

    void Compute() override;

    virtual ~MathDivBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok odmocnenie čísla
 * @param Manager object graph_obj
 */
class MathSqrtBlock : public BlockBase{
public:
    MathSqrtBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MathSqrtBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre absolútnu hodnotu čísla
 * @param Manager object graph_obj
 */
class MathAbsBlock : public BlockBase{
public:
    MathAbsBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MathAbsBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre zistenie väčšieho z dvoch čísel
 * @param Manager object graph_obj
 */
class MathGTBlock : public BlockBase{
public:
    MathGTBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MathGTBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre zistenie menšieho z dvoch čísel
 * @param Manager object graph_obj
 */
class MathLTBlock : public BlockBase{
public:
    MathLTBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MathLTBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre výpočet sínusu čísla
 * @param Manager object graph_obj
 */
class MathSinBlock : public BlockBase{
public:
    MathSinBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MathSinBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre výpočet cosínusu čísla
 * @param Manager object graph_obj
 */
class MathCosBlock : public BlockBase{
public:
    MathCosBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MathCosBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre inkrementáciu čísla o 1
 * @param Manager object graph_obj
 */
class MathIncBlock : public BlockBase{
public:
    MathIncBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MathIncBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre dekrementáciu čísla o 1
 * @param Manager object graph_obj
 */
class MathDecBlock : public BlockBase{
public:
    MathDecBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MathDecBlock() = default; // destruktor
};


//----------MATICE----------


/*!
 * @brief Trieda - blok pre 2x2 maticový vstup
 * @param Manager object graph_obj
 */
class MatrixInput : public BlockBase{
public:
    MatrixInput(Manager &graph_obj);
    void Compute() override;
    virtual ~MatrixInput() = default; // destruktor
};

/*!
 * @brief Trieda - blok pre 2x2 maticový výstup
 * @param Manager object graph_obj
 */
class MatrixOutput : public BlockBase{
public:
    MatrixOutput(Manager &graph_obj);
    void Compute() override;
    virtual ~MatrixOutput() = default; // destruktor
};

/*!
 * @brief Trieda - blok pre 3x3 maticový vstup
 * @param Manager object graph_obj
 */
class Matrix3x3Input : public BlockBase{
public:
    Matrix3x3Input(Manager &graph_obj);
    void Compute() override;
    virtual ~Matrix3x3Input() = default; // destruktor
};

/*!
 * @brief Trieda - blok pre 3x3 maticový výstup
 * @param Manager object graph_obj
 */
class Matrix3x3Output : public BlockBase{
public:
    Matrix3x3Output(Manager &graph_obj);
    void Compute() override;
    virtual ~Matrix3x3Output() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2x2 maticové násobenie vektorom
 * @param Manager object graph_obj
 */
class MatMulVecBlock : public BlockBase{
public:
    MatMulVecBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MatMulVecBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3x3 maticové násobenie vektorom
 * @param Manager object graph_obj
 */
class Mat3x3MulVecBlock : public BlockBase{
public:
    Mat3x3MulVecBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~Mat3x3MulVecBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2x2 maticové sčítanie
 * @param Manager object graph_obj
 */
class MatrixAddBlock : public BlockBase{
public:
    MatrixAddBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MatrixAddBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3x3 maticové sčítanie
 * @param Manager object graph_obj
 */
class Matrix3x3AddBlock : public BlockBase{
public:
    Matrix3x3AddBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~Matrix3x3AddBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2x2 maticové násobenie
 * @param Manager object graph_obj
 */
class MatrixMulBlock : public BlockBase{
public:
    MatrixMulBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MatrixMulBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3x3 maticové násobenie
 * @param Manager object graph_obj
 */
class Matrix3x3MulBlock : public BlockBase{
public:
    Matrix3x3MulBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~Matrix3x3MulBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2x2 maticové odčítanie
 * @param Manager object graph_obj
 */
class MatrixSubBlock : public BlockBase{
public:
    MatrixSubBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MatrixSubBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3x3 maticové odčítanie
 * @param Manager object graph_obj
 */
class Matrix3x3SubBlock : public BlockBase{
public:
    Matrix3x3SubBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~Matrix3x3SubBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre výpočet determinantu matice 2x2
 * @param Manager object graph_obj
 */
class MatrixDeterminantBlock : public BlockBase{
public:
    MatrixDeterminantBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~MatrixDeterminantBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre výstup výpočtu determinantu matice 2x2
 * @param Manager object graph_obj
 */
class MatrixDeterminantOutput : public BlockBase{
public:
    MatrixDeterminantOutput(Manager &graph_obj);
    void Compute() override;
    virtual ~MatrixDeterminantOutput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre vstup výpočtu determinantu matice 2x2
 * @param Manager object graph_obj
 */
class MatrixDeterminantInput : public BlockBase{
public:
    MatrixDeterminantInput(Manager &graph_obj);
    void Compute() override;
    virtual ~MatrixDeterminantInput() = default; // destruktor
};


//----------VEKTORY----------


/*!
 * @brief Trieda - blok pre 2D vektorový vstup
 * @param Manager object graph_obj
 */
class VectorInput : public BlockBase{
public:
    VectorInput(Manager &graph_obj);
    void Compute() override;
    virtual ~VectorInput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2D vektorový výstup
 * @param Manager object graph_obj
 */
class VectorOutput : public BlockBase{
public:
    VectorOutput(Manager &graph_obj);
    void Compute() override;
    virtual ~VectorOutput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3D vektorový vstup
 * @param Manager object graph_obj
 */
class Vector3DInput : public BlockBase{
public:
    Vector3DInput(Manager &graph_obj);
    void Compute() override;
    virtual ~Vector3DInput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3D vektorový výstup
 * @param Manager object graph_obj
 */
class Vector3DOutput : public BlockBase{
public:
    Vector3DOutput(Manager &graph_obj);
    void Compute() override;
    virtual ~Vector3DOutput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2D sčítanie dvoch vektorov
 * @param Manager object graph_obj
 */
class VectorAddBlock : public BlockBase{
public:
    VectorAddBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~VectorAddBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2D odčítanie dvoch vektorov
 * @param Manager object graph_obj
 */
class VectorSubBlock : public BlockBase{
public:
    VectorSubBlock(Manager &graph_obj);
    void Compute() override;

    virtual ~VectorSubBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3D sčítanie dvoch vektorov
 * @param Manager object graph_obj
 */
class VectorAddBlock3D : public BlockBase{
public:
    VectorAddBlock3D(Manager &graph_obj);
    void Compute() override;
    virtual ~VectorAddBlock3D() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 3D odčítanie dvoch vektorov
 * @param Manager object graph_obj
 */
class VectorSubBlock3D : public BlockBase{
public:
    VectorSubBlock3D(Manager &graph_obj);
    void Compute() override;
    virtual ~VectorSubBlock3D() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre 2D skalárny súčin
 * @param Manager object graph_obj
 */
class VectorDotProductBlock2D : public BlockBase{
public:
    VectorDotProductBlock2D(Manager &graph_obj);
    void Compute() override;
    virtual ~VectorDotProductBlock2D() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre výstup 2D skalárneho súčinu
 * @param Manager object graph_obj
 */
class VectorDotOutput : public BlockBase{
public:
    VectorDotOutput(Manager &graph_obj);
    void Compute() override;
    virtual ~VectorDotOutput() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre násobenie 2D vektoru konštantou
 * @param Manager object graph_obj
 */
class VectorMulConstBlock : public BlockBase{
public:
    VectorMulConstBlock(Manager &graph_obj);
    void Compute() override;
    virtual ~VectorMulConstBlock() = default; // destruktor
};


/*!
 * @brief Trieda - blok pre násobenie 3D vektoru konštantou
 * @param Manager object graph_obj
 */
class VectorMulConstBlock3D : public BlockBase{
public:
    VectorMulConstBlock3D(Manager &graph_obj);
    void Compute() override;
    virtual ~VectorMulConstBlock3D() = default; // destruktor
};
