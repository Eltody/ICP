
#pragma once
#include <QGraphicsLinearLayout>
#include <QMainWindow>
#include <QAction>
#include <QColor>
#include <string>

#include "../core/Blocks.h"
#include "ui_BlockManager.h"


class UIBlockManager;

class BlockMenuAction : public QAction{
private:
    //! BlockType generovaného bloku
    BlockType t;
public:
    //! Action Konštruktor
    BlockMenuAction(BlockType t, const QIcon &icon);
    operator BlockType();
};

/**
 * @brief Úložisko pre všetky custom defined štýly
 */
class Style{
public:
    static const int PortMarginV;
    static const int PortNamePadding;

    static const int NodeFieldOffset; // offset pre umiestnenie textových polí
    static const int NodeFieldWidth; // šírka textových polí v IO blokov
    static const int NodeNamePadding; // odsadenie bloku
    static const int NodeNameHeight; // veľkosť mena bloku
    static const int NodeMinWidth; // minimum šírky bloku
    static const int NodeRoundSize;
    static const QColor NodeOutlineCol; // outline farba
    static const QColor NodeOutlineHighlightCol; // highlight outline farba
    static const QColor NodeBackgroundCol; // farba pozadia bloku
};


QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QLineEdit;
class QLabel;
QT_END_NAMESPACE

namespace Ui {
class ELITEEDITOR;
}


/**
 * @brief Trieda hlavného okna
 */
class ELITEEDITOR : public QMainWindow{
    Q_OBJECT
public:
    //! Konštruktor
	explicit ELITEEDITOR(UIBlockManager &g, QWidget *parent = 0);
    //! Deštruktor
    ~ELITEEDITOR();

protected:
    //! Vyvolaná akcia pri zatváraní schémy
	void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void buildMathInput();
    void buildMathOutput();
    void buildMathAdd();
    void buildMathSub();
    void buildMathMul();
    void buildMathDiv();
    void buildMathSqrt();
    void buildMathAbs();
    void buildMathGt();
    void buildMathLt();
    void buildMathSin();
    void buildMathCos();
    void buildMathInc();
    void buildMathDec();

    void buildVectorInput();
    void buildVectorInput3D();
    void buildVectorOutput();
    void buildVectorOutput3D();
    void buildVectorDotOut();
    void buildVectorAdd();
    void buildVectorAdd3D();
    void buildVectorSub();
    void buildVectorSub3D();
    void buildVectorMul();
    void buildVectorMul3D();
    void buildVectorDot();

    void buildMatrixInput();
    void buildMatrixOutput();
    void buildMatrixDetInput();
    void buildMatrixDetOutput();
    void buildMatrixAdd();
    void buildMatrixSub();
    void buildMatrixMul();
    void buildMatrixMulVec();
    void buildMatrixDet();
    void buildMatrix3In();
    void buildMatrix3Out();
    void buildMatrix3Add();
    void buildMatrix3Sub();
    void buildMatrix3Mul();


    void calc();
    void vect();
    void matr2();
    void matr3();
	void newFile();
	void open();
    void overlap();
	bool save();
	bool saveAs();
	void compute();
	void step();
	void reset();
	void help();

private:
	Ui::ELITEEDITOR *ui;
	UIBlockManager &graph;

    // praca so suborom
    void createActions();
    void createMenus();
	void deleteToolBars();
    void createToolBars();
    bool maybeSave();
    void loadFile(const QString &fileName, bool overlap);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);

    QString curFile;
    QMenu *fileMenu;
    QMenu *helpMenu;

    QToolBar *blockMenu;
	QToolBar *fileToolBar;
    QToolBar *actionToolBar;
    //! Toolbar s help buttonom
    QToolBar *helpToolBar;
	QToolBar *nameToolBar;

    QWidget *spacerWidget;
    QAction *calculatorBTN;
    QAction *vectorBTN;
    QAction *matrix2BTN;
    QAction *matrix3BTN;

    // praca s operaciami
    QAction *calcIn = new BlockMenuAction(MATH_INPUT, QIcon());
    QAction *calcOut = new BlockMenuAction(MATH_OUTPUT, QIcon());
    QAction *calcAdd = new BlockMenuAction(MATH_ADD, QIcon());
    QAction *calcSub = new BlockMenuAction(MATH_SUB, QIcon());
    QAction *calcMul = new BlockMenuAction(MATH_MUL, QIcon());
    QAction *calcDiv = new BlockMenuAction(MATH_DIV, QIcon());
    QAction *calcSqrt = new BlockMenuAction(MATH_SQRT, QIcon());
    QAction *calcAbs = new BlockMenuAction(MATH_ABS, QIcon());
    QAction *calcGt = new BlockMenuAction(MATH_GT, QIcon());
    QAction *calcLt = new BlockMenuAction(MATH_LT, QIcon());
    QAction *calcSin = new BlockMenuAction(MATH_SIN, QIcon());
    QAction *calcCos = new BlockMenuAction(MATH_COS, QIcon());
    QAction *calcInc = new BlockMenuAction(MATH_INC, QIcon());
    QAction *calcDec = new BlockMenuAction(MATH_DEC, QIcon());

    QAction *vectorInp = new BlockMenuAction(VECTOR_INPUT, QIcon());
    QAction *vectorInp3D = new BlockMenuAction(VECTOR3D_INPUT, QIcon());
    QAction *vectorOut = new BlockMenuAction(VECTOR_OUTPUT, QIcon());
    QAction *vectorOut3D = new BlockMenuAction(VECTOR3D_OUTPUT, QIcon());
    QAction *vectorDotOut = new BlockMenuAction(VECTOR_DOT_OUTPUT, QIcon());
    QAction *vectorAdd = new BlockMenuAction(VECTOR_ADD, QIcon());
    QAction *vectorAdd3D = new BlockMenuAction(VECTOR_ADD3D, QIcon());
    QAction *vectorSub = new BlockMenuAction(VECTOR_SUB, QIcon());
    QAction *vectorSub3D = new BlockMenuAction(VECTOR_SUB3D, QIcon());
    QAction *vectorMul = new BlockMenuAction(VECTOR_MUL_CONST, QIcon());
    QAction *vectorMul3D = new BlockMenuAction(VECTOR_MUL_CONST3D, QIcon());
    QAction *vectorDot = new BlockMenuAction(VECTOR_DOTPRODUCT, QIcon());

    QAction *matrixInp = new BlockMenuAction(MAT2_INPUT, QIcon());
    QAction *matrixOut = new BlockMenuAction(MAT2_OUTPUT, QIcon());
    QAction *matrixDetIn = new BlockMenuAction(MAT_DETERMINANT_INPUT, QIcon());
    QAction *matrixDetOut = new BlockMenuAction(MAT_DETERMINANT_OUTPUT, QIcon());
    QAction *matrixAdd = new BlockMenuAction(MAT_ADD, QIcon());
    QAction *matrixSub = new BlockMenuAction(MAT_SUB, QIcon());
    QAction *matrixMul = new BlockMenuAction(MAT_MUL, QIcon());
    QAction *matrixMulVec = new BlockMenuAction(MAT_MUL_VEC, QIcon());
    QAction *matrixDet = new BlockMenuAction(MAT_DETERMINANT, QIcon());
    QAction *matrix3In = new BlockMenuAction(MAT3_INPUT, QIcon());
    QAction *matrix3Out = new BlockMenuAction(MAT3_OUTPUT, QIcon());
    QAction *matrix3Add = new BlockMenuAction(MAT3_ADD, QIcon());
    QAction *matrix3Sub = new BlockMenuAction(MAT3_SUB, QIcon());
    QAction *matrix3Mul = new BlockMenuAction(MAT3_MUL, QIcon());

    // Akcie:
    //! Vytvorenie noveho suboru
	QAction *newBTN;
    //! Otvaranie suboru
	QAction *openBTN;
    //! Ukladanie suboru
    QAction *saveBTN;
    //! Import suboru
    QAction *importBTN;
    //! Vypocet celej schemy
    QAction *computeAct;
    //! Vypocet nasledujuceho bloku schemy
    QAction *stepAct;
    //! Nastavenie bloku ako nasledujuceho vykonavaneho bloku
    QAction *resetAct;
    //! Vymazanie bloku
	QAction *deleteAct;
    //! Ukáž Help Box
    QAction *helpAct;
};
