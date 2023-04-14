cmake_minimum_required(VERSION 3.23)
project(2023DataStructuresApplications)

set(CMAKE_CXX_STANDARD 14)

add_executable(2023DataStructuresApplications main.cpp GUI_Component/EventHandler.cpp GUI_Component/EventHandler.h Helpers/Font.cpp Helpers/Font.h TextInput/Typing.cpp TextInput/Typing.h TextInput/MultiText.cpp TextInput/MultiText.h Helpers/States.cpp Helpers/States.h Helpers/statesEnum.h TextInput/Letter.cpp TextInput/Letter.h TextInput/TextInput.cpp TextInput/TextInput.h GUI_Component/Snapshot.cpp GUI_Component/Snapshot.h GUI_Component/SnapshotInterface.h GUI_Component/GUI_Component.cpp GUI_Component/GUI_Component.h Helpers/KeyBoardShortCuts.cpp Helpers/KeyBoardShortCuts.h Helpers/MouseEvents.cpp Helpers/MouseEvents.h GUI_Component/History.cpp GUI_Component/History.h GUI_Component/HistoryNode.h TextInput/Cursor.cpp TextInput/Cursor.h TextInput/InputBox.cpp TextInput/InputBox.h WordSort/Word.cpp WordSort/Word.h WordSort/FileReader.cpp WordSort/FileReader.h WordSort/WordSort.cpp WordSort/WordSort.h DropDownMenu/Item.cpp DropDownMenu/Item.h Helpers/Position.cpp Helpers/Position.h DropDownMenu/ItemList.cpp DropDownMenu/ItemList.h DropDownMenu/DDM_InputBox.cpp DropDownMenu/DDM_InputBox.h DropDownMenu/DropDownMenu.cpp DropDownMenu/DropDownMenu.h GUI_Component/TextInputSnapshot.cpp GUI_Component/TextInputSnapshot.h MenuBar/Menu.cpp MenuBar/Menu.h MenuBar/MenuBar.cpp MenuBar/MenuBar.h FileTree/FileItem.cpp FileTree/FileItem.h Helpers/Texture.cpp Helpers/Texture.h FileTree/FileNode.cpp FileTree/FileNode.h FileTree/FileTree.cpp FileTree/FileTree.h)
target_link_libraries(2023DataStructuresApplications sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
