#include "ColorsFrame.h"
#include <QTimer>
#include <QPointer>

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

	auto it = m_buttonMap.find(color);
	if (it != m_buttonMap.end()) {
		HighlightColor(it->second, color);
	}
}

void ColorsFrame::OnSequenceEnded()
{
	for (auto& pair : m_buttonMap) {
		SetDefaultColor(pair.second, pair.first);
	}
	this->setEnabled(true);
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

	SetDefaultColor(colorButton, color);

	colorButton->setCursor(Qt::PointingHandCursor);
	colorButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	colorButton->setFocusPolicy(Qt::NoFocus);

	m_gridLayout->addWidget(colorButton, position.first, position.second);

	QObject::connect(colorButton, &QPushButton::released, this, [this, color]() {
		emit ColorSelected(color);
	});
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

void ColorsFrame::HighlightColor(QPushButton* colorButton, EColor color)
{
	QColor baseColor(ColorToString(color));
	QColor hightlightColor = baseColor.lighter(200);
	QString styleSheet = QString(
		"QPushButton {"
		"    background-color: %1;"
		"    border: none;"
		"    padding: 10px;"
		"}").arg(hightlightColor.name());

	QString originalStyleSheet = colorButton->styleSheet();
	colorButton->setStyleSheet(styleSheet);

	QPointer<QPushButton> safeButton = colorButton;
	QTimer::singleShot(1000, [safeButton, originalStyleSheet]() {
		if (safeButton) {
			safeButton->setStyleSheet(originalStyleSheet);
		}
		});
}

void ColorsFrame::SetDefaultColor(QPushButton* colorButton, EColor color)
{
	QString colorName = ColorToString(color);

	QColor baseColor(colorName);
	QColor hoverColor = baseColor.darker(150);

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
}

QString ColorsFrame::ColorToString(EColor color) const
{
	switch (color) {
		case EColor::Blue:    return "blue";
		case EColor::Green:   return "green";
		case EColor::Yellow:  return "yellow";
		case EColor::Red:     return "red";
		case EColor::Orange:  return "orange";
		case EColor::Purple:  return "purple";
		case EColor::Teal:    return "teal";
		case EColor::Magenta: return "magenta";
		case EColor::None:    return "none";
		default:              return "unknown";
	}
}
