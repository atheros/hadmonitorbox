#!/bin/sh

DST_DIR=`pwd`
SRC_DIR=`dirname $0`
echo SRC=$SRC_DIR
echo DST=$DST_DIR

if [ -L $DST_DIR/app ]; then
	#echo "Removing old dir"
	rm -f $DST_DIR/app
fi

ln -s $SRC_DIR/src $DST_DIR/app


ORG_MK=$DST_DIR/build.mk.org
BUILD_MK=$DST_DIR/build.mk

if [ -f $ORG_MK ]; then
	rm -f $BUILD_MK
	cp $ORG_MK $BUILD_MK
else
	cp $BUILD_MK $ORG_MK
	cp $DST_DIR/application.cpp $DST_DIR/application.cpp.org
	touch $DST_DIR/application.cpp
fi

cd $SRC_DIR
FILES=`find -name '*.cpp' | grep -P '^./src/' | sed s,^./,,`
cd $DST_DIR

for f in $FILES; do
	echo $f
	echo "CPPSRC += \$(TARGET_SRC_PATH)/`echo $f | sed s,^src/,app/,`" >> $BUILD_MK
done



