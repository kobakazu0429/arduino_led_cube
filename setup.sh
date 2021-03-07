DIR=$(cd $(dirname $0) && pwd)

echo $DIR

echo "Create Lib Symbolic Links"
echo "==========================================="

ln -s $DIR/lib/LedCubeController/LedCubeController.h                      $DIR/LedCubeController.h
ln -s $DIR/lib/LedCubeController/LedCubeController.cpp                    $DIR/LedCubeController.cpp

ln -s $DIR/src/MyCubeController/MyCubeController.h                      $DIR/MyCubeController.h
ln -s $DIR/src/MyCubeController/MyCubeController.cpp                    $DIR/MyCubeController.cpp


echo "Create Lib Symbolic Links : done"
echo "==========================================="
