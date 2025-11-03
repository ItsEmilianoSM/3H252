#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include <Dibujo.hpp>
#include <GestorDibujos.hpp>
#include <Corral.hpp> 

using namespace ftxui;

int main() {
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24));

    const std::vector<std::u32string> jugador_patea = {
        U"  o__  ",
        U" /|    ",
        U" / > o ", 
    };
    
    const std::vector<std::u32string> jugador_celebra = {
        U" \\o/ ",
        U"  |  ",
        U" / \\ ",
    };

    const std::vector<std::u32string> balon = {
        U"o",
    };

    const std::vector<std::u32string> porteria = {
        U"  _______  ",
        U" |\\     \\ ",
        U" | \\x\\   \\",
        U" |  \\xx\\  ",
    };

    // --- NUEVO ARTE ---
    const std::vector<std::u32string> arbol = {
        U"   /\\   ",
        U"  /<>\\  ",
        U" /<>>\\ ",
        U"   ||   ",
    };


    GestorDibujos gestor;

    gestor.Agregar(Dibujo(60, 10, porteria, Color::White)); 
   
    gestor.Agregar(Dibujo(5, 18, arbol, Color::Green));    

    gestor.Agregar(Dibujo(10, 15, jugador_patea, Color::Cyan)); 
    gestor.Agregar(Dibujo(16, 17, balon, Color::Red));          

    int frames_totales = 150; 
    int frame_patada = 30;   
    int frames_vuelo = 50;   

    
    int balon_x_ini = 16;
    int balon_y_ini = 17;

    int balon_x_fin = 63;
    int balon_y_fin = 12;

    for (int frame = 0; frame < frames_totales; ++frame) 
    {
        screen.Clear();

        if (frame < frame_patada) {
            // El jugador tiene la pose de patear y el balón está en su pie
            gestor.dibujos[2].figura = jugador_patea;
            gestor.dibujos[3].x = balon_x_ini;
            gestor.dibujos[3].y = balon_y_ini;
        
        } else if (frame >= frame_patada && frame < (frame_patada + frames_vuelo)) {
            // El jugador cambia a pose de celebración
            gestor.dibujos[2].figura = jugador_celebra;

            float t = (float)(frame - frame_patada) / frames_vuelo;

            gestor.dibujos[3].x = balon_x_ini + t * (balon_x_fin - balon_x_ini);
            gestor.dibujos[3].y = balon_y_ini + t * (balon_y_fin - balon_y_ini);

        } else {

            // El jugador mete gol
            gestor.dibujos[2].figura = jugador_celebra;
            gestor.dibujos[3].x = balon_x_fin;
            gestor.dibujos[3].y = balon_y_fin;

            if (frame % 10 < 5) {
                gestor.dibujos[2].y = 14; // Arriba
            } else {
                gestor.dibujos[2].y = 15; // Abajo
            }
        }

        gestor.DibujarTodos(screen);
        
        std::cout << screen.ToString() << screen.ResetPosition() << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}