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
		SoulRift/engine/main.cpp
		SoulRift/engine/GameWindow.h
		SoulRift/engine/GameWindow.cpp
		SoulRift/engine/GLFrame.h
		SoulRift/engine/GLFrame.cpp
		SoulRift/engine/GLObject.h
		SoulRift/engine/GLObject.cpp
		SoulRift/engine/GLWindow.h
		SoulRift/engine/GLWindow.cpp
		SoulRift/engine/GLButton.h
		SoulRift/engine/GLButton.cpp



	    common/shader.hpp
	    common/shader.cpp
	    common/texture.cpp
	    common/texture.hpp
		SoulRift/engine/Constants.h SoulRift/engine/SettingsManager.cpp SoulRift/engine/SettingsManager.h SoulRift/engine/Utility.cpp SoulRift/engine/Utility.h)
target_link_libraries(SoulRift
	${ALL_LIBS}
)

file ( COPY
		SoulRift/engine/ButtonFragmentShader.fragmentshader
		SoulRift/engine/ButtonVertexShader.vertexshader
		SoulRift/engine/FrameFragmentShader.fragmentshader
		SoulRift/engine/FrameVertexShader.vertexshader
		SoulRift/engine/backA.bmp
		SoulRift/engine/background.bmp
		SoulRift/engine/backS.bmp
		SoulRift/engine/continueA.bmp
		SoulRift/engine/continueS.bmp
		SoulRift/engine/exitA.bmp
		SoulRift/engine/exitS.bmp
		SoulRift/engine/newGameA.bmp
		SoulRift/engine/newGameS.bmp
		SoulRift/engine/newGameP.bmp
		SoulRift/engine/settingsA.bmp
		SoulRift/engine/settingsS.bmp
        DESTINATION
        ${PROJECT_BINARY_DIR}/bin)