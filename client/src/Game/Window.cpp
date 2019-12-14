/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#include <vector>
#include "Component/IComponent.hpp"
#include "Window.hpp"

static const std::vector<std::string> musicPath({
    "Menu/Music.ogg",
    "Game/Music.ogg"
});

Client::Window::Window() : _window(), _fullscreen(true), _sound(true), _vsync(true),
    _framerate(60), _monitor(sf::VideoMode::getDesktopMode()), _renderRatio(
        float(_monitor.width) / float(WIN_REF_SIZE.x),
        float(_monitor.height) / float(WIN_REF_SIZE.y)
    ), _music()
{
    if (!_music.openFromFile(ASSETS_DIR + musicPath[0])) {
        throw std::runtime_error("\'Client::Window::Window\': Cannot load music: " + musicPath[0]);
    }
    _music.setLoop(true);
    this->recreateWindow();
    _music.play();
}

Client::Window::~Window()
{
    _music.stop();
}

void Client::Window::switchFullscreen()
{
    _fullscreen = !_fullscreen;
    this->recreateWindow();
}

void Client::Window::switchSound()
{
    _sound = !_sound;
    _music.setVolume(float(_sound) * 100.f);
}

void Client::Window::switchVsync()
{
    _vsync = !_vsync;
    _window.setVerticalSyncEnabled(_vsync);
}

void Client::Window::setFramerate(const uint32_t framerate)
{
    _framerate = framerate;
    _window.setFramerateLimit(_framerate);
}

void Client::Window::setMusic(const bool game)
{
    _music.stop();
    if (!_music.openFromFile(ASSETS_DIR + musicPath[game])) {
        throw std::runtime_error("\'Client::Window::Window\': Cannot load music: " + musicPath[game]);
    }
    _music.play();
}

bool Client::Window::getFullscreen() const
{
    return _fullscreen;
}

bool Client::Window::getSound() const
{
    return _sound;
}

bool Client::Window::getVsync() const
{
    return _vsync;
}

uint32_t Client::Window::getFramerate() const
{
    return _framerate;
}

sf::Vector2<uint32_t> Client::Window::getSize() const
{
    return _window.getSize();
}

sf::Vector2<float> Client::Window::getRenderRatio() const
{
    return _renderRatio;
}

bool Client::Window::pollEvent(sf::Event &event)
{
    return _window.pollEvent(event);
}

void Client::Window::clear()
{
    _window.clear();
}

void Client::Window::draw(const sf::Drawable &drawable)
{
    _window.draw(drawable);
}

void Client::Window::display()
{
    _window.display();
}

bool Client::Window::isOpen() const
{
    return _window.isOpen();
}

void Client::Window::close()
{
    _window.close();
}

void Client::Window::recreateWindow()
{
    _window.create(_monitor, WIN_TITLE, _fullscreen ? sf::Style::Fullscreen : sf::Style::Titlebar);
    _window.setVerticalSyncEnabled(_vsync);
    _window.setFramerateLimit(_framerate);
    if (!_fullscreen) {
        _window.setSize(sf::Vector2<uint32_t>(_monitor.width, _monitor.width));
    }
}