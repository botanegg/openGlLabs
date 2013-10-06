cmake_minimum_required (VERSION 2.6)

set(PROJECT_NAME testing)
project(${PROJECT_NAME})


set(COMPILE_FLAGS "-g -pedantic -Wall -Wextra -Wabi -Wcast-qual -Wconversion -Wfloat-equal -Winline -Wmissing-declarations -Wmissing-format-attribute -Wno-long-long -Woverloaded-virtual -Wpacked -Wredundant-decls -Wshadow -Wsign-promo -Weffc++")

set(CMAKE_C_FLAGS "${COMPILE_FLAGS}")
set(CMAKE_CPP_FLAGS "${COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS "${COMPILE_FLAGS}")


set(srcs
	main.cpp
	App.cpp
	Keyboard.cpp
	Mouse.cpp
	Camera.cpp
	IDrawtickable.cpp
	MyObject.cpp
	Texture.cpp
)

add_executable(${PROJECT_NAME} ${srcs})

#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)
#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)


target_link_libraries(${PROJECT_NAME}
	${OPENGL_LIBRARIES}
	${GLUT_LIBRARY}
)
