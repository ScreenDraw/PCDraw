#pragma once

namespace WSHandler {
void emit ( ws_t cli ){

    console::log("connected");

    cli.onData( InputHandler::emit );

    cli.onClose([](){
        console::log("closed");
    });
    
}}