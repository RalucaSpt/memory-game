#include "ColorsFrame.h"

ColorsFrame::ColorsFrame(QWidget* parent) :
	m_firstShow {true},
	m_gridLayout {new QGridLayout()}
{
	m_colors = { "red", "blue", "yellow", "green", "orange", "purple", "cyan", "magenta" };
}

void ColorsFrame::showEvent(QShowEvent* event)
{
	if (m_firstShow) {

		m_gridLayout = qobject_cast<QGridLayout*>(layout());

		if (m_gridLayout) {
			AddColoredButtons(2);
		}

		m_firstShow = false;
	}
}

void ColorsFrame::AddColoredButtons(uint8_t numberOfButtons)
{
	int row = 0;
	int col = 0;

	int columnLimit = (numberOfButtons <= 2) ? 2 : (numberOfButtons == 4) ? 2 : 4;

	for (size_t i = 0; i < numberOfButtons && i < m_colors.size(); ++i) {
		AddButton(m_colors[i], { row, col });

		++col;
		if (col >= columnLimit) {
			col = 0;
			++row;
		}
	}
}

void ColorsFrame::AddButton(const QString& color, std::pair<uint8_t, uint8_t> position)
{
	QPushButton* colorButton = new QPushButton(this);

	QColor baseColor(color);
	QColor hoverColor = baseColor.lighter(120);
	
	QString styleSheet = QString(
		"QPushButton {"
		"    background-color: %1;"
		"    border: none;"
		"    padding: 10px;"
		"}"
		"QPushButton:hover {"
		"    background-color: %2;"
		"}"
	).arg(baseColor.name()).arg(hoverColor.name());

	colorButton->setStyleSheet(styleSheet);
	colorButton->setCursor(Qt::PointingHandCursor);
	colorButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	m_gridLayout->addWidget(colorButton, position.first, position.second);
}