#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Observable.h"
#include "MockGameListener.h"
#include "Game.h"

using ::testing::Exactly;
using ::testing::AtLeast;

TEST(ObservableTest, AddListener_AddsListenerSuccessfully) {
    Observable observable;
    MockGameListener listener;
    observable.AddListener(&listener);

    //nu putem testa direct lista internă dar alte teste vor confirma funcționalitatea
}

TEST(ObservableTest, RemoveListener_RemovesListenerSuccessfully) {
    Observable observable;
    MockGameListener listener;
    observable.AddListener(&listener);
    observable.RemoveListener(&listener);

}

TEST(ObservableTest, NotifyOnPressStart_CallsOnPressStartOnListener) {
    Observable observable;
    MockGameListener listener;

    observable.AddListener(&listener);

    EXPECT_CALL(listener, OnPressStart())
        .Times(Exactly(1));

    observable.NotifyOnPressStart();
}

TEST(ObservableTest, NotifyOnMoveMade_CallsOnMoveMadeOnListener) {
    Observable observable;
    MockGameListener listener;

    observable.AddListener(&listener);

    EXPECT_CALL(listener, OnMoveMade())
        .Times(Exactly(1));

    observable.NotifyOnMoveMade();
}

TEST(ObservableTest, NotifyMultipleListeners_CallsAllListeners) {
    Observable observable;
    MockGameListener listener1, listener2;

    observable.AddListener(&listener1);
    observable.AddListener(&listener2);

    EXPECT_CALL(listener1, OnPressStart())
        .Times(Exactly(1));
    EXPECT_CALL(listener2, OnPressStart())
        .Times(Exactly(1));

    observable.NotifyOnPressStart();
}

TEST(GameTest, StartNewGame_NotifiesListeners) {
    Game game;
    MockGameListener mockListener;

    // Adăugăm listener-ul la joc
    game.AddListener(&mockListener);

    // Setăm așteptarea ca metoda OnPressStart să fie apelată
    EXPECT_CALL(mockListener, OnPressStart()).Times(Exactly(1));

    // Pornim un joc nou
    game.StartNewGame();
}


TEST(ObservableTest, RemovedListener_IsNotNotified) {
    Observable observable;
    MockGameListener listener;

    observable.AddListener(&listener);
    observable.RemoveListener(&listener);

    EXPECT_CALL(listener, OnPressStart())
        .Times(0);

    observable.NotifyOnPressStart();
}
