#pragma once
#include <nodepp/input.h>
#include <nodepp/query.h>

namespace InputHandler {

input_t device;

void emit( string_t msg ){

    for( auto x: string::split( msg,'\n' ) ){
         auto data = query::parse( x );

        if( data["cmd"] == "MSE" ){
            
            if( !data["x"].empty() && !data["y"].empty() ){
                ptr_t<float> pos ({ 
                    string::to_float( data["x"] ),
                    string::to_float( data["y"] )
                });
                console::log( data["x"], data["y"] );
                device.set_mouse_position( pos[0], pos[1] );   
            }

              if( data["p"] == "1" ) device.press_mouse_button( 1 );
            elif( data["p"] == "0" ) device.release_mouse_button( 1 );

        }
    
    }

}}