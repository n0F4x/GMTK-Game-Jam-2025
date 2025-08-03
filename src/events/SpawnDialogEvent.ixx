module;

#include <string>

export module events.SpawnDialogEvent;

export struct SpawnDialogEvent {
    enum struct Style {
        eOverworld,
        eHell,
    };

    std::string text;
    Style       style;
};
