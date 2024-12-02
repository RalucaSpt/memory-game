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
	if (ui.comboBox->currentIndex() == 0)
		m_difficultyDilay = 1000;
	else
		if (ui.stackedWidget->currentIndex() == 1)
			m_difficultyDilay = 500;
		else
			m_difficultyDilay = 250;
    ui.stackedWidget->setCurrentIndex(1);
    startGame();
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
        QMessageBox::warning(this, "Game Over", "Ai greșit secvența!");
        ui.stackedWidget->setCurrentIndex(0);
    }
    else if(m_game->IsSequenceOver())
    {
        ui.lcdLevel->display(m_game->GetLevel());
        ui.lcdMaxScore->display(m_game->GetMaxScore());       
        showSequence();
    }
}

//
//void GameUI::OnPressStart()
//{
//    qDebug() << "Jocul a început!";
//}
//
//void GameUI::OnMoveMade()
//{
//    qDebug() << "Mutare făcută de utilizator!";
//}
//
//void GameUI::showSequence()
//{
//    
//    
//
//    const auto& sequence = m_game->GetMoveSequence();
//    int delay = 0;
//    
//    setButtonsEnabled(false);
//    
//    for (auto color : sequence)
//    {
//        QTimer::singleShot(delay, [this, color]() {
//            highlightButton(color);
//            });
//        delay += 1500; 
//    }
//    QTimer::singleShot(delay, [this]() {
//        setButtonsEnabled(true);
//        });
//}   


//void GameUI::highlightButton(gameLogic::Color color)
//{
//    QPushButton* button = getButtonForColor(color);
//
//    if (button)
//    {
//        const QString originalStyle = button->styleSheet();
//        button->setStyleSheet("background-color: white;");
//
//        QTimer::singleShot(1000, [button, originalStyle]() {
//            button->setStyleSheet(originalStyle);
//            });
//    }
//}
//
//void GameUI::on_startButton_clicked()
//{
//	ui.stackedWidget->setCurrentIndex(1);
//	startGame();
//}
//
//void GameUI::startGame()
//{
//    m_game->StartNewGame();
//    m_game->ResetPlayerMove();
//
//    ui.lcdLevel->display(1);
//    ui.lcdMaxScore->display(m_game->GetMaxScore());
//
//    m_game->RandomColorGenerator();
//    showSequence();
//}
//
//void GameUI::handleButtonPress()
//{
//    QPushButton* button = qobject_cast<QPushButton*>(sender());
//    if (!button) return;
//
//    gameLogic::Color color = getColorForButton(button);
//   
//    if (m_game->VerifyPlayerMoveSequence(color))
//    {
//        if (m_game->GetPlayerMove() == m_game->GetMoveSequence().size())
//        {
//            ui.lcdLevel->display(m_game->AddLevel());
//            if (m_game->CheckNewRecord())
//                ui.lcdMaxScore->display(m_game->GetMaxScore());
//
//            m_game->RandomColorGenerator();
//            m_game->ResetPlayerMove();
//            showSequence();
//        }
//    }
//    else
//    {
//        QMessageBox::warning(this, "Game Over", "Ai greșit secvența!");
//		ui.stackedWidget->setCurrentIndex(0);
//    }
//}
//
//QPushButton* GameUI::getButtonForColor(gameLogic::Color color) const
//{
//    switch (color)
//    {
//    case gameLogic::Color::RED:    return ui.redButton;
//    case gameLogic::Color::BLUE:   return ui.blueButton;
//    case gameLogic::Color::GREEN:  return ui.greenButton;
//    case gameLogic::Color::YELLOW: return ui.yellowButton;
//    default: return nullptr;
//    }
//}
//
//gameLogic::Color GameUI::getColorForButton(QPushButton* button) const
//{
//    if (button == ui.redButton)    return gameLogic::Color::RED;
//    if (button == ui.blueButton)   return gameLogic::Color::BLUE;
//    if (button == ui.greenButton)  return gameLogic::Color::GREEN;
//    if (button == ui.yellowButton) return gameLogic::Color::YELLOW;
//    return gameLogic::Color::none;
//}
//
//void GameUI::setButtonsEnabled(bool enabled)
//{
//    ui.redButton->setEnabled(enabled);
//    ui.blueButton->setEnabled(enabled);
//    ui.greenButton->setEnabled(enabled);
//    ui.yellowButton->setEnabled(enabled);
//}

