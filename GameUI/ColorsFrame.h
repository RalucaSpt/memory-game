#pragma once

#include <QtWidgets/QFrame>
#include <QPushButton>
#include <QGridLayout>
#include <unordered_map>
#include "EColor.h"
#include "EDifficulty.h"

class ColorsFrame : public QFrame
{
	Q_OBJECT

public:
	ColorsFrame(QWidget* parent = nullptr);
	~ColorsFrame() override = default;

	void AddButtonsAccordingToDifficulty(EDifficulty difficulty);

public slots:
	void OnColorReceived(EColor color);
	void OnSequenceEnded();

protected:
	void showEvent(QShowEvent* event) override;

private:
	void AddColoredButtons(uint8_t numberOfButtons);
	void AddButton(EColor color, std::pair<uint8_t, uint8_t> position);
	void RemoveButtons();
	void HighlightColor(QPushButton* colorButton, EColor color);
	void SetDefaultColor(QPushButton* colorButton, EColor color);

	QString ColorToString(EColor color);

private:
	bool m_firstShow;
	std::unordered_map<EColor, QPushButton*> m_buttonMap;
	QGridLayout* m_gridLayout;
};
