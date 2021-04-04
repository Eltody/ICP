#include <QtWidgets>
#include <QToolBar>
#include <QString>
#include <string>

#include "../core/blocks.h"
#include "blockeditor.h"
#include "ui_blockeditor.h"
#include "block_ui.h"
#include "graph_ui.h"


const int Style::ConnectionHoverSize = 15;
const QColor Style::ConnectionCol = QColor(255, 255, 255);

const int Style::GraphLoadPadding = 15;

const int Style::NodeFieldOffset = 25;
const int Style::NodeFieldWidth = 65;
const int Style::NodeNamePadding = 14;
const int Style::NodeNameHeight = 40;
const int Style::NodeMinWidth = 60;
const int Style::NodeRoundSize = 5;
const QColor Style::NodeOutlineCol = QColor(0, 0, 0);
const QColor Style::NodeOutlineHighlightCol = QColor(76, 76, 76);
const QColor Style::NodeBackgroundCol = QColor(76, 76, 76);

const int Style::TooltipRoundSize = 10;
const int Style::TooltipPadding = 10;
const int Style::TooltipHPadding = 18;
const QColor Style::TooltipOutlineCol = QColor(0, 0, 0, 0);
const QColor Style::TooltipBackgroundCol = QColor(76, 76, 76);
const QColor Style::TooltipTextCol = QColor(255, 255, 255);

const int Style::PortDrawSize = 10;
const int Style::PortSize = 25;
const int Style::PortMarginV = 30;
const int Style::PortNamePadding = 15;
const QColor Style::PortOutlineCol = QColor(0, 0, 0);
const QColor Style::PortFreeCol = QColor(255, 255, 255);
const QColor Style::PortHoverCol = QColor(175, 175, 175);

bool calcIsOpen = false;
bool vectIsOpen = false;
bool matrIsOpen = false;


BLOCKEDITOR::BLOCKEDITOR(GraphUI &g, QWidget *parent) :
	QMainWindow(parent),  ui(new Ui::BLOCKEDITOR), graph(g){
	ui->setupUi(this);

    QApplication::setApplicationDisplayName("(j)Elitný editor");
	createActions();
	createToolBars();
	setCurrentFile("");
	setUnifiedTitleAndToolBarOnMac(true);

	setCentralWidget(&graph);
	show();

    graph.onGraphChange([this](){this->setWindowModified(true);});
}

BLOCKEDITOR::~BLOCKEDITOR(){
	//avoid destruction of graph, which is destructed externally
	centralWidget()->setParent(nullptr);

	deleteActions();
	delete ui;
}

void BLOCKEDITOR::deleteActions(){
    delete newBTN;
    delete openBTN;
    delete saveBTN;
    delete importBTN;
	delete computeAct;
	delete stepAct;
	delete resetAct;
	delete helpAct;
}

void BLOCKEDITOR::createActions(){
    newBTN = new QAction(QIcon(":/icons/new.png"), "&Nový...", this);
    newBTN->setShortcuts(QKeySequence::New);
    newBTN->setStatusTip("Vytvoriť novú plochu");
    connect(newBTN, SIGNAL(triggered()), this, SLOT(newFile()));

    openBTN = new QAction(QIcon(":/icons/open.png"), "&Otvoriť...", this);
    openBTN->setShortcuts(QKeySequence::Open);
    openBTN->setStatusTip("Otvoriť uložený súbor");
    connect(openBTN, SIGNAL(triggered()), this, SLOT(open()));

    importBTN = new QAction(QIcon(":/icons/import.png"), "&Vložiť", this);
    importBTN->setStatusTip("Vloží súbor do aktuálnej plochy");
    connect(importBTN, SIGNAL(triggered()), this, SLOT(merge()));

    saveBTN = new QAction(QIcon(":/icons/save.png"), "&Uložiť", this);
    saveBTN->setShortcuts(QKeySequence::Save);
    saveBTN->setStatusTip("Uloží plochu na disk");
    connect(saveBTN, SIGNAL(triggered()), this, SLOT(save()));

    computeAct = new QAction(QIcon(":/icons/compute.png"), "&Vypočítať (F3)", this);
	computeAct->setShortcut(QKeySequence::fromString("F3", QKeySequence::NativeText));
    computeAct->setStatusTip("Vypočíta všetky bloky");
	connect(computeAct, SIGNAL(triggered()), this, SLOT(compute()));

    stepAct = new QAction(QIcon(":/icons/step.png"), "&Krokovať (F4)", this);
	stepAct->setShortcut(QKeySequence::fromString("F4", QKeySequence::NativeText));
    stepAct->setStatusTip("Vypočíta jeden krok");
	connect(stepAct, SIGNAL(triggered()), this, SLOT(step()));

    resetAct = new QAction(QIcon(":/icons/reset.png"), "&Obnoviť (F5)", this);
	resetAct->setShortcut(QKeySequence::fromString("F5", QKeySequence::NativeText));
    resetAct->setStatusTip("Vynuluje výpočet");
	connect(resetAct, SIGNAL(triggered()), this, SLOT(reset()));

    helpAct = new QAction(QIcon(":/icons/help.png"), "&Nápoveda", this);
    helpAct->setStatusTip("Zobrazí nápovedu");
	helpAct->setShortcuts(QKeySequence::HelpContents);
	connect(helpAct, SIGNAL(triggered()), this, SLOT(help()));
}

void BLOCKEDITOR::createToolBars(){
    connect(calcIn, SIGNAL(triggered()), this , SLOT(buildMathIn()));


    calculatorBTN = new QAction(QIcon(":/icons/expandCalc.png"), "", this);
    calculatorBTN->setStatusTip("Základné matematické operácie");
    connect(calculatorBTN, SIGNAL(triggered()), this, SLOT(calc()));

    vectorBTN = new QAction(QIcon(":/icons/expandVect.png"), "", this);
    vectorBTN->setStatusTip("Operácie nad vektormi");
    connect(vectorBTN, SIGNAL(triggered()), this, SLOT(vect()));

    matrixBTN = new QAction(QIcon(":/icons/expandMatr.png"), "", this);
    matrixBTN->setStatusTip("Operácie nad maticami");
    connect(matrixBTN, SIGNAL(triggered()), this, SLOT(matr()));

    blockMenu = new QToolBar();
    addToolBar(Qt::LeftToolBarArea, blockMenu);
    blockMenu->setIconSize(QSize(226, 45));
    blockMenu->setFixedWidth(226);
    blockMenu->setMovable(false);
    blockMenu->addAction(calculatorBTN);
    blockMenu->addAction(vectorBTN);
    blockMenu->addAction(matrixBTN);

    fileToolBar = addToolBar("Súbor");
    fileToolBar->setMovable(false);
    fileToolBar->addAction(newBTN);
    fileToolBar->addAction(openBTN);
    fileToolBar->addAction(saveBTN);
    fileToolBar->addAction(importBTN);

    actionToolBar = addToolBar("Akcie");
    actionToolBar->setMovable(false);
	actionToolBar->addAction(computeAct);
	actionToolBar->addAction(stepAct);
    actionToolBar->addAction(resetAct);

    spacerWidget = new QWidget();
    spacerWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    helpToolBar = addToolBar("Nápoveda");
    helpToolBar->setMovable(false);
    helpToolBar->addWidget(spacerWidget);
	helpToolBar->addAction(helpAct);
}

void BLOCKEDITOR::buildMathIn(){
    graph.addBlock(MATH_INPUT);
}

void BLOCKEDITOR::closeEvent(QCloseEvent *event){
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void BLOCKEDITOR::calc(){
    if (vectIsOpen == true){
        vect();
    } else if (matrIsOpen == true){
        matr();
    }
    if (calcIsOpen == false){
        calcIsOpen = true;
        calculatorBTN->setIcon(QIcon(":/icons/contractCalc.png"));
        vectorBTN->setIcon(QIcon(":/icons/btmVect.png"));
        blockMenu->removeAction(matrixBTN);
        blockMenu->removeAction(vectorBTN);
        blockMenu->addAction(calcIn);
        blockMenu->addAction(calcOut);
        blockMenu->addAction(calcSub);
        blockMenu->addAction(calcMul);
        blockMenu->addAction(calcDiv);
        blockMenu->addAction(calcSqrt);
        blockMenu->addAction(calcAbs);
        blockMenu->addAction(calcGt);
        blockMenu->addAction(calcLt);
        blockMenu->addAction(calcSin);
        blockMenu->addAction(calcCos);
        blockMenu->addAction(calcInc);
        blockMenu->addAction(calcDec);
        blockMenu->addAction(vectorBTN);
        blockMenu->addAction(matrixBTN);
    } else{
        calcIsOpen = false;
        calculatorBTN->setIcon(QIcon(":/icons/expandCalc.png"));
        vectorBTN->setIcon(QIcon(":/icons/expandVect.png"));
        blockMenu->removeAction(calcIn);
        blockMenu->removeAction(calcOut);
        blockMenu->removeAction(calcSub);
        blockMenu->removeAction(calcMul);
        blockMenu->removeAction(calcDiv);
        blockMenu->removeAction(calcSqrt);
        blockMenu->removeAction(calcAbs);
        blockMenu->removeAction(calcGt);
        blockMenu->removeAction(calcLt);
        blockMenu->removeAction(calcSin);
        blockMenu->removeAction(calcCos);
        blockMenu->removeAction(calcInc);
        blockMenu->removeAction(calcDec);
    }
}

void BLOCKEDITOR::vect(){
    if (calcIsOpen == true){
        calc();
    } else if (matrIsOpen == true){
        matr();
    }
    if (vectIsOpen == false){
        vectIsOpen = true;
        vectorBTN->setIcon(QIcon(":/icons/contractVect.png"));
        matrixBTN->setIcon(QIcon(":/icons/btmMatr.png"));
        blockMenu->removeAction(matrixBTN);
        blockMenu->addAction(vectorInp);
        blockMenu->addAction(vectorInp3D);
        blockMenu->addAction(vectorOut);
        blockMenu->addAction(vectorOut3D);
        blockMenu->addAction(vectorDotOut);
        blockMenu->addAction(vectorAdd);
        blockMenu->addAction(vectorAdd3D);
        blockMenu->addAction(vectorSub);
        blockMenu->addAction(vectorSub3D);
        blockMenu->addAction(vectorMul);
        blockMenu->addAction(vectorMul3D);
        blockMenu->addAction(vectorDot);
        blockMenu->addAction(matrixBTN);
    } else{
        vectIsOpen = false;
        vectorBTN->setIcon(QIcon(":/icons/expandVect.png"));
        matrixBTN->setIcon(QIcon(":/icons/expandMatr.png"));
        blockMenu->removeAction(vectorInp);
        blockMenu->removeAction(vectorInp3D);
        blockMenu->removeAction(vectorOut);
        blockMenu->removeAction(vectorOut3D);
        blockMenu->removeAction(vectorDotOut);
        blockMenu->removeAction(vectorAdd);
        blockMenu->removeAction(vectorAdd3D);
        blockMenu->removeAction(vectorSub);
        blockMenu->removeAction(vectorSub3D);
        blockMenu->removeAction(vectorMul);
        blockMenu->removeAction(vectorMul3D);
        blockMenu->removeAction(vectorDot);
    }
}

void BLOCKEDITOR::matr(){
    if (calcIsOpen == true){
        calc();
    } else if (vectIsOpen == true){
        vect();
    }
    if (matrIsOpen == false){
        matrIsOpen = true;
        matrixBTN->setIcon(QIcon(":/icons/contractMatr.png"));
        blockMenu->addAction(matrixInp);
        blockMenu->addAction(matrix3In);
        blockMenu->addAction(matrixOut);
        blockMenu->addAction(matrix3Out);
        blockMenu->addAction(matrixAdd);
        blockMenu->addAction(matrix3Add);
        blockMenu->addAction(matrixSub);
        blockMenu->addAction(matrix3Sub);
        blockMenu->addAction(matrixMul);
        blockMenu->addAction(matrix3Mul);
        blockMenu->addAction(matrixMulVec);
        blockMenu->addAction(matrixDetIn);
        blockMenu->addAction(matrixDetOut);
        blockMenu->addAction(matrixDet);
    } else{
        matrIsOpen = false;
        matrixBTN->setIcon(QIcon(":/icons/expandMatr.png"));
        blockMenu->removeAction(matrixInp);
        blockMenu->removeAction(matrix3In);
        blockMenu->removeAction(matrixOut);
        blockMenu->removeAction(matrix3Out);
        blockMenu->removeAction(matrixAdd);
        blockMenu->removeAction(matrix3Add);
        blockMenu->removeAction(matrixSub);
        blockMenu->removeAction(matrix3Sub);
        blockMenu->removeAction(matrixMul);
        blockMenu->removeAction(matrix3Mul);
        blockMenu->removeAction(matrixMulVec);
        blockMenu->removeAction(matrixDetIn);
        blockMenu->removeAction(matrixDetOut);
        blockMenu->removeAction(matrixDet);
    }
}

void BLOCKEDITOR::newFile(){
    if(maybeSave()){
		graph.clearGraph();
		setCurrentFile(QString::fromStdString(""));
	}
}

void BLOCKEDITOR::open(){
    if (maybeSave()){
		QString fileName = QFileDialog::getOpenFileName(this,
            QString(), QString(), QString("Súbory dizajnéru (*.jee)"));
		if (!fileName.isEmpty())
			loadFile(fileName, false);
	}
}

void BLOCKEDITOR::merge(){
	QString fileName = QFileDialog::getOpenFileName(this,
        QString("Vložiť"), QString(), QString("Súbory dizajnéru (*.jee)"));
	if (!fileName.isEmpty())
		loadFile(fileName, true);
}

bool BLOCKEDITOR::save(){
    if (curFile.isEmpty()){
		return saveAs();
    } else{
		return saveFile(curFile);
	}
}

bool BLOCKEDITOR::saveAs(){
	QFileDialog dialog(this);
	dialog.setWindowModality(Qt::WindowModal);
	dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setNameFilter("Súbory dizajnéru (*.jee)");
	std::string saveName;
    if (curFile.isEmpty()){
		if (graph.GetName().empty()){
            saveName = "plocha1.jee";
        } else{
            saveName = graph.GetName() + ".jee";
		}
    } else{
		saveName = curFile.toStdString();
	}
	dialog.selectFile(saveName.c_str());
	QStringList files;
    if (dialog.exec()){
		files = dialog.selectedFiles();
    } else{
		return false;
    }
	return saveFile(files.at(0));
}

void BLOCKEDITOR::compute(){
	graph.computeAll();
}

void BLOCKEDITOR::step(){
	graph.computeStep();
}

void BLOCKEDITOR::reset(){
	graph.computeReset();
}

void BLOCKEDITOR::help(){
    QMessageBox::about(this, "Nápoveda",
                             "<h1>(j)Elitný editor - nápoveda</h1>"
                             "<h2>Bloky:</h2>"
                             "<p><b>Pre vytvorenie bloku klikni pravým tlačítkom na myši a vyber požadovaný blok.</p>"
                             "<p><b>Pre odstránenie bloku klikni na daný blok pravým tlačítkom na myši a vyber 'Odstrániť'.</p>"
                             "<h2>Prepojenia:</h2>"
                             "<p><b>Pre vytvorenie prepojenia medzi dvomi blokmi klikni ľavým tlačítkom na myši na výstup jedného a následne vstup druhého bloku.</p>"
                             "<p><b>Pre upravenie prepojenia klikni ľavým tlačítkom na myši na vstup bloku a následne klikni na požadovaný výstup.</p>"
                             "<p><b>Pre odstránenie prepojenia klikni ľavým tlačítkom na myši na vstup bloku a následne klikni do priestoru.</p>"
                             "<h2>Výpočty:</h2>"
                             "<p><b>Pre výpočet všetkých blokov naraz klikni na tlačidlo 'Vypočítať', alebo stlač F3 na klávesnici.</p>"
                             "<p><b>Pre výpočet jedného kroku klikni na tlačidlo 'Krokovať', alebo stlač F4 na klávesnici.</p>"
                             "<p><b>Pre vynulovanie výpočtov klikni na tlačidlo 'Obnoviť', alebo stlač F5 na klávesnici.</p>"
                             "<h1>O (j)Elitnom editore</h1>"
                             "<p><b>Autori:</b> Martin Rakús, Tomáš Zaťko</p>"
					   );
}

bool BLOCKEDITOR::maybeSave(){
    if(this->isWindowModified()){
        QMessageBox ret(QMessageBox::Question, tr("Uložiť?"), tr("Plocha bola upravená.\nPrajete si uložiť vykonané zmeny?"), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        ret.setButtonText(QMessageBox::Save, tr("Uložiť"));
        ret.setButtonText(QMessageBox::Discard, tr("Zahodiť"));
        ret.setButtonText(QMessageBox::Cancel, tr("Zrušiť"));
        switch(ret.exec()){
            case QMessageBox::Save:
                return save();
                break;
            case QMessageBox::Cancel:
                return false;
                break;
            case QMessageBox::Discard:
                break;
            default:
                break;
        }
	}
	return true;
}

void BLOCKEDITOR::loadFile(const QString &fileName, bool merge){
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "(j)Elitný editor",
                                   QString::fromStdString("Nemožno otvoriť súbor %1:\n%2.")
							 .arg(fileName)
							 .arg(file.errorString()));
		return;
	}

	QTextStream in(&file);
#ifndef QT_NO_CURSOR
	QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
	// FILE LOADING
	std::stringstream funcIn;
	while(!in.atEnd()){
		funcIn << in.read(1024).toStdString() << '\n';
	}

	if(!graph.loadGraph(funcIn, merge)) {
        QMessageBox::warning(this, "(j)Elitný editor",
                                   QString::fromStdString("Chyba čítania súboru."));
	}
#ifndef QT_NO_CURSOR
	QApplication::restoreOverrideCursor();
#endif

    statusBar()->showMessage("Súbor bol otvorený", 2000);

	if(!merge){
		setCurrentFile(fileName);
		setWindowModified(false);
	}
}


bool BLOCKEDITOR::saveFile(const QString &fileName){
	QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "(j)Elitný editor",
                             QString::fromStdString("Nemožno uložiť súbor %1:\n%2.")
							 .arg(fileName)
							 .arg(file.errorString()));
		return false;
	}

	QTextStream out(&file);
#ifndef QT_NO_CURSOR
	QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
	// FILE SAVING
	std::stringstream funcOut;
	funcOut = graph.saveGraph();

    while(funcOut.good()){
		std::string str;
		std::getline(funcOut, str);
		out << QString::fromStdString(str) << '\n';
	}
    if(funcOut.fail()){
        QMessageBox::warning(this, "(j)Elitný editor",
                                   QString::fromStdString("Chyba zápisu súboru."));
	}
#ifndef QT_NO_CURSOR
	QApplication::restoreOverrideCursor();
#endif

	setCurrentFile(fileName);
    statusBar()->showMessage("Súbor bol uložený", 2000);
	return true;
}

void BLOCKEDITOR::setCurrentFile(const QString &fileName){
	curFile = fileName;
	setWindowModified(false);
	QString shownName = curFile;
    if (curFile.isEmpty()){
        shownName = "plocha.jee";
	}
	setWindowFilePath(shownName);
}
