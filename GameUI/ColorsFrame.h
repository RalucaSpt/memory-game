#pragma once

#include <QtWidgets/QFrame>
#include <QPushButton>
#include <QGridLayout>
#include <unordered_map>

class ColorsFrame : public QFrame
{
	Q_OBJECT

public:
	ColorsFrame(QWidget* parent = nullptr);
	~ColorsFrame() override = default;

protected:
	void showEvent(QShowEvent* event) override;

private:
	void AddColoredButtons(uint8_t numberOfButtons);
	void AddButton(const QString& color, std::pair<uint8_t, uint8_t> position);

private:
	bool m_firstShow;
	std::unordered_map<QString, QPushButton*> buttonMap;
	std::vector<QString> m_colors;
	QGridLayout* m_gridLayout;
};
