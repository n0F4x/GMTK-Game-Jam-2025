#include <string>
#include <iostream>

import app;

import plugins.resources;

struct Message
{
    std::string message;

    auto send() const -> void
    {
        std::cout << message;
    }
};

auto main() -> int
{
    auto message = app::create()
                   .plug_in(plugins::resources)
                   .insert_resource(Message{"Hello GMTK 2025!"})
                   .build()
                   .resource_manager.get<Message>();

    message.send();
}
