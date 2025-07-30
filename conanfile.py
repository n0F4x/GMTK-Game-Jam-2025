from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class GMTK2025(ConanFile):
    name = "gmtk-2025"
    version = "0.0.1"
    package_type = "application"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "fPIC": [True, False],
    }
    default_options = {
        "fPIC": True,
    }
    implements = ["auto_shared_fpic"]

    def build_requirements(self):
        self.tool_requires("cmake/[>=3.30]")

    def requirements(self):
        self.requires("data-driven_game_engine/0.0.1")
        self.requires("sfml/3.0.1")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        # CMakeDeps
        deps = CMakeDeps(self)
        deps.generate()

        # CMakeToolChain
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
