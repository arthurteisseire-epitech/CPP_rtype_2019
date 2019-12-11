/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.hpp
*/

#ifndef RTYPE_COMMONMENU_HPP
#define RTYPE_COMMONMENU_HPP

#define MENU_DTOR \
delete _prev;\
for (auto &component : _components) {\
    delete component;\
}\
for (auto &button : _buttons) {\
    delete button.first;\
}

#define MENU_EVENT \
if (_quitRefTime < 0.f) {\
    for (auto &button : _buttons) {\
        if (button.first->event(event, keyBind, network, window)) {\
            (this->*button.second)(window);\
        }\
    }\
}

#define MENU_UPDATE \
float clockTime(_clock.getElapsedTime().asSeconds());\
float spawnTime((clockTime - 0.5f) * 2.f);\
if (spawnTime < 1.f) {\
    _components[0]->move({-0.5f + spawnTime, 0.5f});\
    uint8_t i = 0;\
    for (auto &button : _buttons) {\
        button.first->move({buttonPosList[i].x - 1.f + spawnTime, buttonPosList[i].y});\
        i++;\
    }\
} else if (_quitRefTime > 0.f) {\
    float quitTime(std::pow((clockTime - _quitRefTime) * 2.f, 4.f));\
    _components[0]->move({0.5f - quitTime, 0.5f});\
    uint8_t i = 0;\
    for (auto &button : _buttons) {\
        button.first->move({buttonPosList[i].x - quitTime, buttonPosList[i].y});\
        i++;\
    }\
    if (quitTime > 0.5f) {\
        if (_next) {\
            self = _next;\
            self->update(self, network, window);\
        } else {\
            window.close();\
        }\
    }\
} else {\
    _components[0]->move({0.5f, 0.5f});\
    uint8_t i = 0;\
    for (auto &button : _buttons) {\
        button.first->move({buttonPosList[i].x, buttonPosList[i].y});\
        i++;\
    }\
}\
for (auto &component : _components) {\
    component->update(network, window);\
}\
for (auto &button : _buttons) {\
    button.first->update(network, window);\
}

#define MENU_RENDER \
for (uint8_t layer = 0; layer < 255; layer++) {\
    for (auto &component : _components) {\
        component->render(window, layer);\
    }\
    for (auto &button : _buttons) {\
        button.first->render(window, layer);\
    }\
}

#endif