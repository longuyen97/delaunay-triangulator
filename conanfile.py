from conans import ConanFile, CMake

class PocoTimerConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "catch2/2.11.3", "opencv/3.4.5@conan/stable"
    generators = "cmake"