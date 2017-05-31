cmake_minimum_required (VERSION 2.6)
project (game)

find_package(OpenGL REQUIRED)

add_subdirectory (external)

include_directories(
        external/glfw-3.1.2/include/GLFW/
        external/glm-0.9.7.1/
        external/glew-1.13.0/include/
        external/freetype/include/
        .
)



set(GLAD "external/glfw-3.1.2/deps/glad/glad.h"
        "external/glfw-3.1.2/deps/glad.c")

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
        freetype
        )

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

#find_package(Freetype REQUIRED)
include_directories(${FREETYPE_INCLUDE_DIRS})


set(CMAKE_CXX_STANDARD 11)
SET(GCC_COVERAGE_LINK_FLAGS    "-static -static-libgcc -static-libstdc++")
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

add_executable(game
        code/BattlePhaseControl.h
        code/Creature.cpp
        code/Creature.h
        code/CreatureDefines.h
        code/Enemy.cpp
        code/Enemy.h
        code/EventControl.cpp
        code/EventControl.h
        code/EventFlags.cpp
        code/EventFlags.h
        code/Field.cpp
        code/Field.h
        code/globalPhaseControl.cpp
        code/globalPhaseControl.h
        code/Map.cpp
        code/Map.h
        code/MapDefines.h
        code/Perks.cpp
        code/Perks.h
        code/Player.cpp
        code/Player.h
        code/Skills.h
        code/Stats.cpp
        code/Stats.h
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
        code/Skills.cpp
        code/BattlePhaseControl.cpp
        engine/ResourceFactory.cpp
        engine/ResourceFactory.h
        engine/GLPanel.cpp
        engine/GLPanel.h
        engine/GLText.cpp
        engine/GLText.h
        engine/Shader.cpp
        engine/Shader.h
        engine/IGLObject.h
        )

target_link_libraries(game
        ${ALL_LIBS})

target_link_libraries(game ${FREETYPE_LIBRARIES})

file ( COPY
        resources/ButtonFragmentShader.fragmentshader
        resources/ButtonVertexShader.vertexshader
        resources/FrameFragmentShader.fragmentshader
        resources/FrameVertexShader.vertexshader
        resources/backA.bmp
        resources/background.bmp
        resources/blackBackground.bmp
        resources/backS.bmp
        resources/continueA.bmp
        resources/continueS.bmp
        resources/continueP.bmp
        resources/exitA.bmp
        resources/exitS.bmp
        resources/exitP.bmp
        resources/newGameA.bmp
        resources/newGameS.bmp
        resources/newGameP.bmp
        resources/settingsA.bmp
        resources/settingsS.bmp
        resources/settingsP.bmp
        resources/wall.bmp
        resources/tunel.bmp
        resources/parametres.config
        DESTINATION
        ${PROJECT_BINARY_DIR}/bin)


option(test "Build all tests." OFF) # Makes boolean 'test' available.

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.

set(CMAKE_CXX_FLAGS "-g -Wall")

# force static runtime libraries for msvc builds
if(MSVC)
    set(variables
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_RELWITHDEBINFO
            CMAKE_CXX_FLAGS_MINSIZEREL
            )
    foreach(variable ${variables})
        if(${variable} MATCHES "/MD")
            string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
        endif()
    endforeach()
endif()

# If you want your own include/ directory, set this, and then you can do
# include_directories(${COMMON_INCLUDES}) in other CMakeLists.txt files.
# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

################################
# Normal Libraries & Executables
################################
# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere.

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

# This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(lib/gtest-1.6.0)

enable_testing()

# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

##############
# Unit Tests
##############
add_executable(runUnitTests
        PPTests.cpp)

# Standard linking to gtest stuff.
target_link_libraries(runUnitTests gtest gtest_main)

# Extra linking for the project.

target_link_libraries(runUnitTests
        ${ALL_LIBS})

target_link_libraries(runUnitTests ${FREETYPE_LIBRARIES})

set (GAME_FILES
        code/BattlePhaseControl.h
        code/Creature.cpp
        code/Creature.h
        code/CreatureDefines.h
        code/Enemy.cpp
        code/Enemy.h
        code/EventControl.cpp
        code/EventControl.h
        code/EventFlags.cpp
        code/EventFlags.h
        code/Field.cpp
        code/Field.h
        code/globalPhaseControl.cpp
        code/globalPhaseControl.h
        code/Map.cpp
        code/Map.h
        code/MapDefines.h
        code/Perks.cpp
        code/Perks.h
        code/Player.cpp
        code/Player.h
        code/Skills.h
        code/Stats.cpp
        code/Stats.h
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
        engine/SettingsManager.cpp
        engine/SettingsManager.h
        engine/Utility.cpp
        engine/Utility.h
        engine/Constants.h
        common/shader.hpp
        common/shader.cpp
        common/texture.cpp
        common/texture.hpp
        code/Skills.cpp
        code/BattlePhaseControl.cpp
        engine/ResourceFactory.cpp
        engine/ResourceFactory.h
        engine/GLPanel.cpp
        engine/GLPanel.h
        engine/GLText.cpp
        engine/GLText.h
        engine/Shader.cpp
        engine/Shader.h
        engine/IGLObject.h)

add_library(game_lib ${GAME_FILES})

target_link_libraries(game_lib ${ALL_LIBS})
target_link_libraries(game_lib ${FREETYPE_LIBRARIES})

target_link_libraries(runUnitTests game_lib)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(NAME that-test-I-made COMMAND runUnitTests)

# You can also omit NAME and COMMAND. The second argument could be some other
# test executable.
add_test(that-other-test-I-made runUnitTests)

add_executable(generalUnitTest GeneralTests.cpp)

# Standard linking to gtest stuff.
target_link_libraries(generalUnitTest gtest gtest_main)

# Extra linking for the project.

target_link_libraries(generalUnitTest
        ${ALL_LIBS})

target_link_libraries(generalUnitTest ${FREETYPE_LIBRARIES})

target_link_libraries(generalUnitTest game_lib)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(NAME general-test COMMAND generalUnitTest)
