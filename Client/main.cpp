// Copyright (c) 2018 All Rights Reserved WestBot

#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "../Common/led.grpc.pb.h"

using namespace grpc;
using namespace WestBot;

class LedDummyClient
{
public:
    LedDummyClient( std::shared_ptr< Channel > channel )
        : _stub( Led::NewStub( channel ) ) 
    {
    }

    bool turnOn( int ledId )
    {
        LedRequest request;
        request.set_id( ledId );
        request.set_name( "dummy" );

        LedReply reply;
        ClientContext context;
        
        Status status = _stub->turnOn( & context, request, & reply ); 

        if( status.ok() ) 
        {
            return true;
        } 
        else 
        {
            std::cout 
                << status.error_code() << ": " << status.error_message()
                << std::endl;
            return false; 
        }
    }

    bool turnOff( int ledId )
    {
        LedRequest request;
        request.set_id( ledId );
        request.set_name( "dummy" );

        LedReply reply;
        ClientContext context;
        
        Status status = _stub->turnOff( & context, request, & reply ); 

        if( status.ok() ) 
        {
            return true;
        } 
        else 
        {
            std::cout 
                << status.error_code() << " : " << status.error_message()
                << std::endl;
            return false; 
        }
    }

private:
    std::unique_ptr< Led::Stub > _stub;
};

int main( int argc, char** argv ) 
{
    LedDummyClient dummy(
        grpc::CreateChannel(
            "localhost:50051", 
            grpc::InsecureChannelCredentials() ) ); 
  
    bool status = dummy.turnOn( 2 );

    std::cout << "[action] Turn ON / status: " << status << std::endl;
    
    status = dummy.turnOff( 3 );
    
    std::cout << "[action] Turn OFF / status: " << status << std::endl;

    return 0;
}
