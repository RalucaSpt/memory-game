#pragma once

#include <QtWidgets/QFrame>
#include <QPushButton>
#include <QLabel>
#include "EColor.h"

class HistoryFrame : public QFrame
{
	Q_OBJECT

public:
	HistoryFrame(QWidget* parent = nullptr);
	~HistoryFrame() override = default;

	void UpdateSelectedColors(const std::vector<EColor>& selectedColors);

public slots:
	void OnRoundEnded();
	void OnUndo();

protected:
	void showEvent(QShowEvent* event) override;

private:
	QString ColorToString(EColor color);

private:
	bool m_firstShow;
	std::vector<QLabel*> m_previousSelectedColors;
};
