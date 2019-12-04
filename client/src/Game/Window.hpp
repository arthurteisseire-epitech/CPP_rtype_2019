/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#ifndef RTYPE_WINDOW_HPP
#define RTYPE_WINDOW_HPP

#define WIN_TITLE "R-Type"
#define WIN_REF_SIZE sf::Vector2<uint32_t>(1920, 1080)

#include <cstdint>
#include <SFML/Graphics.hpp>

namespace Client {
    class Window {
    public:
        Window();
        ~Window() = default;
        void switchFullscreen();
        void switchVsync();
        void setFramerate(const uint32_t framerate);
        sf::Vector2<uint32_t> getSize() const;
        sf::Vector2<float> getRenderRatio() const;
        bool pollEvent(sf::Event &event);
        void clear();
        void draw(const sf::Drawable &drawable);
        void display();
        bool isOpen() const;
        void close();
    private:
        void recreateWindow();
        sf::RenderWindow _window;
        bool _fullscreen;
        bool _vsync;
        uint32_t _framerate;
        sf::VideoMode _monitor;
        sf::Vector2<float> _renderRatio;
    };
}

#endif
