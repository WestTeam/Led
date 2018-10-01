// Copyright (c) 2018 All Rights Reserved WestBot

#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "../Common/led.grpc.pb.h"

using namespace grpc;
using namespace WestBot;

// Logic and data behind the server's behavior.
class LedServiceImpl final : public Led::Service
{
    Status turnOn(
        ServerContext* context,
        const LedRequest* request,
        LedReply* reply ) override 
    {
        // TODO: Call the item register API
        std::cout << "Turn LED " << request->name() << ": ON" << std::endl;

        reply->set_id( request->id() );
        reply->set_status( true );
        reply->set_errorstring( "none" );
        
        return Status::OK;
    }
    
    Status turnOff(
        ServerContext* context,
        const LedRequest* request,
        LedReply* reply ) override 
    {
        // TODO: Call the item register API
        std::cout << "Turn LED " << request->name() << ": OFF" << std::endl;

        reply->set_id( request->id() );
        reply->set_status( false );
        reply->set_errorstring( "none" );
        
        return Status::OK;
    }
};

void RunServer()
{
    std::string serverAddr( "localhost:50051" );
    LedServiceImpl ledService;

    ServerBuilder builder;
    builder.AddListeningPort( serverAddr, grpc::InsecureServerCredentials() );
    builder.RegisterService( & ledService );

    std::unique_ptr< Server > server( builder.BuildAndStart() );

    std::cout << "Server listening on " << serverAddr << std::endl;

    server->Wait();
}

int main( int argc, char** argv )
{
    RunServer();

    return 0;
}
