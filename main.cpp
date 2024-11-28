#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/System.hpp> 
#include <SFML/Network.hpp> 
#include <SFML/Audio.hpp> 
#include <SFML/Window.hpp>
void clicked_button(sf::RectangleShape &rectangle){
    rectangle.setFillColor(sf::Color::Green);
}   
int main() {
menu:
    sf::RenderWindow window(sf::VideoMode(1093,700), "okno");
    sf::Event event,eventt;
    sf::RectangleShape rectangle(sf::Vector2f(350.f, 100.f));
    sf::RectangleShape rectangle1(sf::Vector2f(350.f, 100.f));
    sf::RectangleShape background(sf::Vector2f(1093.f, 700.f));
    sf::Texture texture,back,texture2;
    texture.loadFromFile("C:\\Users\\huber\\OneDrive\\Pulpit\\nowy.png");
    texture2.loadFromFile("C:\\Users\\huber\\OneDrive\\Pulpit\\wczytaj.png");
    back.loadFromFile("C:\\Users\\huber\\OneDrive\\Pulpit\\background1.png");
    sf::FloatRect bonds = rectangle.getGlobalBounds();
    sf::FloatRect bonds1 = rectangle1.getGlobalBounds();
    rectangle.setPosition(sf::Vector2f(window.getSize().x / 2.f - rectangle1.getSize().x / 2.f, (window.getSize().y / 2.f - rectangle1.getSize().x / 2.f) + 200.f));
    rectangle1.setPosition(sf::Vector2f(window.getSize().x / 2.f - rectangle1.getSize().x / 2.f, (window.getSize().y / 2.f - rectangle1.getSize().x / 2.f) + 320.f));
    rectangle.setTexture(&texture);
    rectangle1.setTexture(&texture2);
    background.setTexture(&back);
    
    while (window.isOpen()) {
        window.draw(background);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); return  0; }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (bonds.contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                        clicked_button(rectangle);
                        window.close();
                        break;
                    } if (bonds1.contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                        clicked_button(rectangle1);
                        /* window.close();
                         break;*/
                    }
                    /*      std::cout <<"x :"<<sf::Mouse::getPosition().x << "\n";
                          std::cout <<"y :" << sf::Mouse::getPosition().y<<"\n";
                          std::cout << "bounds x :" << bonds.getPosition().x << "\n";
                          std::cout << "bounds y :" << bonds.getPosition().y << "\n";*/
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                rectangle.setFillColor(sf::Color::White);
                rectangle1.setFillColor(sf::Color::White);
            }
        }
        
        bonds = rectangle.getGlobalBounds();
        bonds1 = rectangle1.getGlobalBounds();
        window.draw(rectangle);
        window.draw(rectangle1);
        window.display();
        window.clear();
    }
    sf::RenderWindow windowmenu(sf::VideoMode(1093, 700), "ZAPIS");
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\huber\\OneDrive\\Pulpit\\Roboto-Italic.ttf"))
        return EXIT_FAILURE;

    sf::String playerInput;
    sf::Text playerText;
    sf::RectangleShape form1(sf::Vector2f(350.f, 25.f));
    sf::RectangleShape form2(sf::Vector2f(350.f, 25.f));
    sf::RectangleShape form3(sf::Vector2f(350.f, 25.f));
    form1.setPosition(30.f, (windowmenu.getSize().y / 3)+100);
    form1.setFillColor(sf::Color::White);
    form2.setPosition(30.f, (windowmenu.getSize().y * (2.f / 3.f))+100);
    form2.setFillColor(sf::Color::White);
    form3.setPosition(30.f, 100);
    form3.setFillColor(sf::Color::White);
    playerText.setFont(font);
    playerText.setCharacterSize(25);
    playerText.setPosition(30.f,windowmenu.getSize().y/ 3);
    playerText.setFillColor(sf::Color::Red);
    bool clicked1 = false;
    bool clicked2 = false;
    bool clicked3 = false;
    while (windowmenu.isOpen()) {
        while (windowmenu.pollEvent(eventt))
        {
            if (eventt.type == sf::Event::Closed())windowmenu.close();
            if (eventt.type == sf::Event::MouseButtonPressed) {
                if (eventt.mouseButton.button == sf::Mouse::Left) {
                    if (form1.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(windowmenu)))) {
                        clicked_button(form1);
                        playerText.setPosition(30.f, (windowmenu.getSize().y /3)+100);
                        clicked1 = true;
                        clicked2 = false;
                        clicked3 = false;
                        playerInput.clear();
                    }
                    if (form2.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(windowmenu)))) {
                        clicked_button(form2);
                        playerText.setPosition(30.f, (windowmenu.getSize().y * (2.f / 3.f)) + 100);
                        clicked1 = false;
                        clicked2 = true;
                        clicked3 = false;
                        playerInput.clear();
                    }
                    if (form3.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(windowmenu)))) {
                        clicked_button(form3);
                        playerText.setPosition(30.f, 100);
                        clicked1 = false;
                        clicked2 = false;
                        clicked3 = true;
                        playerInput.clear();
                    }
                }

            }
            if ((eventt.type == sf::Event::TextEntered)&&clicked1==true) {
                if (eventt.text.unicode == 8 && playerInput.getSize() > 0) {
                    playerInput.erase(playerInput.getSize() - 1);
                    playerText.setString(playerInput);
                }
                else {
                    playerInput += eventt.text.unicode;
                    playerText.setString(playerInput);
                }
            }
            if ((eventt.type == sf::Event::TextEntered) && clicked2 == true) {
                if (eventt.text.unicode == 8 && playerInput.getSize() > 0) {
                    playerInput.erase(playerInput.getSize() - 1);
                    playerText.setString(playerInput);
                }
                else {
                    playerInput += eventt.text.unicode;
                    playerText.setString(playerInput);
                }
            }
            if ((eventt.type == sf::Event::TextEntered) && clicked3 == true) {
                if (eventt.text.unicode == 8 && playerInput.getSize() > 0) {
                    playerInput.erase(playerInput.getSize() - 1);
                    playerText.setString(playerInput);
                }
                else {
                    playerInput += eventt.text.unicode;
                    playerText.setString(playerInput);
                }
            }
        }
           
           windowmenu.draw(form1);
           windowmenu.draw(form2);
           windowmenu.draw(form3);
           windowmenu.draw(playerText);
           windowmenu.display();
           windowmenu.clear();
       }

    return 0;
}
