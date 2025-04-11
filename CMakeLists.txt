cmake_minimum_required(VERSION 3.30)
project(TrabalhoAlexFacil C)

set(CMAKE_C_STANDARD 99)

# Encontra todos os .c do projeto
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

# Remove o main.c da lista (afim de compilar ele separadamente no executável)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

# Cria uma biblioteca com todos os .c auxiliares
add_library(TrabalhoAlexFacilLib STATIC ${SOURCES})

# Compila o main
add_executable(TrabalhoAlexFacil main.c)

# Linka o main com a biblioteca
target_link_libraries(TrabalhoAlexFacil PRIVATE TrabalhoAlexFacilLib)
