#include <SFML/Graphics.hpp> 



int main() {

    // Creamos la ventana 

    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Ventana con Crosshair");



    // Cargamos la textura del crosshair 

    sf::Texture textura;

    if (!textura.loadFromFile("crosshair.png")) {

        // Manejo de error si la carga de la textura falla 

        return -1; // Sale del programa si no puede cargar la textura 

    }



    // Creamos el sprite para la mirilla (crosshair) 

    sf::Sprite mirilla(textura);

    mirilla.setOrigin(textura.getSize().x / 2, textura.getSize().y / 2); // Establecemos el origen en el centro del sprite 



    // Bucle principal 

    while (ventana.isOpen()) {

        sf::Event evento;

        while (ventana.pollEvent(evento)) {

            if (evento.type == sf::Event::Closed) {

                ventana.close(); // Cierra la ventana si se presiona el botón de cerrar 

            }

        }



        // Centramos la posición del crosshair en el centro de la ventana 

        mirilla.setPosition(ventana.getSize().x / 2, ventana.getSize().y / 2);



        // Limpiamos la ventana 

        ventana.clear(sf::Color::Black);



        // Dibujamos el crosshair en el centro de la ventana 

        ventana.draw(mirilla);



        // Mostramos todo en pantalla 

        ventana.display();

    }



    return 0;

}