#include "GameUI.h"
#include <QThread>
#include <QTimer>
#include <QMessageBox>

GameUI::GameUI(gameLogic::Game* game, QWidget* parent)
	: QMainWindow(parent), m_game(game), m_difficultyDilay(1000)
{
    ui.setupUi(this);
    resize(800, 600);
    m_game->AddListener(this);

    for (auto& button : { ui.redButton, ui.blueButton, ui.greenButton, ui.yellowButton })
    {
        connect(button, &QPushButton::clicked, this, &GameUI::handleButtonPress);
    }
}

GameUI::~GameUI()
{
    m_game->RemoveListener(this);
}

QPushButton* GameUI::getButtonForColor(gameLogic::Color color) const
{
    switch (color)
    {
    case gameLogic::Color::RED:    return ui.redButton;
    case gameLogic::Color::BLUE:   return ui.blueButton;
    case gameLogic::Color::GREEN:  return ui.greenButton;
    case gameLogic::Color::YELLOW: return ui.yellowButton;
    default: return nullptr;
    }
}

gameLogic::Color GameUI::getColorForButton(QPushButton* button) const
{
    if (button == ui.redButton)    return gameLogic::Color::RED;
    if (button == ui.blueButton)   return gameLogic::Color::BLUE;
    if (button == ui.greenButton)  return gameLogic::Color::GREEN;
    if (button == ui.yellowButton) return gameLogic::Color::YELLOW;
    return gameLogic::Color::none;
}

void GameUI::setButtonsEnabled(bool enabled)
{
    ui.redButton->setEnabled(enabled);
    ui.blueButton->setEnabled(enabled);
    ui.greenButton->setEnabled(enabled);
    ui.yellowButton->setEnabled(enabled);
}

void GameUI::showSequence()
{ 
    const auto& sequence = m_game->GetMoveSequence();
    m_game->SetIsSequenceOver(false);
    int delay = m_difficultyDilay;
    setButtonsEnabled(false);

    for (auto color : sequence)
    {
        QTimer::singleShot(delay, [this, color]() {
            highlightButton(color);
            });
        delay += m_difficultyDilay+100;
    }

    QTimer::singleShot(delay, [this]() {
        setButtonsEnabled(true);
        });

}

void GameUI::highlightButton(gameLogic::Color color)
{
    QPushButton* button = getButtonForColor(color);

    if (button)
    {
        const QString originalStyle = button->styleSheet();
        button->setStyleSheet("background-color: white;");
        QTimer::singleShot(m_difficultyDilay, [button,originalStyle]() {
            button->setStyleSheet(originalStyle);
            });
    }
}

void GameUI::on_startButton_clicked()
{
    switch (ui.comboBox->currentIndex())
    {
	case 0:
		m_difficultyDilay = 1000;
		break;
	case 1:
		m_difficultyDilay = 500;
		break;
	case 2:
		m_difficultyDilay = 250;
		break;
    default:
        m_difficultyDilay = 1000;
        break;
    }
    ui.stackedWidget->setCurrentIndex(1);
    startGame();
}

void GameUI::on_resetButton_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}
  
void GameUI::startGame()
{
    m_game->StartNewGame();
}

void GameUI::OnPressStart()
{
    m_game->ResetPlayerMove();

    ui.lcdLevel->display(0);
    ui.lcdMaxScore->display(0);

    m_game->RandomColorGenerator();
    showSequence();
}

void GameUI::handleButtonPress()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    gameLogic::Color color = getColorForButton(button);

    m_game->MakeMove(color);
}

void GameUI::OnMoveMade()
{
    if (m_game->IsGameOver())
	{
		setButtonsEnabled(false);
        ui.GameOver->setText("Game Over\nYour score is: " + QString::number(m_game->GetLevel()));
    }
    else if(m_game->IsSequenceOver())
    {
        ui.lcdLevel->display(m_game->GetLevel());
        ui.lcdMaxScore->display(m_game->GetMaxScore());       
        showSequence();
    }
}