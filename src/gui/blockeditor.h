/** ICP Project 2017/2018: BlockEditor
 * @file blockeditor.h
 * @brief Block appearance
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#ifndef BLOCKEDITOR_H
#define BLOCKEDITOR_H

#include <QGraphicsLinearLayout>
#include <QMainWindow>
#include "graph_ui.h"

#include <QColor>

/**
 * @brief Container for all custom defined styles
 */
class Style{
public:
    //! Port connect diameter
    static const int PortSize;
    //! Port draw diameter
    static const int PortDrawSize;
    //! Port margin
    static const int PortMarginV;
    //! Port name padding
    static const int PortNamePadding;
    //! Port outline color
    static const QColor PortOutlineCol;
    //! Unoccupied port color
    static const QColor PortFreeCol;
    //! Port color when hovered over
    static const QColor PortHoverCol;

    //! Connection line width when hovered
    static const int ConnectionHoverSize;
    //! Connection line color
    static const QColor ConnectionCol;

    //! Padding around the graph widget
    static const int GraphLoadPadding;

    //! Offset for positioning text fields in IO blocks
    static const int NodeFieldOffset;
    //! Width of text fields in IO blocks
    static const int NodeFieldWidth;
    //! Block name padding
    static const int NodeNamePadding;
    //! Block name Height
    static const int NodeNameHeight;
    //! Block's minimum width
    static const int NodeMinWidth;
    //! Corner rounding size on block
    static const int NodeRoundSize;
    //! Block's outline color
    static const QColor NodeOutlineCol;
    //! Block's highlight outline color
    static const QColor NodeOutlineHighlightCol;
    //! Background block color
    static const QColor NodeBackgroundCol;

    //! Tooltip corner rounding size
    static const int TooltipRoundSize;
    //! Tooltip padding
    static const int TooltipPadding;
    //! Tooltip horizontal padding
    static const int TooltipHPadding;
    //! Tooltip outline color
    static const QColor TooltipOutlineCol;
    //! Tooltip background color
    static const QColor TooltipBackgroundCol;
    //! Tooltip text color
    static const QColor TooltipTextCol;
};


QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QLineEdit;
class QLabel;
QT_END_NAMESPACE

namespace Ui {
class BLOCKEDITOR;
}


/**
 * @brief Main window class
 * This class is a QWidget that is parent to all graphic elements within the window.
 * All other control widgets (except the dropdown menus for adding/removing blocks) are declared here.
 */
class BLOCKEDITOR : public QMainWindow{
    Q_OBJECT
public:
	//! Constructor
	explicit BLOCKEDITOR(GraphUI &g, QWidget *parent = 0);
	//! Destructor
	~BLOCKEDITOR();

protected:
	//! Event called when closing the opened scheme
	void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void buildMathIn();
    //! Button slot called when opening standard calculator operations
    void calc();
    //! Button slot called when opening vector operations
    void vect();
    //! Button slot called when opening 2x2 matrix operations
    void matr2();
    //! Button slot called when opening 3x3 matrix operations
    void matr3();
	//! Button slot to call when creating a new scheme
	void newFile();
	//! Button slot to call when opening a file
	void open();
	//! Button slot to call when merging a file into existing scheme
	void merge();
	//! Button slot to call when opening a file
	bool save();
	//! Button slot to call when saving file a new one
	bool saveAs();
	//! Button slot called when computing the whole scheme
	void compute();
	//! Button slot called when computing one block from compute queue
	void step();
	//! Button slot called to set first block as next in compute queue
	void reset();
	//! Button slot called when opening help
	void help();

private:
	Ui::BLOCKEDITOR *ui;
	GraphUI &graph;

	//! Function that destroys QActions for buttons
	void deleteActions();
	//! Function that creates QActions for buttons
    void createActions();
	//! Sets up menu bar with all buttons
    void createMenus();
	//! Destroys toolbars
	void deleteToolBars();
	//! Place buttons on toolbars
    void createToolBars();
	//! Asks user to save changes before quitting
    bool maybeSave();
	//! Creates dialogs for opening a scheme file
	void loadFile(const QString &fileName, bool merge);
	//! Creates dialogs for saving a scheme to disk
    bool saveFile(const QString &fileName);
	//! Sets current file name in window title
    void setCurrentFile(const QString &fileName);

	//! Currently edited file's name
    QString curFile;

	//! Dialog used for opening and closing files
    QMenu *fileMenu;
	//! Dialog used for help and about boxes
    QMenu *helpMenu;

    //! Menu with available blocks
    QToolBar *blockMenu;
	//! Toolbar with file buttons
	QToolBar *fileToolBar;
	//! Toolbar with buttons related to computing blocks
    QToolBar *actionToolBar;
	//! Toolbar with a help button
    QToolBar *helpToolBar;
	//! Toolbar with a name of currently edited scheme
	QToolBar *nameToolBar;

    //! Widget that right-aligns the scheme name
    QWidget *spacerWidget;

    //! Action for opening standard calculator operations
    QAction *calculatorBTN;
    //! Action for opening vector operations
    QAction *vectorBTN;
    //! Action for opening 2x2 matrix operations
    QAction *matrix2BTN;
    //! Action for opening 3x3 matrix operations
    QAction *matrix3BTN;

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

	//! Action for creating a new file
	QAction *newBTN;
	//! Action for opening a file
	QAction *openBTN;
	//! Action for saving a file
    QAction *saveBTN;
    //! Action for importing a file
    QAction *importBTN;
	//! Action for computing the whole scheme
    QAction *computeAct;
	//! Action for computing next block in the compute queue
    QAction *stepAct;
	//! Action that sets the first block as next in compute queue
    QAction *resetAct;
	//! Action for deleting a block
	QAction *deleteAct;
	//! Action for showing the help box
    QAction *helpAct;
};

#endif // BLOCKEDITOR_H
