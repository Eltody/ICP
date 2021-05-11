/*! VUT FIT ICP
 * @file EliteEditor.h
 * @brief Header súbor pre GUI reprezentáciu blokov
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#pragma once
#include <QPainterPath>
#include <QApplication>
#include <QPaintEvent>
#include <QLineEdit>
#include <QPainter>
#include <QWidget>
#include <list>

#include <utility>
#include <algorithm>

#include "EliteEditor.h"
#include "ui_BlockPort.h"
#include "ui_BlockManager.h"

#include "../core/BlockBase.h"

/**
 * @brief GUI reprezentácia bloku
 */
template <typename BlockBaseT>
class UIBlock : public QWidget, public BlockBaseT{
private:
    //! Vektory vstupných a výstupných portov
	std::vector<InPortUI> inputs; // Should be const vector of non const elements, but this requires custom implementation of vector!
	std::vector<OutPortUI> outputs; // Should be const vector of non const elements, but this requires custom implementation of vector!
	QLabel label;
	bool drag = false;
    //! Highlight status bloku
	bool highlight = false;
    //! Pozícia bloku
	QPoint drag_p, offset;
protected:
    //! Výška a šírka bloku
	int width_, height_;

public:
	/**
     * @brief UIBlock konštruktor
	 */
    explicit UIBlock(const BlockBaseT &b, QWidget *parent = nullptr)
        : QWidget(parent), BlockBaseT(b), label(b.name.c_str(), this){
		setMouseTracking(true);
		for(size_t i = 0; i < BlockBaseT::InputCount(); i++) {
			inputs.push_back(InPortUI(InPort(BlockBaseT::Input(i), *this), parent));
		}
		for(size_t i = 0; i < BlockBaseT::OutputCount(); i++) {
			outputs.push_back(OutPortUI(OutPort(BlockBaseT::Output(i), *this), parent));
		}

		int input_w = 0;
		int output_w = 0;
		if (inputs.size()>0) {
			input_w = (*std::max_element(inputs.begin(), inputs.end(),
				[] (const InPortUI &a, const InPortUI &b) { return a.getWidth() < b.getWidth(); }
			)).getWidth();
		}
		if (outputs.size()>0) {
			output_w = (*std::max_element(outputs.begin(), outputs.end(),
				[] (const OutPortUI &a, const OutPortUI &b) { return a.getWidth() < b.getWidth(); }
			)).getWidth();
		}

        height_ = (static_cast<int>(std::max(inputs.size(), outputs.size()))) * Style::PortMarginV +
                 std::max(Style::PortMarginV, Style::NodeNameHeight);
        width_ = std::max(input_w + output_w, Style::NodeMinWidth);
        width_ = std::max(width_, Style::NodeNamePadding * 5 + QApplication::fontMetrics().width(label.text()));

        resize(width_ + 1, height_ + 1);

        Move(rand() % 436 + 97, rand() % 340 + 60);

		show();
		this->label.show();
	}

	/**
     * @brief Pozícia kde bude blok vložený
	 */
    QPoint Pos() const{
		return (pos() - offset);
	}

	/**
     * @brief Generuje ID portu
     * @param port Vstupný port
     * @return Pri úspešnom vykonaní vráti ID, inak -1
	 */
    int getPortID(const InPort &port) const{
		int idx = 0;
        for (const InPortUI &p : inputs){
			if (&p == &port){
				return idx;
			}
			idx++;
		}
		return -1;
	}

	/**
     * @brief Generuje ID portu
     * @param port Výstupný port
     * @return Pri úspešnom vykonaní vráti ID, inak -1
	 */
    int getPortID(const OutPort &port) const{
		int idx = 0;
        for (const OutPortUI &p : outputs){
			if (&p == &port){
				return idx;
			}
			idx++;
		}
		return -1;
	}

	/**
     * @brief Vráti referenciu do vstupného portu špecifikovaného s OID
     * @param id ID portu
     * @return Vracia adresu portu
	 */
    InPort & Input(std::size_t id){
		return inputs[id];
	}

    //! Vracia počet vstupov bloku
    std::size_t InputCount(){
		return inputs.size();
	}

	/**
     * @brief Vráti referenciu do výstupného portu špecifikovaného s ID
     * @param id ID portu
     * @return Vracia adresu portu
	 */
    OutPort & Output(std::size_t id){
		return outputs[id];
	}

    //! Vráti počet výstupov bloku
    std::size_t OutputCount(){
		return outputs.size();
	}

    //! Presun bloku s offsetom
	void updateOffset(QPoint offset){
		auto p = Pos();
		this->offset = offset;
		Move(p.x(), p.y());
	}

	/**
     * @brief Moves block to a specified location Presunutie bloku na špecifikovanú lokáciu
     * @param x X-ová pozícia
     * @param y Y-ová pozícia
	 */
    virtual void Move(int x, int y){
		x += this->offset.x();
		y += this->offset.y();

		move(x, y);

        label.move(0, Style::NodeNamePadding);
		label.setFixedWidth(width_);
		label.setAlignment(Qt::AlignCenter);

        int offset = std::max(Style::PortMarginV, Style::NodeNameHeight);
        for(auto &in : inputs){
			in.Move(x, y + offset);
            offset += Style::PortMarginV;
		}
        offset = std::max(Style::PortMarginV, Style::NodeNameHeight);
        for(auto &out : outputs){
			out.Move(x + width_, y + offset);
            offset += Style::PortMarginV;
		}
	}

    //! Zmena highlight statusu bloku
    void Highlight(bool enable){
		this->highlight = enable;
		update();
	}

protected:
    //! Vykreslovanie bloku
    void paintEvent(QPaintEvent *){
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);
		QPainterPath path;

        path.addRoundedRect(QRectF(.5, .5, width_, height_), Style::NodeRoundSize, Style::NodeRoundSize);

        painter.fillPath(path, QBrush(Style::NodeBackgroundCol));

        if (highlight){
			QPainterPath h;
            h.addRoundedRect(QRectF(2.5, 2.5, width_ - 4, height_ - 4), Style::NodeRoundSize, Style::NodeRoundSize);

            QPen p(Style::NodeOutlineHighlightCol);
			p.setWidth(5);

			painter.strokePath(h, p);
		}

        painter.strokePath(path, QPen(Style::NodeOutlineCol));
	}
    void mouseMoveEvent(QMouseEvent *event){
		static_cast<UIBlockManager&>(this->graph).hideHoverConnectionUI();
		if(drag){
			QPoint tmp = Pos() + event->pos() - drag_p;
			Move(tmp.x(), tmp.y());
		}
	}
    void mousePressEvent(QMouseEvent *event){
		setFocus();
        if(event->button() == Qt::LeftButton){
			drag = true;
			drag_p = event->pos();
		}
        else if (event->button() == Qt::RightButton){
			static_cast<UIBlockManager&>(this->graph).blockContextMenu(this);
		}
	}

    void mouseReleaseEvent(QMouseEvent *){
		drag = false;
	}

    void enterEvent(QEvent *){
		static_cast<UIBlockManager&>(this->graph).hideHoverConnectionUI();
	}
};

/**
 * @brief Textové okno pre vstupný blok
 */
class TextEdit : public QLineEdit{
private:

	std::function<void(void)> callback;
	bool err = false;
	QString prev;
public:
	TextEdit(QWidget *parent, std::function<void(void)> callback)
        : QLineEdit(parent), callback(callback){ }
    void ErrorColor(bool err){
		this->err = err;
	}
protected:
    void focusOutEvent(QFocusEvent *e){
		QLineEdit::focusOutEvent(e);
		if (text() != prev) { callback(); }
		prev = text();
	}
    void keyPressEvent(QKeyEvent *e){
		QLineEdit::keyPressEvent(e);
		if (text() != prev) { callback(); }
		prev = text();
	}
    void paintEvent(QPaintEvent *e){
		QLineEdit::paintEvent(e);
		if(err){
			QPainter painter(this);
			painter.setBrush(QColor(255, 0, 0, 64));
			painter.drawRect(0, 0, width() - 1, height() - 1);
		}
	}
};

/**
 * @brief GUI reprezentácia vstupného bloku
 */
template <typename BlockBaseT>
class InputBlockUI : public UIBlock<BlockBaseT>{
private:
	int orig_w, orig_h;
	int text_in_off;
	std::map<std::string, TextEdit*> text_in;
	void update_output() {
		this->graph.computeReset();
        Type &val = this->Output(0).Value();
		for(auto l : text_in){
			bool ok;
			val[l.first] = l.second->text().toDouble(&ok);
			if(!ok){
				val[l.first] = 0.0;
				l.second->ErrorColor(true);
			} else {
				l.second->ErrorColor(false);
			}
		}
	}
public:
    explicit InputBlockUI(const UIBlock<BlockBaseT> &b, QWidget *parent = nullptr)
        : UIBlock<BlockBaseT>(b, parent), orig_w(this->width_), orig_h(this->height_){
		auto data = this->Output(0).Value().Data();
		text_in_off = 0;
		for(auto &el : data){
            text_in_off = std::max(text_in_off, QApplication::fontMetrics().width((el.first + " : ").c_str()));
		}
        int off = Style::NodeNameHeight - 3;

		for(auto &el : data){
			auto l = new TextEdit(this, [this](){this->update_output();});
			l->show();
			l->setText("0");
            l->resize(Style::NodeFieldWidth, l->height());
            l->move(Style::PortNamePadding + text_in_off, off);
			text_in.insert(std::pair<std::string, TextEdit*>(el.first.c_str(), l));
            off += Style::NodeFieldOffset;
		}
		update_output();
	}
    bool Computable() {
		return false;
	}
	~InputBlockUI(){
		for(auto l : text_in){
			delete l.second;
		}
	}
    void Move(int x, int y)
	{
        this->width_ = this->orig_w - static_cast<OutPortUI&>(this->Output(0)).getWidth() + text_in_off + Style::NodeFieldWidth;
		int cnt = static_cast<int>(text_in.size()) - 1;
        this->height_ = this->orig_h + Style::NodeFieldOffset * (cnt < 0 ? 0 : cnt);
		this->resize(this->width_ + 1, this->height_ + 1);
        UIBlock<BlockBaseT>::Move(x, y);
	}
protected:
    void paintEvent(QPaintEvent *event) {
        UIBlock<BlockBaseT>::paintEvent(event);

        int h = QApplication::fontMetrics().height();

		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);

        int offset = Style::NodeNameHeight + h - 2;
		for(const auto &el : text_in){
            painter.drawText(Style::PortNamePadding, offset, (el.first + " : ").c_str());
            offset += Style::NodeFieldOffset;
		}
	}
};

/**
 * @brief GUI reprezentácia výstupného bloku
 */
template <typename BlockBaseT>
class OutputBlockUI : public UIBlock<BlockBaseT>{
private:
	int orig_w, orig_h;
public:
    explicit OutputBlockUI(const UIBlock<BlockBaseT> &b, QWidget *parent = nullptr)
        : UIBlock<BlockBaseT>(b, parent), orig_w(this->width_), orig_h(this->height_) {
		this->Input(0).onConnectionChange([this](Ports &){this->update();});
		this->Input(0).onValueChange([this](Ports &){this->update();});
	}
    bool Computable(){
		return false;
	}
    void updateBlockSize(){
		int w, h;
		auto lines = Tooltip::TextLines(static_cast<std::string>(this->Input(0).Value()), w, h);
		int cnt = static_cast<int>(lines.size()) - 1;
		this->height_ = this->orig_h + h * (cnt < 0 ? 0 : cnt) - h;
		this->width_ = this->orig_w - static_cast<InPortUI&>(this->Input(0)).getWidth() + w;
        this->width_ = std::max(this->width_, Style::NodeNamePadding * 2 + QApplication::fontMetrics().width(this->name.c_str()));
        this->width_ = std::max(this->width_, Style::NodeMinWidth);
		this->resize(this->width_ + 1, this->height_ + 1);
	}
    void Move(int x, int y){
		updateBlockSize();
        UIBlock<BlockBaseT>::Move(x, y);
	}

protected:
    void paintEvent(QPaintEvent *event){
		updateBlockSize();
        UIBlock<BlockBaseT>::paintEvent(event);

		int w, h;
		auto lines = Tooltip::TextLines(static_cast<std::string>(this->Input(0).Value()), w, h);

		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);

        int offset = Style::PortMarginV + h - 3;
		for(const std::string &line : lines){
            painter.drawText(Style::PortNamePadding, offset, line.c_str());
			offset += h;
		}
	}
};
