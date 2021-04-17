TEMPLATE = app
CONFIG += console
#CONFIG -= app_bundle

#since we want to use qDebug, we
#will not subtract qt.
#CONFIG -= qt

CONFIG += c++11
#------------------------------------------
##Add these lines for SFML:



#WINDOWS
# put SFML file in the same location as project
LIBS += -L"..\..\SFML-2.5.1\lib" #change this
LIBS += -L"..\..\SFML-2.5.1\bin" #change this

#MAC
#LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "..\..\SFML-2.5.1\include" #change this
DEPENDPATH  += "..\..\SFML-2.5.1\include" #change this

#MAC
#INCLUDEPATH += "/usr/local/include"
#DEPENDPATH += "/usr/local/include"

#-----------------------------------------

SOURCES += main.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Integer/integer.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Operator/operator.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Plot/plot.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/RPN/rpn.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Token/token.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Variable/variable.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/function/function.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/graph_info_copy/graph_info.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/left_op/left_op.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/right_op/right_op.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/shunting_yard/shunting_yard.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/tokenize/tokenize.cpp \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/transformation/transformation.cpp \
    system.cpp \
    random.cpp \
    sidebar.cpp \
    animate.cpp


HEADERS += \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Integer/integer.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Operator/operator.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Plot/plot.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Queue/queue_iterator_Copy.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/RPN/rpn.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Stack/stack_iterator_Copy.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Token/token.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Variable/variable.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/Vector/vector.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/function/function.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/graph_info_copy/graph_info.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/left_op/left_op.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/right_op/right_op.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/shunting_yard/shunting_yard.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/tokenize/tokenize.h \
    ../../../../../OneDrive/Desktop/CS3A/!inludes/transformation/transformation.h \
    constants.h \
    system.h \
    random.h \
    sidebar.h \
    animate.h
