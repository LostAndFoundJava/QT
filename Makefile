#############################################################################
# Makefile for building: Bofeng
# Generated by qmake (2.01a) (Qt 4.8.1) on: Sat Apr 1 14:50:07 2017
# Project:  Bofeng.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile Bofeng.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtSql -I/usr/include/qt4 -I. -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lQtSql -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = can.cpp \
		cmysplashscreen.cpp \
		globl_data.cpp \
		log.cpp \
		main.cpp \
		mainwindow.cpp \
		management.cpp \
		systemset.cpp \
		config.cpp \
		keyboard.cpp \
		qmyedit.cpp \
		widget.cpp \
		subwidget.cpp \
		learn.cpp \
		varify.cpp \
		sqlite.cpp \
		juxingkuang.cpp \
		product.cpp \
		notice.cpp \
		dataset.cpp moc_cmysplashscreen.cpp \
		moc_log.cpp \
		moc_mainwindow.cpp \
		moc_management.cpp \
		moc_systemset.cpp \
		moc_keyboard.cpp \
		moc_qmyedit.cpp \
		moc_widget.cpp \
		moc_subwidget.cpp \
		moc_learn.cpp \
		moc_varify.cpp \
		moc_product.cpp \
		moc_notice.cpp \
		moc_dataset.cpp \
		qrc_Bofeng.cpp
OBJECTS       = can.o \
		cmysplashscreen.o \
		globl_data.o \
		log.o \
		main.o \
		mainwindow.o \
		management.o \
		systemset.o \
		config.o \
		keyboard.o \
		qmyedit.o \
		widget.o \
		subwidget.o \
		learn.o \
		varify.o \
		sqlite.o \
		juxingkuang.o \
		product.o \
		notice.o \
		dataset.o \
		moc_cmysplashscreen.o \
		moc_log.o \
		moc_mainwindow.o \
		moc_management.o \
		moc_systemset.o \
		moc_keyboard.o \
		moc_qmyedit.o \
		moc_widget.o \
		moc_subwidget.o \
		moc_learn.o \
		moc_varify.o \
		moc_product.o \
		moc_notice.o \
		moc_dataset.o \
		qrc_Bofeng.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Bofeng.pro
QMAKE_TARGET  = Bofeng
DESTDIR       = 
TARGET        = Bofeng

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_log.h ui_mainwindow.h ui_management.h ui_systemset.h ui_keyboard.h ui_widget.h ui_learn.h ui_varify.h ui_notice.h ui_dataset.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Bofeng.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtSql.prl \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile Bofeng.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtSql.prl:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile Bofeng.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Bofeng1.0.0 || $(MKDIR) .tmp/Bofeng1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Bofeng1.0.0/ && $(COPY_FILE) --parents can.h cmysplashscreen.h globl_data.h log.h mainwindow.h management.h systemset.h config.h keyboard.h qmyedit.h widget.h subwidget.h learn.h varify.h sqlite.h juxingkuang.h product.h notice.h dataset.h .tmp/Bofeng1.0.0/ && $(COPY_FILE) --parents Bofeng.qrc .tmp/Bofeng1.0.0/ && $(COPY_FILE) --parents can.cpp cmysplashscreen.cpp globl_data.cpp log.cpp main.cpp mainwindow.cpp management.cpp systemset.cpp config.cpp keyboard.cpp qmyedit.cpp widget.cpp subwidget.cpp learn.cpp varify.cpp sqlite.cpp juxingkuang.cpp product.cpp notice.cpp dataset.cpp .tmp/Bofeng1.0.0/ && $(COPY_FILE) --parents log.ui mainwindow.ui management.ui systemset.ui keyboard.ui widget.ui learn.ui varify.ui notice.ui dataset.ui .tmp/Bofeng1.0.0/ && (cd `dirname .tmp/Bofeng1.0.0` && $(TAR) Bofeng1.0.0.tar Bofeng1.0.0 && $(COMPRESS) Bofeng1.0.0.tar) && $(MOVE) `dirname .tmp/Bofeng1.0.0`/Bofeng1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Bofeng1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_cmysplashscreen.cpp moc_log.cpp moc_mainwindow.cpp moc_management.cpp moc_systemset.cpp moc_keyboard.cpp moc_qmyedit.cpp moc_widget.cpp moc_subwidget.cpp moc_learn.cpp moc_varify.cpp moc_product.cpp moc_notice.cpp moc_dataset.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_cmysplashscreen.cpp moc_log.cpp moc_mainwindow.cpp moc_management.cpp moc_systemset.cpp moc_keyboard.cpp moc_qmyedit.cpp moc_widget.cpp moc_subwidget.cpp moc_learn.cpp moc_varify.cpp moc_product.cpp moc_notice.cpp moc_dataset.cpp
moc_cmysplashscreen.cpp: cmysplashscreen.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) cmysplashscreen.h -o moc_cmysplashscreen.cpp

moc_log.cpp: log.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) log.h -o moc_log.cpp

moc_mainwindow.cpp: globl_data.h \
		log.h \
		management.h \
		qmyedit.h \
		config.h \
		keyboard.h \
		ui_keyboard.h \
		learn.h \
		varify.h \
		mainwindow.h \
		systemset.h \
		dataset.h \
		widget.h \
		sqlite.h \
		juxingkuang.h \
		product.h \
		notice.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_management.cpp: qmyedit.h \
		config.h \
		keyboard.h \
		ui_keyboard.h \
		globl_data.h \
		learn.h \
		varify.h \
		mainwindow.h \
		log.h \
		management.h \
		product.h \
		notice.h \
		systemset.h \
		dataset.h \
		widget.h \
		sqlite.h \
		juxingkuang.h \
		management.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) management.h -o moc_management.cpp

moc_systemset.cpp: qmyedit.h \
		config.h \
		keyboard.h \
		ui_keyboard.h \
		globl_data.h \
		dataset.h \
		systemset.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) systemset.h -o moc_systemset.cpp

moc_keyboard.cpp: ui_keyboard.h \
		keyboard.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) keyboard.h -o moc_keyboard.cpp

moc_qmyedit.cpp: qmyedit.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) qmyedit.h -o moc_qmyedit.cpp

moc_widget.cpp: sqlite.h \
		juxingkuang.h \
		product.h \
		widget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) widget.h -o moc_widget.cpp

moc_subwidget.cpp: subwidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) subwidget.h -o moc_subwidget.cpp

moc_learn.cpp: globl_data.h \
		varify.h \
		qmyedit.h \
		config.h \
		keyboard.h \
		ui_keyboard.h \
		mainwindow.h \
		log.h \
		management.h \
		learn.h \
		product.h \
		notice.h \
		systemset.h \
		dataset.h \
		widget.h \
		sqlite.h \
		juxingkuang.h \
		learn.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) learn.h -o moc_learn.cpp

moc_varify.cpp: qmyedit.h \
		config.h \
		keyboard.h \
		ui_keyboard.h \
		globl_data.h \
		mainwindow.h \
		log.h \
		management.h \
		learn.h \
		varify.h \
		product.h \
		notice.h \
		systemset.h \
		dataset.h \
		widget.h \
		sqlite.h \
		juxingkuang.h \
		varify.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) varify.h -o moc_varify.cpp

moc_product.cpp: product.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) product.h -o moc_product.cpp

moc_notice.cpp: notice.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) notice.h -o moc_notice.cpp

moc_dataset.cpp: dataset.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) dataset.h -o moc_dataset.cpp

compiler_rcc_make_all: qrc_Bofeng.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_Bofeng.cpp
qrc_Bofeng.cpp: Bofeng.qrc \
		image/circle_red.png \
		image/circle_green.png \
		image/slider.png \
		image/Keyboard.png \
		image/Bofeng.png
	/usr/bin/rcc -name Bofeng Bofeng.qrc -o qrc_Bofeng.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_log.h ui_mainwindow.h ui_management.h ui_systemset.h ui_keyboard.h ui_widget.h ui_learn.h ui_varify.h ui_notice.h ui_dataset.h
compiler_uic_clean:
	-$(DEL_FILE) ui_log.h ui_mainwindow.h ui_management.h ui_systemset.h ui_keyboard.h ui_widget.h ui_learn.h ui_varify.h ui_notice.h ui_dataset.h
ui_log.h: log.ui
	/usr/bin/uic-qt4 log.ui -o ui_log.h

ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_management.h: management.ui
	/usr/bin/uic-qt4 management.ui -o ui_management.h

ui_systemset.h: systemset.ui
	/usr/bin/uic-qt4 systemset.ui -o ui_systemset.h

ui_keyboard.h: keyboard.ui
	/usr/bin/uic-qt4 keyboard.ui -o ui_keyboard.h

ui_widget.h: widget.ui
	/usr/bin/uic-qt4 widget.ui -o ui_widget.h

ui_learn.h: learn.ui
	/usr/bin/uic-qt4 learn.ui -o ui_learn.h

ui_varify.h: varify.ui
	/usr/bin/uic-qt4 varify.ui -o ui_varify.h

ui_notice.h: notice.ui
	/usr/bin/uic-qt4 notice.ui -o ui_notice.h

ui_dataset.h: dataset.ui
	/usr/bin/uic-qt4 dataset.ui -o ui_dataset.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

can.o: can.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o can.o can.cpp

cmysplashscreen.o: cmysplashscreen.cpp cmysplashscreen.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cmysplashscreen.o cmysplashscreen.cpp

globl_data.o: globl_data.cpp globl_data.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o globl_data.o globl_data.cpp

log.o: log.cpp log.h \
		ui_log.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o log.o log.cpp

main.o: main.cpp cmysplashscreen.h \
		globl_data.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp ui_mainwindow.h \
		globl_data.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

management.o: management.cpp ui_management.h \
		globl_data.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o management.o management.cpp

systemset.o: systemset.cpp ui_systemset.h \
		globl_data.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o systemset.o systemset.cpp

config.o: config.cpp config.h \
		keyboard.h \
		ui_keyboard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o config.o config.cpp

keyboard.o: keyboard.cpp keyboard.h \
		ui_keyboard.h \
		config.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o keyboard.o keyboard.cpp

qmyedit.o: qmyedit.cpp qmyedit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qmyedit.o qmyedit.cpp

widget.o: widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o widget.o widget.cpp

subwidget.o: subwidget.cpp widget.h \
		sqlite.h \
		juxingkuang.h \
		product.h \
		ui_widget.h \
		subwidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o subwidget.o subwidget.cpp

learn.o: learn.cpp ui_learn.h \
		globl_data.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o learn.o learn.cpp

varify.o: varify.cpp ui_varify.h \
		globl_data.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o varify.o varify.cpp

sqlite.o: sqlite.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sqlite.o sqlite.cpp

juxingkuang.o: juxingkuang.cpp juxingkuang.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o juxingkuang.o juxingkuang.cpp

product.o: product.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o product.o product.cpp

notice.o: notice.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o notice.o notice.cpp

dataset.o: dataset.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dataset.o dataset.cpp

moc_cmysplashscreen.o: moc_cmysplashscreen.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_cmysplashscreen.o moc_cmysplashscreen.cpp

moc_log.o: moc_log.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_log.o moc_log.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_management.o: moc_management.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_management.o moc_management.cpp

moc_systemset.o: moc_systemset.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_systemset.o moc_systemset.cpp

moc_keyboard.o: moc_keyboard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_keyboard.o moc_keyboard.cpp

moc_qmyedit.o: moc_qmyedit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qmyedit.o moc_qmyedit.cpp

moc_widget.o: moc_widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_widget.o moc_widget.cpp

moc_subwidget.o: moc_subwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_subwidget.o moc_subwidget.cpp

moc_learn.o: moc_learn.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_learn.o moc_learn.cpp

moc_varify.o: moc_varify.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_varify.o moc_varify.cpp

moc_product.o: moc_product.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_product.o moc_product.cpp

moc_notice.o: moc_notice.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_notice.o moc_notice.cpp

moc_dataset.o: moc_dataset.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dataset.o moc_dataset.cpp

qrc_Bofeng.o: qrc_Bofeng.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_Bofeng.o qrc_Bofeng.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

