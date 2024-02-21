#include <nodepp/nodepp.h>
#include <nodepp/http.h>
#include <nodepp/dns.h>
#include <nodepp/ws.h>

using namespace nodepp;

#include <InputHandler.h>
#include <HTTPHandler.h>
#include <WSHandler.h>

onMain([](){

    auto server = http::server( HTTPHandler::emit );
                    ws::server( server );

    server.onConnect( WSHandler::emit );

    server.listen( "0.0.0.0", 8000, [=]( socket_t /*unused*/ ){
        console::log(string::format("server started at http://%s:8000",dns::get_hostname().c_str()));
    });

})