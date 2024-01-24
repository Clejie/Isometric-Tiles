#include <sfml/Graphics.hpp>
#include <iostream>
#include <cmath>

int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Isometric tiles");
    float scale = 2.50f;
    
    sf::Sprite tileBoard[20][20];
    sf::Sprite tile;

    // Texture for the sprite
    sf::Texture tileTexture;
    tileTexture.loadFromFile("resources/block.png");

    for (int col = 0; col < 20; col++) {
        for (int row = 0; row < 20; row++) {
            tileBoard[col][row].setOrigin(8, 8);
            tileBoard[col][row].setTexture(tileTexture);
            tileBoard[col][row].scale(scale, scale);
        }
    }

    // Main loop
    int frame = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int col = 0; col < 20; col++) {
            int r = 0;
            int g = 0;
            int b = 0;
            for (int row = 0; row < 20; row++) {
                // Get position of the 
                //float yOffset = -1 * sin(col / 2.0f + row + frame / 200 / 2.0f + frame / 200) * 10;
                float yOffset = -1 * sin(col / 2.0f + frame/200) * 10 + 10;
                float xOffset = -1 * sin(row / 2.0f + frame / 200) * 10 + 10;
                //xOffset = 0;
                float x = window.getSize().x * col / scale;
                float y = window.getSize().y * row / scale;
                if (r >= 255) {
                    r = 0;
                }
                if (g >= 255) {
                    g = 0;
                }
                if (b >= 255) {
                    b = 0;
                }
                float xTile = (x * 0.5f + y * -0.5f) / 8 + 400;
                float yTile = (x * 0.25f + y * 0.25f) / 8 + 200;
                yTile = yTile + yOffset + xOffset;
                g = 255 * (yOffset) + 255 * xOffset;
                b = yOffset + xOffset * 10;
                r = (yOffset + xOffset) * 10;
                tileBoard[col][row].setPosition(xTile, yTile);
                tileBoard[col][row].setColor(sf::Color(r, g, b));

                window.draw(tileBoard[col][row]);
            }
        }
        window.display();
        frame++;
    }
    return 0;
}