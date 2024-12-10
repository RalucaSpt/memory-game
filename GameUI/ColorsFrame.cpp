#include "ColorsFrame.h"

ColorsFrame::ColorsFrame(QWidget* parent) :
	m_firstShow {true},
	m_gridLayout {new QGridLayout()}
{
}

void ColorsFrame::AddButtonsAccordingToDifficulty(EDifficulty difficulty)
{
	switch (difficulty) {
		case EDifficulty::Easy:
			AddColoredButtons(2);
			break;
		case EDifficulty::Medium:
			AddColoredButtons(4);
			break;
		case EDifficulty::Hard:
			AddColoredButtons(8);
			break;
	}
}

void ColorsFrame::OnColorReceived(EColor color) {
	int a = 5;
}

void ColorsFrame::showEvent(QShowEvent* event)
{
	if (m_firstShow) {

		m_gridLayout = qobject_cast<QGridLayout*>(layout());

		this->setEnabled(false);

		m_firstShow = false;
	}
}

void ColorsFrame::AddColoredButtons(uint8_t numberOfButtons)
{
	m_buttonMap.clear();
	RemoveButtons();

	uint8_t row = 0;
	uint8_t col = 0;

	int columnLimit = (numberOfButtons <= 2) ? 2 : (numberOfButtons == 4) ? 2 : 4;

	for (size_t i = 0; i < numberOfButtons; ++i) {
		AddButton(static_cast<EColor>(i), {row, col});

		++col;
		if (col >= columnLimit) {
			col = 0;
			++row;
		}
	}
}

void ColorsFrame::AddButton(EColor color, std::pair<uint8_t, uint8_t> position)
{
	QPushButton* colorButton = new QPushButton(this);

	m_buttonMap.insert({ color, colorButton });

	QString colorName = ColorToString(color);

	QColor baseColor(colorName);
	QColor hoverColor = baseColor.darker(120);

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
	colorButton->setFocusPolicy(Qt::NoFocus);

	m_gridLayout->addWidget(colorButton, position.first, position.second);
}

void ColorsFrame::RemoveButtons()
{
	QLayoutItem* item;
	while ((item = m_gridLayout->takeAt(0)) != nullptr) {
		QWidget* widget = item->widget();
		if (widget) {
			widget->deleteLater(); 
		}
		delete item;
	}
}

QString ColorsFrame::ColorToString(EColor color)
{
	switch (color) {
		case EColor::Blue:    return "blue";
		case EColor::Green:   return "green";
		case EColor::Yellow:  return "yellow";
		case EColor::Red:     return "red";
		case EColor::Orange:  return "orange";
		case EColor::Purple:  return "purple";
		case EColor::Cyan:    return "cyan";
		case EColor::Magenta: return "magenta";
		case EColor::None:    return "none";
		default:              return "unknown";
	}
}
