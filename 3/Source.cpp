#include <SFML/Graphics.hpp> 

#include <vector> 



int main() {

    sf::RenderWindow ventana(sf::VideoMode(800, 600), "C�rculos Rojo y Azul");



    sf::Texture texturaRoja, texturaAzul;

    if (!texturaRoja.loadFromFile("rcircle.png") || !texturaAzul.loadFromFile("bcircle.png")) {

        return -1; // Salir si hay problemas cargando las texturas 

    }



    sf::Sprite spriteRojo(texturaRoja);

    sf::Sprite spriteAzul(texturaAzul);



    std::vector<sf::Sprite> circulos;



    while (ventana.isOpen()) {

        sf::Event evento;

        while (ventana.pollEvent(evento)) {

            if (evento.type == sf::Event::Closed) {

                ventana.close();

            }



            if (evento.type == sf::Event::MouseButtonPressed) {

                if (evento.mouseButton.button == sf::Mouse::Left) {

                    sf::Vector2f posicion(static_cast<float>(evento.mouseButton.x), static_cast<float>(evento.mouseButton.y));

                    spriteRojo.setPosition(posicion);

                    circulos.push_back(spriteRojo);

                }
                else if (evento.mouseButton.button == sf::Mouse::Right) {

                    sf::Vector2f posicion(static_cast<float>(evento.mouseButton.x), static_cast<float>(evento.mouseButton.y));

                    spriteAzul.setPosition(posicion);

                    circulos.push_back(spriteAzul);

                }

            }

        }



        ventana.clear(sf::Color::White);



        for (const auto& circulo : circulos) {

            ventana.draw(circulo);

        }



        ventana.display();

    }



    return 0;

}