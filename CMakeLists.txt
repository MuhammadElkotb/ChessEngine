cmake_minimum_required(VERSION 3.23)
project(ChessEngine)
set(SOURCES
src/App.cpp
src/Board.cpp
src/Piece.cpp
src/TextureLoader.cpp
)
set(HEADERS
headers/Board.hpp
headers/Piece.hpp
headers/Cell.hpp
headers/TextureLoader.hpp
)

add_executable(ChessEngine ${SOURCES})

set_property(TARGET ChessEngine PROPERTY CXX_STANDARD 20)


target_link_libraries(ChessEngine 
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/ogg.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/openal32.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/sfml-audio-d.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/sfml-graphics-d.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/sfml-main-d.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/sfml-network-d.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/sfml-system-d.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/sfml-window-d.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/vorbis.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/vorbisenc.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/vorbisfile.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/flac.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/freetype.lib"
)

target_include_directories(ChessEngine PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/SFML/include"
)