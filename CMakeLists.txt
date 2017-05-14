cmake_minimum_required (VERSION 2.6)
project (game)

find_package(OpenGL REQUIRED)

add_subdirectory (external)

include_directories(
        external/glfw-3.1.2/include/GLFW/
        external/glm-0.9.7.1/
        external/glew-1.13.0/include/
        external/freetype-2.3.5/include/
        .
)


set(GLAD "external/glfw-3.1.2/deps/glad/glad.h"
        "external/glfw-3.1.2/deps/glad.c")

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
        )

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

set(CMAKE_CXX_STANDARD 11)

add_executable(game
        code/battlePhaseControl.h
        code/creature.cpp
        code/creature.h
        code/creature_defines.h
        code/enemy.cpp
        code/enemy.h
        code/eventControl.cpp
        code/eventControl.h
        code/eventFlags.cpp
        code/eventFlags.h
        code/field.cpp
        code/field.h
        code/globalPhaseControl.cpp
        code/globalPhaseControl.h
        #code/main.cpp # for console prject
        code/map.cpp
        code/map.h
        code/map_defines.h
        code/perks.cpp
        code/perks.h
        code/player.cpp
        code/player.h
        code/skills.h
        code/stats.cpp
        code/stats.h
        engine/GameWindow.cpp
        engine/GameWindow.h
        engine/GLButton.cpp
        engine/GLButton.h
        engine/GLField.cpp
        engine/GLField.h
        engine/GLFrame.cpp
        engine/GLFrame.h
        engine/GLObject.cpp
        engine/GLObject.h
        engine/GLWindow.cpp
        engine/GLWindow.h
        engine/main.cpp
        engine/SettingsManager.cpp
        engine/SettingsManager.h
        engine/Utility.cpp
        engine/Utility.h
        engine/Constants.h
        common/shader.hpp
        common/shader.cpp
        common/texture.cpp
        common/texture.hpp
        code/skills.cpp)

target_link_libraries(game
        ${ALL_LIBS})

file ( COPY
        resources/ButtonFragmentShader.fragmentshader
        resources/ButtonVertexShader.vertexshader
        resources/FrameFragmentShader.fragmentshader
        resources/FrameVertexShader.vertexshader
        resources/backA.bmp
        resources/background.bmp
        resources/backS.bmp
        resources/continueA.bmp
        resources/continueS.bmp
        resources/exitA.bmp
        resources/exitS.bmp
        resources/newGameA.bmp
        resources/newGameS.bmp
        resources/newGameP.bmp
        resources/settingsA.bmp
        resources/settingsS.bmp
        resources/parametres.config
        DESTINATION
        ${PROJECT_BINARY_DIR}/bin)
