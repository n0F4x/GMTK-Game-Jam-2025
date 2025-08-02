export module components.Health;

import utility.Strong;

export struct Health : util::Strong<int, Health> {
    using Strong::Strong;
};
