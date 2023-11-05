#include <SFML/Graphics.hpp> 



int main() {

    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Mover Figuras");



    sf::Texture texturaCuadrado, texturaCirculo;

    if (!texturaCuadrado.loadFromFile("cuad_yellow.png") || !texturaCirculo.loadFromFile("rcircleg.png")) {

        return -1; // Salir si hay problemas cargando las texturas 

    }



    sf::Sprite sprite(texturaCuadrado);

    sprite.setScale(0.5f, 0.5f); // Escalamos el sprite para que sea más pequeño (ajusta según el tamaño de tus sprites) 

    bool esCuadrado = true;



    const float velocidadMovimiento = 5.0f;

    const sf::Vector2u ventanaSize = ventana.getSize();

    const float limiteX = ventanaSize.x - sprite.getGlobalBounds().width;

    const float limiteY = ventanaSize.y - sprite.getGlobalBounds().height;



    while (ventana.isOpen()) {

        sf::Event evento;

        while (ventana.pollEvent(evento)) {

            if (evento.type == sf::Event::Closed) {

                ventana.close();

            }



            if (evento.type == sf::Event::KeyPressed) {

                if (evento.key.code == sf::Keyboard::Space) {

                    if (esCuadrado) {

                        sprite.setTexture(texturaCirculo);

                        esCuadrado = false;

                    }
                    else {

                        sprite.setTexture(texturaCuadrado);

                        esCuadrado = true;

                    }

                }

            }

        }



        sf::Vector2f movimiento(0, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 0) {

            movimiento.x = -velocidadMovimiento;

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite.getPosition().x < limiteX) {

            movimiento.x = velocidadMovimiento;

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprite.getPosition().y > 0) {

            movimiento.y = -velocidadMovimiento;

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprite.getPosition().y < limiteY) {

            movimiento.y = velocidadMovimiento;

        }



        sprite.move(movimiento);



        ventana.clear(sf::Color::White);

        ventana.draw(sprite);

        ventana.display();

    }



    return 0;

}