#include <iostream>
#include <cstring>
#include "map.hpp" 

extern "C" {
    #include <enet/enet.h>
}

#include "network.hpp"

void startClient(void){

    // Map du jouer/client
    Map * map = new Map;


    ENetHost* client = enet_host_create(nullptr, 1, 2, 0, 0);
    if (!client) {
        std::cerr << "Client creation failed.\n";
        return;
    }

    ENetAddress address;
    enet_address_set_host(&address, "127.0.0.1");
    address.port = 1234;

    ENetPeer* peer = enet_host_connect(client, &address, 2, 0);
    if (!peer) {
        std::cerr << "Connection failed.\n";
        return;
    }
    /* Wait up to 5 seconds for the connection attempt to succeed. */
    ENetEvent event = {};
    if (enet_host_service(client, &event, 5000) > 0 &&
        event.type == ENET_EVENT_TYPE_CONNECT)
    {
        std::cout << "Got a connection!\n";

        while (true)
        {

            ENetEvent event;
            /* Wait up to 10 milliseconds for an event. */
            while (enet_host_service(client, &event, 10) > 0)
            {
                switch (event.type)
                {
                case ENET_EVENT_TYPE_CONNECT:
                break;

                case ENET_EVENT_TYPE_RECEIVE:
                    printf("A packet of length %lu containing %s was received on channel %u.\n",
                        event.packet->dataLength,
                        event.packet->data,
                        event.channelID);

                    // Parse data
                    

                    /* Clean up the packet now that we're done using it. */
                    enet_packet_destroy(event.packet);
                break;

                case ENET_EVENT_TYPE_DISCONNECT:
                    std::cout << "Server Disconected\n";
                    break;
                }
            }

            //do other stuff
            std::cout << "Entrez un message: ";
            std::string message = "";
            std::cin >> message;

            if (message != "")
                sendMessage(peer, message.c_str());
        }
    }
    else
    {
        std::cout << "Wasn't able to connect\n";
    }

    enet_peer_reset(peer);
    enet_host_destroy(client);
    return;
}

