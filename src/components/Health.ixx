export module components.Health;

import ddge.utility.Strong;

export struct Health : ddge::util::Strong<int, Health> {
    using Strong::Strong;
};
