cmake_minimum_required (VERSION 2.6)
project (SoulRift)

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

# Tutorial 1
add_executable(SoulRift
		SoulRift/main.cpp
		SoulRift/GameWindow.h
		SoulRift/GameWindow.cpp
		SoulRift/GLFrame.h
		SoulRift/GLFrame.cpp
		SoulRift/GLObject.h
		SoulRift/GLObject.cpp
		SoulRift/GLWindow.h
		SoulRift/GLWindow.cpp
		SoulRift/GLButton.h
		SoulRift/GLButton.cpp



	    common/shader.hpp
	    common/shader.cpp
	    common/texture.cpp
	    common/texture.hpp
        SoulRift/Constants.h)
target_link_libraries(SoulRift
	${ALL_LIBS}
)

file ( COPY
        SoulRift/ButtonFragmentShader.fragmentshader
        SoulRift/ButtonVertexShader.vertexshader
        SoulRift/FrameFragmentShader.fragmentshader
        SoulRift/FrameVertexShader.vertexshader
        SoulRift/backA.bmp
        SoulRift/background.bmp
        SoulRift/backS.bmp
        SoulRift/continueA.bmp
        SoulRift/continueS.bmp
        SoulRift/exitA.bmp
        SoulRift/exitS.bmp
        SoulRift/newGameA.bmp
        SoulRift/newGameS.bmp
        SoulRift/SettingsA.bmp
        SoulRift/settingsS.bmp
        DESTINATION
        ${PROJECT_BINARY_DIR}/bin)