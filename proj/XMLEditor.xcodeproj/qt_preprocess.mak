#############################################################################
# Makefile for building: XMLEditor.app/Contents/MacOS/XMLEditor
# Generated by qmake (3.0) (Qt 5.3.2)
# Project:  XMLEditor.pro
# Template: app
# Command: /Users/westjour/Qt5.3.2/5.3/clang_64/bin/qmake -spec macx-xcode -o XMLEditor.xcodeproj/project.pbxproj XMLEditor.pro
#############################################################################

MAKEFILE      = project.pbxproj

MOC       = /Users/westjour/Qt5.3.2/5.3/clang_64/bin/moc
UIC       = /Users/westjour/Qt5.3.2/5.3/clang_64/bin/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB
INCPATH       = -I../../../Qt5.3.2/5.3/clang_64/mkspecs/macx-clang -I. -I../../../Qt5.3.2/5.3/clang_64/lib/QtWidgets.framework/Versions/5/Headers -I../../../Qt5.3.2/5.3/clang_64/lib/QtXml.framework/Versions/5/Headers -I../../../Qt5.3.2/5.3/clang_64/lib/QtGui.framework/Versions/5/Headers -I../../../Qt5.3.2/5.3/clang_64/lib/QtCore.framework/Versions/5/Headers -I. -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/System/Library/Frameworks/AGL.framework/Headers -I. -F/Users/westjour/Qt5.3.2/5.3/clang_64/lib
DEL_FILE  = rm -f
MOVE      = mv -f

IMAGES = 
PARSERS =
preprocess: $(PARSERS) compilers
clean preprocess_clean: parser_clean compiler_clean

parser_clean:
mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compilers: moc_CDailyWeatherModel.cpp moc_CLaunchWindow.cpp moc_CWindowSDB.cpp\
	 moc_CWindowWDB.cpp moc_CSoilLayerModel.cpp ui_launch.h ui_wdb.h ui_sdb.h
compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all: moc_CDailyWeatherModel.cpp moc_CLaunchWindow.cpp moc_CWindowSDB.cpp moc_CWindowWDB.cpp moc_CSoilLayerModel.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_CDailyWeatherModel.cpp moc_CLaunchWindow.cpp moc_CWindowSDB.cpp moc_CWindowWDB.cpp moc_CSoilLayerModel.cpp
moc_CDailyWeatherModel.cpp: ../../../Qt5.3.2/5.3/clang_64/lib/QtCore.framework/Versions/5/Headers/QAbstractTableModel \
		CDailyWeatherModel.h
	/Users/westjour/Qt5.3.2/5.3/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/westjour/Qt5.3.2/5.3/clang_64/mkspecs/macx-clang -I/Users/westjour/Desktop/GUI_Repo/proj -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtWidgets.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtXml.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtGui.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtCore.framework/Headers -F/Users/westjour/Qt5.3.2/5.3/clang_64/lib CDailyWeatherModel.h -o moc_CDailyWeatherModel.cpp

moc_CLaunchWindow.cpp: ../../../Qt5.3.2/5.3/clang_64/lib/QtWidgets.framework/Versions/5/Headers/QWidget \
		CLaunchWindow.h
	/Users/westjour/Qt5.3.2/5.3/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/westjour/Qt5.3.2/5.3/clang_64/mkspecs/macx-clang -I/Users/westjour/Desktop/GUI_Repo/proj -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtWidgets.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtXml.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtGui.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtCore.framework/Headers -F/Users/westjour/Qt5.3.2/5.3/clang_64/lib CLaunchWindow.h -o moc_CLaunchWindow.cpp

moc_CWindowSDB.cpp: ../../../Qt5.3.2/5.3/clang_64/lib/QtWidgets.framework/Versions/5/Headers/QMainWindow \
		CWindowSDB.h
	/Users/westjour/Qt5.3.2/5.3/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/westjour/Qt5.3.2/5.3/clang_64/mkspecs/macx-clang -I/Users/westjour/Desktop/GUI_Repo/proj -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtWidgets.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtXml.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtGui.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtCore.framework/Headers -F/Users/westjour/Qt5.3.2/5.3/clang_64/lib CWindowSDB.h -o moc_CWindowSDB.cpp

moc_CWindowWDB.cpp: ../../../Qt5.3.2/5.3/clang_64/lib/QtWidgets.framework/Versions/5/Headers/QMainWindow \
		../../../Qt5.3.2/5.3/clang_64/lib/QtXml.framework/Versions/5/Headers/QDomNamedNodeMap \
		CWindowWDB.h
	/Users/westjour/Qt5.3.2/5.3/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/westjour/Qt5.3.2/5.3/clang_64/mkspecs/macx-clang -I/Users/westjour/Desktop/GUI_Repo/proj -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtWidgets.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtXml.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtGui.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtCore.framework/Headers -F/Users/westjour/Qt5.3.2/5.3/clang_64/lib CWindowWDB.h -o moc_CWindowWDB.cpp

moc_CSoilLayerModel.cpp: ../../../Qt5.3.2/5.3/clang_64/lib/QtCore.framework/Versions/5/Headers/QAbstractTableModel \
		CSoilLayerModel.h
	/Users/westjour/Qt5.3.2/5.3/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/westjour/Qt5.3.2/5.3/clang_64/mkspecs/macx-clang -I/Users/westjour/Desktop/GUI_Repo/proj -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtWidgets.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtXml.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtGui.framework/Headers -I/Users/westjour/Qt5.3.2/5.3/clang_64/lib/QtCore.framework/Headers -F/Users/westjour/Qt5.3.2/5.3/clang_64/lib CSoilLayerModel.h -o moc_CSoilLayerModel.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_launch.h ui_wdb.h ui_sdb.h
compiler_uic_clean:
	-$(DEL_FILE) ui_launch.h ui_wdb.h ui_sdb.h
ui_launch.h: ui/launch.ui
	/Users/westjour/Qt5.3.2/5.3/clang_64/bin/uic ui/launch.ui -o ui_launch.h

ui_wdb.h: ui/wdb.ui
	/Users/westjour/Qt5.3.2/5.3/clang_64/bin/uic ui/wdb.ui -o ui_wdb.h

ui_sdb.h: ui/sdb.ui
	/Users/westjour/Qt5.3.2/5.3/clang_64/bin/uic ui/sdb.ui -o ui_sdb.h

compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

