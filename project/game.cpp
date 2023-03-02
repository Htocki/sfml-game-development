#include "game.h"

Game::Game()
  : m_Window(sf::VideoMode(640, 480), "SFML Application")
  , m_Player()
{
  m_Player.setRadius(40.f);
  m_Player.setPosition(100.f, 100.f);
  m_Player.setFillColor(sf::Color::Cyan);
}

void Game::run() {
  while (m_Window.isOpen()) {
    processEvents();
    update();
    render();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (m_Window.pollEvent(event)) {
    if ((event.type == sf::Event::KeyPressed) &&
         event.key.code == sf::Keyboard::Escape) {
      m_Window.close();
    }
  }
}

void Game::update() { }

void Game::render() {
  m_Window.clear();
  m_Window.draw(m_Player);
  m_Window.display();
}