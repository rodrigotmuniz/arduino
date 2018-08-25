/*
 *  toggle_button exemplo
 *  
 *  Autor: Rodrigo Muniz
 *  Abril de 2018
 */

 #ifndef toggle_button
 #define toggle_button

 #include "Arduino.h"

 class toggle_button {
  public:
    toggle_c(int buttonPin); //Constructor
    void toggle_m(int bounceTime); //Metodos
    
  private: 
    int _buttonPin;
    int _ledPin;
 };

 #endif 
