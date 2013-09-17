cmake_minimum_required (VERSION 2.6)

set(PROJECT_NAME OGLab)
project(${PROJECT_NAME})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -Wall -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

find_library(GLUT_LIB glut)
find_library(GL_LIB GL)
find_library(GLU_LIB GLU)

set(srcs
	main.cpp
	App.cpp
	Keyboard.cpp
	Mouse.cpp
	Camera.cpp
)

add_executable(${PROJECT_NAME} ${srcs})

target_link_libraries(${PROJECT_NAME}
	${GLUT_LIB}
	${GL_LIB}
	${GLU_LIB}
)

