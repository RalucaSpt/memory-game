#include "HistoryFrame.h"

HistoryFrame::HistoryFrame(QWidget* parent) :
	m_firstShow{ true }
{
}

void HistoryFrame::UpdateSelectedColors(const std::vector<EColor>& selectedColors)
{
	auto lastNColors = std::min(selectedColors.size(), m_previousSelectedColors.size());
	auto prevColorsIt = m_previousSelectedColors.begin();
	for (auto it = selectedColors.end() - lastNColors; it != selectedColors.end(); ++it) {
		if (prevColorsIt != m_previousSelectedColors.end()) {
			(*prevColorsIt)->setStyleSheet(QString("background-color: %1;").arg(ColorToString(*it)));
			++prevColorsIt;
		}
	}
}

void HistoryFrame::OnRoundEnded()
{
	for (auto label : m_previousSelectedColors) {
		label->setStyleSheet("background-color: transparent;");
	}
}

void HistoryFrame::showEvent(QShowEvent* event)
{
	if (m_firstShow) {

		const QObjectList& childList = this->children();
		for (QObject* child : childList) {
			QLabel* label = qobject_cast<QLabel*>(child);
			if (label) {
				m_previousSelectedColors.push_back(label);
			}
		}

		m_firstShow = false;
	}
}

QString HistoryFrame::ColorToString(EColor color)
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
