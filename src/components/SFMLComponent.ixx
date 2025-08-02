module;

#include <memory>

export module components.SFMLComponent;

import window.Window;

export struct SFDrawable {
    virtual void draw(window::Window& window) = 0;

    virtual ~SFDrawable() = default;
};

export struct SFMLComponent {
    std::shared_ptr<SFDrawable> component;
};
