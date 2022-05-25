cmake_minimum_required(VERSION 3.23)
project(ChessEngine)
set(SOURCES
src/App.cpp
src/Board.cpp
src/Piece.cpp
)
set(HEADERS
headers/Board.hpp
headers/Piece.hpp
)

add_executable(ChessEngine ${SOURCES})

target_link_libraries(ChessEngine 
"M:/Prject/Cpp/ChessEngine/SFML/lib/ogg.lib"
"M:/Prject/Cpp/ChessEngine/SFML/lib/openal32.lib"
"M:/Prject/Cpp/ChessEngine/SFML/lib/sfml-audio-d.lib"
"M:/Prject/Cpp/ChessEngine/SFML/lib/sfml-graphics-d.lib"
"M:/Prject/Cpp/ChessEngine/SFML/lib/sfml-main-d.lib"
"M:/Prject/Cpp/ChessEngine/SFML/lib/sfml-network-d.lib"
"M:/Prject/Cpp/ChessEngine/SFML/lib/sfml-system-d.lib"
"M:/Prject/Cpp/ChessEngine/SFML/lib/sfml-window-d.lib"
"M:/Prject/Cpp/ChessEngine/SFML/lib/vorbis.lib"
"M:/Prject/Cpp/ChessEngine/SFML/lib/vorbisenc.lib"
"M:/Prject/Cpp/ChessEngine/SFML/lib/vorbisfile.lib"
"M:/Prject/Cpp/ChessEngine/SFML/lib/flac.lib"
"M:/Prject/Cpp/ChessEngine/SFML/lib/freetype.lib"
)

target_include_directories(ChessEngine PUBLIC 
"M:/Prject/Cpp/ChessEngine/SFML/include"
)
